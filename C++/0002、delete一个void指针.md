# 1������˵��
������һ���ṹ��`Student`�����������˶�Ӧ�Ĺ��캯������������

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

Ȼ������һ�������ĺ����������ͷŵ��������ָ��(����δ��)ָ����û�����ռ�

```C++
bool releaseSpace(void* ptr)
{
    if (ptr != nullptr && ptr != NULL) {
        delete ptr;
        ptr = nullptr;
    }
}
```

��ĳ�������е������������

```C++
void func()
{
    Student* newStu = new Student();
    /** ... */
    bool status = releaseSpace(newStu);
}
```

���`new`/`delete`���̿���û�����⣬�ǳ���������ʵ���ϣ�ʹ��`delete`ȥ�ͷ�һ��`void*`ָ��ָ��Ŀռ�ʱ����������⣺**<span style="color:pink">��`delete`ȥ�ͷ�`void*`ָ�벻����ö�Ӧ������������</span>**

# 2����ȷ����
�ڳ���`delete`�ͷ�һ��`void*`ָ��֮ǰ������Ƚ����ָ�뻹ԭ����Ӧ�е�����

���������`releaseSpace`���������ͷŵķ�ʽӦ��Ϊ

```C++
bool releaseSpace(void* ptr)
{
    if (ptr != nullptr && ptr != NULL) {
        delete static_cast<Student>(ptr);
        ptr = nullptr;
    }
}
```

����`static_cast`����ǿ��תΪԭ�����ͣ����Ա����������

��ԭ�����Ͳ���һ���޷�ȷ��ʱ�����Խ��`ģ����`��ʵ��
