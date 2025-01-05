# 简介

STL容器 - stack，栈容器。

# 初始化

```C++
#include <stack>

stack<T> stack_;
```

# push

将`item`压入`stack`的栈顶。

```C++
stack.push(item);
```

# top

返回`stack`栈顶的元素。

```C++
stack.top();
```

# pop

弹出`stack`栈顶的元素，不会返回弹出的元素值。

```C++
stack.pop();
```

# size

返回`stack`栈中元素的个数。

```C++
stack.size();
```

# empty

检查`stack`栈是否为空，若为空返回`true`，否则返回`false`。

```C++
stack.empty();
```

# emplace

在`stack`栈顶构造一个新元素。

```C++
stack.emplace(item);
```

# swap

交换两个`stack`的内容。

```C++
stack1.swap(stack2); // 把stack1和stack2的内容交换
```