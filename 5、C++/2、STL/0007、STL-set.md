# 简介

STL容器 - set，集合容器，元素不可重复，且已经插入的元素不可修改。

# 初始化

```C++
#include <set>

set<ValueType> set_;
```

# insert

向`set`中插入一个元素。

```C++
set_.insert(value);
```

# find

查找`set`中是否存在指定的元素。

```C++
if (set_.find(value) != set_.end()) {
    // 元素存在
} else {
    // 元素不存在
}
```

# erase

删除`set`中指定的元素。

```C++
set_.erase(value);
```

# size

返回`set`中元素的数量。

```C++
size_t size = set_.size();
```

# clear

清空`set`中的所有元素。

```C++
set_.clear();
```

# emplace

向`set`中插入一个新元素。

```C++
set_.emplace(value);
```
