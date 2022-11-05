---
title: typescript
date: 2022-11-03 17:33:52
tags: web
---

## 基础类型

- any
- number
- string
- boolean
- 数组
- 元祖
- 枚举
- void
- null
null表示 什么都没有, 是一个只有一个值的特殊类型。表示一个空对象的引用。
- undefined
undefined是一个没有设置值的变量。
- never

## 变量声明
`var [变量名] : [类型] = 值`

```typescript
var uname:string = "Runoob";
```

### 类型断言 (Type Assertion)
`<类型>值`
`值 as 类型`

```ts
var str = '1'
var str2:number = <number> <any> str
console.log(str2)
```

## 运算符

### 算术运算符
```
+ - * / % ++ -- 
```
### 关系运算符
```
== != > < >= <= 
```
### 逻辑运算符
`&& || !`

### 位运算符
`& | - ^ << >> >>>`
### 赋值运算符
`= += -= *= /=`
### 三元运算符
`? :`
### 类型运算符
`typeof`
`instanceof`

## 条件语句
```
if
if else
if ... else if ... else ...
switch 
```
## 循环
```typescript
// 1
for(init; condition; increment) {
  statement;
}

// 2
for(val in list) {

}

// 3
let arr = [1, "string", false];

for(let entry of someArray) {
  console.log(entry); // 1, "string", false
}

// 4
let list = [4, 5, 6];
list.foreach((val, idx, arr) => {
  // ...
});

// 5
list.every((val, idx, arr) => {

  return true; // Continue
})

// 6
while(cond) {
  statement;
}

do {
  // ...
}
while(cond);

```

## 函数
```ts
function name() {

}

functon () {

}

// 函数返回值
function name() : return_type {

}

// eg
function greet() : string {

}

// 带参数
function name(x: number, y: number) : number {

}

// 可选参数
function buildName(firstName: string, lastName?: string) {
  if(lastName) {

  }

}

// 默认参数
function calculate(price: number, rate: number = 0.50) {

}

// 剩余参数
function buildName(firstName: string, ...restOfName: string[]) {
  return firstName + " " + restOfName.join(" ");
}

// 匿名函数
var msg = function() {
  return "hello world!";
}

// 匿名函数自调用
(function() {
  var x = 'hello!';
  console.log(x);
})();


// 构造 函数
var res = new Function([arg1, arg2], functionBody);

/// eg:
var myFunction = new Function("a", "b", "return a+b;")


// lambda
([param1, param2, ...paramN]) => statement;

var foo = (x: number) => 10 + x

``` 

## Typescript Number

```
MAX_VALUE
MIN_VALUE
NaN
NEGATIVE_INFINITY
POSITIVE_INFINITY
prototype
constructor

```
## String
## Array
## Map
## 元组
## 联合类型
## 接口
```ts
interface IPerson {
  firstName: string,
  lastName: string,
  sayHi: ()=>string
}

var customer: IPerson = {
  firstName: "Tom",
  lastName: "Hanks",
  sayHi: ():string => {return "Hi there";}
}


var employer:IPerson = {
  firstName:"Jim",
  lastName:"Balkes",
  sayHi: ():string => { return "Hello!"}
}


interface RunOptions {
  program: string;
  commandLine: string[]|string|()=>string);
}

var options:RunOptions = {program:"test1", commandLine: "Hello"};

// 限制数组的索引值为number
interface namelist {
  [index:number]: string
}
var list2:namelist = ["Google", "Runoob", "TaoTao"];

// 接口继承
Child_interface_name extends super_interface_name;

Child_interface_name extends super_interface1_name,super_interface2_name,super_interface3_name;


// 单继承实例
interface Perosn {
  age: number
}

interface Musician extends Person {
  instrument: string
}

var drummer = <Musician>{};
drummer.age = 27;
drummer.instrument = "Drums";



interface IParent1 {
  v1: number
}
interface Iparent2 {
  v2: number
}

interface Child extends IParent1, IParent2 { }
var Iobj:Child = {v1:12, v2:23}
```

## 类
```ts
class Car {
  engine:string;

  constructor(engine:string) {
    this.engine = engine;
  }

  disp():void {
    console.log("engine: " + this.engine);
  }
}

var obj = new Car("BMW");

obj.disp();

// 类继承
class Shape {
  Area:number

  constructor(a:number) {
    this.Area = a;
  }
}

class Circle extends Shape {
  disp():void {
    console.log("Circle Area: " + this.Area);
  }
}

var obj = new Circle(223);
obj.disp();

// ts 不支持多继承

// 支持方法重写，调用父类用super


// static用于定义类的数据成员(属性/方法)
class StaticMem {
  static num:number

  static disp():void {
    console.log("Num: " + StaticMem.num);
  }
}


// instanceof
class Person {}
var obj = new Person()
var isPerson = obj instanceof Person;
console.log("是吗?" + isPerson);


// 访问控制符
//  public/protected/private
class Encapsulate {
  str1:string = "hello";
  private str2:string = "world"
}

// var obj = new Encapsulate();
```

类和接口
```ts
interface ILoan {
  interest: number
}

class AgriLoan implemnts ILoan {
  interest: number
  rebate: number

  constructor(interest:number,rebate:number) {
    this.interest=interest
    this.rebate=rebate
  }
}

```

## 对象

```ts
var obj = {
  key1:"value1",
  key3: function() {

  },
  key4:["a"]
}

// Duck Typing

interface IPoint {
  x:number
  y:number
}

function addPoints(p1:IPoint, p2:IPoint):IPoint {
  var x = p1.x + p2.x
  var y = p1.y + p2.y
  return {x:x, y:y}
}

```

## Typescript namespace

```ts
namespace nsa {
  export interface ISomeInterfaceName { }
  export class SomeClassName { }
}

nsa.SomeClassName

// 如果命名空间在一个单独ts文件中，可以使用///引用他
/// <reference path="SomeFileName.ts">

```

## Typescript module

```ts
export interface SomeInterface {

}
```

```ts
import someInterfaceRef = require("./SomeInterface");
```

## 声明文件

xx.d.ts

```ts
declare var jQuery: (selector: string) => any;

jQuery("#foo");
```

## ref
菜鸟教程 https://www.runoob.com/typescript/ts-interface.html