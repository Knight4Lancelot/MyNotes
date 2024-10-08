# 1、案例说明
定义了一个结构体`Student`，里面设置了对应的构造函数和析构函数

```C++
struct Student {
    char* name_;
    int age_;

    Student(std::string name)
    {
        name_ = (char*)malloc(name.size() * sizeof(char));
    }

    ~Student()
    {
        if (name_ != nullptr && name_ != NULL) {
            free(name_);
            name_ = nullptr;
        }
    }
};
```

然后定义了一个这样的函数，用于释放掉传入参数指针(类型未定)指向的用户申请空间

```C++
bool releaseSpace(void* ptr)
{
    if (ptr != nullptr && ptr != NULL) {
        delete ptr;
        ptr = nullptr;
    }
}
```

在某个函数中调用了这个方法

```C++
void func()
{
    Student* newStu = new Student();
    /** ... */
    bool status = releaseSpace(newStu);
}
```

这个`new`/`delete`过程看似没有问题，非常合理，但是实际上，使用`delete`去释放一个`void*`指针指向的空间时，会出现问题：**<span style="color:pink">用`delete`去释放`void*`指针不会调用对应的析构函数！</span>**

# 2、正确做法
在尝试`delete`释放一个`void*`指针之前，最好先将这个指针还原成其应有的类型

比如上面的`releaseSpace`函数，其释放的方式应该为

```C++
bool releaseSpace(void* ptr)
{
    if (ptr != nullptr && ptr != NULL) {
        delete static_cast<Student>(ptr);
        ptr = nullptr;
    }
}
```

利用`static_cast`将其强行转为原有类型，可以避免这个问题

当原有类型不单一，无法确认时，可以结合`模板类`来实现
