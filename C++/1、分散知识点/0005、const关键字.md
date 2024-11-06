# 1、const修饰变量

## （1）const修饰一般变量与数组

```C++
// 修饰一般变量
int const a = 100;
const int b = 100; // 写法与上一行等价

// 修饰数组
int const arr1[] = { 1, 2, 3 };
const int arr2[] = { 1, 2, 3 }; // 写法与上一行等价
```

## （2）const修饰指针

### 2.1、常量指针

```C++
const int* p = &num;
```

常量指针<span style="color:red">不可以通过修改所指向的变量的值</span>，但是<span style="color:red">指针可以指向别的变量</span>。

### 2.2、指针常量

```C++
int* const p = &num;
```

指针常量的<span style="color:red">值不可以修改，即不能指向别的变量</span>，但是<span style="color:red">可以通过指针修改它所指向的变量的值</span>。

### 2.3、前面两种的结合

```C++
const int * const p = &num;
```

这种就是前面两种的结合，<span style="color:red">指针不能指向别的变量，指针所指向的变量值不能被改变</span>。

# 2、const修饰函数

`const`修饰函数存在三种情况：

# 2-1、const修饰函数参数

```C++
void Func(const char* name)
{
    // ...
}
```

在这种情况下，对于传入的参数是不允许进行修改的，起到了很好的保护作用，对于`指针类型`和`引用类型`都适用。

# 2-2、const修饰函数返回值

**（1）值传递**

```C++
const int func()
{
    // ...
}
```

如果是值传递，没有必要将返回值用`const`修饰。

**（2）返回值为指针**

在这种情况下，接受返回值的参数也必须是`const`修饰的不可改变类型变量。

```C++
const char* func()
{
    // ...
}

int main()
{
    char* res1 = func(); // 报错
    const char* res2 = func(); // 正确
}
```

**（3）const修饰成员函数**

在C++的类中，如果用const修饰了一个成员函数，那么这个成员函数中不允许对类持有的变量做出修改。<span style="color:red">仅对类中的函数生效，普通函数后面加上const修饰无意义。</span>

```C++
class Test {
private:
    int _age;
public:
    Test()
    {
        _age = 20;
    }

    func1()
    {
        _age = 101;
    }

    func2() const
    {
        _age = 202;
    }
};
```

在上面的示例中，`func1()`正确，`func2()`错误，因为`func2()`有`const`修饰，不允许修改成员变量，但是修改了成员变量`_age`，编译会报错。

**规则总结：**

1、`const`对象只能访问`const`成员函数，非`const`的对象可以访问任何成员函数，包括`const`成员函数。<br>
2、如果函数名、参数、返回值都相同的`const`成员函数和`非const`成员函数是可以构成重载，那么`const`对象调用`const`成员函数，`非const`对象默认调用非`const`的成员函数。<br>
3、const成员函数可以访问所有成员变量，但是只能访问`const`的成员函数。<br>
4、非const成员函数，可以访问任何成员，包括`const`成员成员函数。<br>
5、const成员函数不能修改任何的成员变量，除非变量用`mutable`修饰。<br>

# 3、const修饰类的成员变量

C++11仅不允许在类声明中初始化`static非const`类型的数据成员。

```C++
class Test {
public:
    static const int a = 3; // Ok in C++11
    static int b = 4;       // Error
    const int c = 5;        // Ok in C++11
    int d = 6;              // Ok in C++11
public:
    CTest11(): c(0) {}     // Ok in C++11
};
```

**规则总结**

1、对于`static const`类型的成员变量不管是旧的C++标准还是C++11都是支持在定义时初始化的。<br>
2、对于`static非const`类型的成员变量C++03和C++11的标准都是不支持在定义时初始化的。<br>
3、对于`const非static`类型的成员变量C++03要求必须在构造函数的初始化列表中来初始化，而C++11的标准支持这种写法，同时允许在定义时进行初始化操作。<br>
4、对于`非static非const`成员变量，C++03标准不允许在成员变量定义时初始化，但是C++11标准允许在类的定义时对这些非静态变量进行初始化。<br>
5、对于`static非const`成员变量的初始化方式并未改变，就是在相应的cpp文件中写成`int Test::b = 5`即可，注意要在类定义之后。<br>

# 4、使用const的好处

**1、保护不可修改的变量**<br>
避免了无意间修改数据带来的安全风险。<br>
**2、便于进行类型检查**<br>
定义常量时，宏没有数据类型，但是const修饰的变量有，编译器可以对后者进行安全检查。<br>
**3、为函数重载提供了一个参考**<br>
const修饰的函数可以看作是对同名函数的重载。<br>
**4、节省空间，避免不必要的内存分配**<br>
const定义常量从汇编的角度来看，只是给出了对应的内存地址，而不是象宏一样给出的是立即数，所以，const定义的常量在程序运行过程中只有一份拷贝，而宏定义的常量在内存中有若干个拷贝。<br>
**5、提高了效率**<br>
编译器通常不为普通const常量分配存储空间，而是将它们保存在符号表中，这使得它成为一个编译期的常量，没有了存储与读内存的操作，使得它的效率也很高。<br>