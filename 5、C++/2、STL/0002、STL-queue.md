# 简介

STL容器 - queue，队列容器。

# 初始化

```C++
#include <queue>

queue<T> queue_;
```

# push

在`queue`队列尾部插入一个元素。

```C++
queue.push(item);
```

# pop

删除`queue`队列头部第一个元素。

```C++
queue.pop();
```

# size

返回`queue`队列中元素的个数。

```C++
queue.size();
```

# empty

检查`queue`队列是否为空，若为空返回`true`，否则返回`false`。

```C++
queue.empty();
```

# front

返回`queue`队列的第一个元素。

```C++
queue.front();
```

# back

返回`queue`队列的最后一个元素。

```C++
queue.back();
```

# emplace

在`queue`队列尾部插入一个新元素。

```C++
queue.emplace(item);
```

# swap

交换两个`queue`的内容。

```C++
queue1.swap(queue2); // 把queue1和queue2的内容交换
```