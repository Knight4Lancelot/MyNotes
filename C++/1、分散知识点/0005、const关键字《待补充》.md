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
