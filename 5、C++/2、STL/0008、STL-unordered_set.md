# 简介

STL容器 - unordered_set，无序集合容器。

# 初始化

```C++
#include <unordered_set>

unordered_set<ValueType> set_;
```

# 插入

向`unordered_set`中插入一个元素。

```C++
set_.insert(value);
```

# 查找

查找`unordered_set`中是否存在指定的元素。

```C++
if (set_.find(value) != set_.end()) {
    // 元素存在
} else {
    // 元素不存在
}
```

# 删除

删除`unordered_set`中指定的元素。

```C++
set_.erase(value);
```

# 大小

返回`unordered_set`中元素的数量。

```C++
size_t size = set_.size();
```

# 清空

清空`unordered_set`中的所有元素。

```C++
set_.clear();
```