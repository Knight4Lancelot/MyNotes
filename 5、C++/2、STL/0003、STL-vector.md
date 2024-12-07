# 简介

`std::vector`是 STL 中的一个动态数组容器，它提供了自动管理内存、动态增长、以及随机访问等特性。`std::vector`可以看作是一个可以自动扩展容量的数组。

# 初始化

```C++
#include <vector>

// 创建一个空的 vector
std::vector<int> vec;

// 创建一个包含初始值的 vector
std::vector<int> vec{1, 2, 3, 4, 5};

// 创建一个指定大小的 vector，并初始化所有元素为默认值
std::vector<int> vec(10);

// 创建一个指定大小的 vector，并初始化所有元素为指定值
std::vector<int> vec(10, 5);
```

# push_back

将一个元素添加到 vector 的末尾。

```C++
vec.push_back(6);
```

# pop_back

删除 vector 末尾的元素。

```C++
vec.pop_back();
```

# size

返回 vector 中当前元素的个数。

```C++
vec.size();
```
# empty

检查 vector 是否为空，如果为空返回 true，否则返回 false。

```C++
vec.empty();
```

# front

返回 vector 中第一个元素的引用。

```C++
vec.front();
```

# back

返回 vector 中最后一个元素的引用。

```C++
vec.back();
```

# clear

删除 vector 中的所有元素。

```C++
vec.clear();
```

# erase

删除 vector 中指定位置的元素。

```C++
// 删除 vector 中索引为 2 的元素
vec.erase(vec.begin() + 2);
```

# insert

在 vector 中指定位置插入一个或多个元素。

```C++
// 在 vector 中索引为 2 的位置插入值为 10 的元素
vec.insert(vec.begin() + 2, 10);
```

# resize

改变 vector 的大小。如果新大小小于当前大小，多余的元素会被删除。如果新大小大于当前大小，新元素会被初始化为默认值。

```C++
vec.resize(15);
```