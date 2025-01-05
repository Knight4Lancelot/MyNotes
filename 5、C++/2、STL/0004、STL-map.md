# 简介

STL 容器 - map，映射容器。

# 初始化

```C++
#include <map>

map<T1, T2> map_;
```

# insert

将键值对`{key, value}`插入到 map 中。

```C++
map_.insert({key, value});
map_.insert(make_pair(key, value));
```

# find

在`map`中查找键为`key`的元素，若找到则返回指向该元素的迭代器，否则返回`map_.end()`。

```C++
auto it = map_.find(key);
if (it != map_.end()) {
    // 找到了
} else {
    // 没找到
}
```

# erase

从 map 中删除键为`key`的元素。

```C++
map_.erase(key);
```

# size

返回`map`中元素的个数。

```C++
map_.size();
```

# empty

检查`map`是否为空，若为空返回`true`，否则返回`false`。

```C++
map_.empty();
```

# emplace

在`map`中插入一个新元素。

```C++
map_.emplace(key, value);
```

# swap

交换两个`map`的内容。

```C++
map_.swap(other_map);
```