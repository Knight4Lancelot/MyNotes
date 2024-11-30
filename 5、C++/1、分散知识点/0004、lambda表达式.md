lambda表达式，即虚函数。

# 1、用法1

```C++
void CallFunc(void (*callback)(int id, std::string name))
{
    callback(10, "Jack");
}

int main()
{
    auto func = [](int id, std::string name) {
        cout << "name = " << name << ", id = " << id << endl;
    };
    CallFunc(func);
}
```

# 2、用法2

```C++
void CallFunc(std::function<void(int, std::string)> callback)
{
    callback(10, "Jack");
}

int main()
{
    
    std::function<void(int, std::string)> func = [](int id, std::string name) {
        cout << "name = " << name << ", id = " << id << endl;
    };
    CallFunc(func);
}
```