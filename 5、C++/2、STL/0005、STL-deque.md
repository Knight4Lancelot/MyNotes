# 简介

STL 容器 - deque，双端队列容器。

# 初始化

```C++
#include <deque>

deque<T> deque_;
```

# push_back

将元素添加到`deque`的末尾。

```C++
deque_.push_back(item);
```

# push_front

将元素添加到`deque`的开头。

```C++
deque_.push_front(item);
```

# pop_back

移除`deque`末尾的元素。

```C++
deque_.pop_back();
```

# pop_front

移除`deque`开头的元素。

```C++
deque_.pop_front();
```

# front

返回`deque`开头的元素。

```C++
deque_.front();
```

# back

返回`deque`末尾的元素。

```C++
deque_.back();
```

# size

返回`deque`中元素的个数。

```C++
deque_.size();
```

# empty

检查`deque`是否为空，若为空返回`true`，否则返回`false`。

```C++
deque_.empty();
```

# emplace

在`deque`指定位置构造一个新元素。

```C++
deque_.emplace(deque.begin() + 2, item);
```

# emplace_front

在`deque`开头构造一个新元素。

```C++
deque_.emplace_front(item);
```

# emplace_back

在`deque`末尾构造一个新元素。

```C++
deque_.emplace_back(item);
```

# swap

交换两个`deque`的内容。

```C++
deque_.swap(newDeque_);
```
