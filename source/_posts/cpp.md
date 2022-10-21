---
title: c++ 11
date: 2022-10-20 17:39:14
tags:
---

### c++11
通过内存模型、线程、原子操作等来支持本地并行编程(Native Concurrency)。
通过统一初始化表达式、auto、declytype、移动语义等来统一对泛型编程的支持。 
通过 constexpr、POD(概念)等更好地支持系统编程。
通过内联命名空间、继承构造函数和右值引用等，以更好地支持库的构建。

### _Pragma

```c
#pragma

_Pragma("once)
```

### 变长参数定义以及__VA_ARGS_
```c
#define PR(...) printf(__VA_ARGS__) 
```

### long long
- ll (long long) %lld
- ull (unsigned long long) %llu

limits.h
LLONG_MIN
LLONG_MAX
ULLONG_MIN

### 静态断言 + static_assert

静态断言
编译时期断言
```c++
template <typename t, typename u> int bit_copy(t& a, u& b) {
  static_assert(sizeof(b) == sizeof(a), "the parameters of bit_coppy must have same width.");

  // TODO
}
```


### noexcept
```c++
void BlockThrow() noexcept { Throw(); }
```
noexcept 会直接调用`std::terminate`中断程序的执行,阻止异常传播.
即声明不抛出异常的函数

```c++
template <class T>
void fun() noexcept(noexcept(T())) {}
```



eg:
```c++
template<class T> class A {
  public:
    static constexpr T min() noexcept { return T(); }
    static constexpr T max() noexcept { return T(); }
    static constexpr T lowest() noexcept { return T(); }
}
```

c++11中类的析构函数默认也是noexcept(true)的.


### 2.7 快速初始化成员变量
C++11 允许使用= {} 进行就地的非静态成员变量初始化。

```c++
struct init{ int a = 1; double b {1.2}; }
```

初始化列表 后作用与 非静态成员, 即 初始化列表的效果总是优先于就地初始化的。


### 2.8 非静态成员的sizeof
c++11 中对非静态成员变量使用sizeof操作是合法的。
```c++
#include<iostream>
using namespace std;

struct People {
  public:
    int hand;
}

int main() {
  cout << sizeof(People::hand) << endl;
}
```


