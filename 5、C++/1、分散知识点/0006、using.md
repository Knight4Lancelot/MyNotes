using的主要作用有三个。

# 1、用于使用命名空间

经典举例：`using namespace std;`

# 2、在子类中引用父类资源

```C++
class CBase {
public:
    int GetBaseId()
    {
        return _baseId;
    }

protected:
    int _baseId = 100;
};

class CNode: private CBase {
private:
    int _age = 20;
    std::string _name = "default";

public:
    using CBase::GetBaseId;
    using CBase::_baseId;

    void GetInfo()
    {
        std::cout << "age = " << _age << std::endl
            << "name = " << _name << std::endl
            << "baseId = " << _baseId << std::endl;
    }
};
```

在使用`private`继承时，父类的`_baseId`和`GetBaseId()`对外界为`private`类型，无法被直接调用，这个时候就需要在子类的`public`中使用`using`来引用父类资源，将其改为`public`类型。

# 3、类型别名指定

## 3-1、基本类型别名指定

```C++
using FileType = enum {
    OPENED,
    CLOSED
};

int main()
{
    cout << FileType.OPENED << endl;
}
```

## 3-2、函数指针别名

先看一个稍微简单点的例子。

```C++
int GetLength(std::string str)
{
    return str.length();
}

using getLength = int (*) (std::string);

int main()
{
    getLength ptr = GetLength;
    int res = (*ptr)("1234567890");
    std::cout << res << std::endl;
}
```

然后在有类的定义情况下稍微复杂些的例子。

```C++
class Foo {
public:
    std::string bar(const std::string& str)
	{
        cout << str.length() << endl;
        return str + " with solution";
    }
};

// 下面这行代码等价于 typedef std::string (Foo::*fooMemFnPtr) (const std::string&);
using fooMemFnPtr = std::string (Foo::*) (const std::string&);

int main()
{
    Foo obj;
    fooMemFnPtr ptr = &Foo::bar;
    std::string result = (obj.*ptr)("Hello, World!");
    std::cout << "res = " << result << std::endl;
}
```