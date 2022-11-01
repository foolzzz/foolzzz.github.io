---
title: c++ 11
date: 2022-10-20 17:39:14
tags:
---


## 2. 保证稳定性与兼容性
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


### 2.9 friend

### 2.10 final/override
`final`关键字使派生类不可覆盖它所修饰的虚函数.

如果派生类的虚函数声明时, 使用了`override`描述符, 那么该函数必须重载其基类中的同名函数，否则代码将无法通过编译。


### 2.11 模板函数的默认模板参数

### 2.12 外部模板

### 2.13 局部和匿名类型作模板实参

## 3 通用为本, 专用为末
### 3.1 继承构造函数

子类可以通过使用using声明来声明继承基类的构造函数.

```c++
#include <iostream>
using namespace std;

struct A {
  A(int i) {}
}

struct B : A {
  using A::A;

  int d {0};
}

int main() {
  B b(365);
}
```

### 3.2 委派构造函数

在C++11中，委派构造函数，就是指委派函数将构造的任务委派给了目标构造函数来完成的这样一种类构造的方式.
```c++
class Info {
public:
  Info() : Info(1, 'a') {}
  Info(int i) : Info(i, 'a') {}
  Info(char e) : Info(1, e) {}

private:
  Info(int i, char e): type(i), name(e) {}
  int type;
  char name;
}
```

### 3.3 右值引用；移动语义和完美转发

3.3.1 指针成员与拷贝构造
涉及到指针要使用深拷贝.

3.3.2 移动语义
移动构造函数

```c++
#include <iostream>
using namespace std;

class HasPtrMem {
public:
  HasPtrMem():d(new int(3)) {}
  HasPtrMem(const HasPtrMem &h):d(new int(*h.d)) {}

  HasPtrMem(HasPtrMem && h) : d(h.d) { // 移动构造函数
    h.d = nullptr;
  }

  ~HasPtrMem() {
    delete d;
  }

  int *d
}
```

3.3.3 左值\右值 与 右值引用

可以取地址的、有名字的就是左值.
不可以取地址的，没有名字的就是右值.

c++11 中, 右值分为两种, 将亡值(xvalue, eXpiring Value), 纯右值(prvalue, Pure Rvalue)

```c++
T && a = ReturnRvalue();
T b = ReturnRvalue();
```
右值引用是不能绑定到任何左值的
```c++
int c;
int && d = c; // X 编译失败
```

出现这样的状况的原因是，在常量左值引用在 C++98 标准中开始就是个“万能”的引用 类型。它可以接受非常量左值、常量左值、右值对其进行初始化。而且在使用右值对其初始 化的时候，常量左值引用还可以像右值引用一样将右值的生命期延长。不过相比于右值引用 所引用的右值，常量左值所引用的右值在它的“余生”中只能是只读的。相对地，非常量左 值只能接受非常量左值对其进行初始化。

```c++
const bool & judge = true;
const bool judge2 = true;
```

常量左值引用可以减少对象开销.


3.3.4 std::move 强制转化为右值


3.3.5 移动语义的一些其他问题
move_if_noexcept(x)
如果x是noexcept的, 则为move语义，否则为copy语义.

3.3.6 完美转发 P85

```c++
void IrunCodeActually(int t) {}

template <typename T>
void IamForwarding(T && t) {
  IrunCodeActually(static_cast<T &&>(t));
}
```


```c++
#include <iostream>
using namespace std;

void RunCode(int && m) {}
void RunCode(int & m) {}
void RunCode(const int && m) {}
void RunCode(const int & m) {}

template <typename T>
void PerfectForward(T && t) { RunCode(forward<T>(t)); }

int main() {
  int a = 1;
  int b = 2;
  const int c = 3;
  const int d = 4;

  PerfectForward(a);
  PerfectForward(move(b));
  PerfectForward(c);
  PerfectForward(move(d));
}
```


3.4 显示转换操作符

`explicit`


3.5 列表初始化
3.5.1 初始化列表
```c++
map<int, float> m = {{1, 1.0f}, {2, 2.1f}};

initializer_list<int>;

```
3.5.2 防止类型收窄
C++11 使用列表初始化可以防范类型收窄, 也能够加强类型使用的安全性.

3.6 POD类型 P105

3.7 非受限联合体

3.8 用户自定义字面量

3.9 内联名字空间
`inline namespace`

3.10 模板的别名
```c++
typedef std::vector<std::string> strvec;


// c++11
using uint = unsigned int;
typedef unsigned int UINT;
using sint = int;

template<typename T> 
using MapString = std::map<T, char *>;


MapString<int> numberedString;
```

3.11 一般化的SFINEA规则
模板推导
```c++
#include <iostream>

struct Test {
  typedef int foo;
}

template <typename T>
void f(typename T::foo) {

}

template <typename T>
void f(T) {

}

int main() {
  f<Test>(10); // #1
  f<int>(10); // #2
}
```

## 4 新手易学，老兵易用
4.1 右尖括号>的改进

4.2 auto类型推导

4.3 decltype

4.4 追踪返回类型
```c++
template<typename T1, typename T2>
auto Sum(T1 & t1, T2 & t2) -> decltype(t1 + t2) {
  return t1 + t2;
}
```

4.4.2 使用追踪返回类型的函数

```c++
int func(char *a, int b)
```



## 5 提高类型安全

5.1 强类型枚举
```c++
enum class Type {};
```

5.2 堆内存管理：智能指针与垃圾回收
unique_ptr, shared_ptr, weak_ptr

## 6 提高性能及操作硬件的能力

6.1 常量表达式

变长参数
```c++
pair<int, double>;

std::tuple<double, char, std::string> collections;
```
变长模板

```c++
template <typeame... Elements> class tuple;

tuple<int, char, double>;
```

6.3 原子类型与原子操作 P196
```c++
atomic_llong
```

## 7 为改变思考方式而改变

7.2 默认函数的控制 P227


7.3 lambda函数 P234

```c++
[capture](parameters) mutable -> return-type { statement }

[]{}
```
捕捉列表
- `[var]` 值传递
- `[=]` 值传递方式捕捉所有父作用于的变量
- `[&var]` 引用传递
- `[&]` 引用传递捕捉父作用于的变脸
- `this` 表示值传递的方式捕捉当前的this指针

## 8 融入实际应用

8.1 对齐 P258

8.2 通用属性
