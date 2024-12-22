# 简介

STL容器 - unordered_map，无序映射容器。

# 初始化

```C++
#include <unordered_map>

unordered_map<KeyType, ValueType> map_;
```

# 插入

向`unordered_map`中插入一个键值对。

```C++
map_.insert(make_pair(key, value));
```

# 访问

通过键访问`unordered_map`中的值。

```C++
ValueType value = map_[key];
```

# 查找

查找`unordered_map`中是否存在指定的键。

```C++
if (map_.find(key) != map_.end()) {
    // 键存在
} else {
    // 键不存在
}
```

# 删除

删除`unordered_map`中指定的键值对。

```C++
map_.erase(key);
```

# 大小

返回`unordered_map`中键值对的数量。

```C++
size_t size = map_.size();
```

# 清空

清空`unordered_map`中的所有键值对。

```C++
map_.clear();
```