---
title: javascript格式
date: 2022-11-05 15:27:47
tags:
---

## CJS
CommonJS
```js
// importing
const doSth = require('./doSth.js');

// exporting
module.exports = function doSth(n) {

}
```
- 经常出现于node开发
- 可以从node_modules或者本地引入模块。eg: `const someModule = require("./some/local/file");`
- cjs不能在浏览器里工作。如果需要在浏览器工作需要转码和打包.


## AMD
异步模块定义
格式一般如下
```js
define(['dep1', 'dep2'], function(dep1, dep2) {
  return function () {};
});
```

```js
define(function (require) {
  var dep1 = require('dep1');
  var dep2 = require('dep2');

  return function() {}
})
```

- AMD是异步引入模块
- AMD是给前端用的
- 不如CJS直观

## UMD
Universal Module Definition

```js
(function (root, factory) {
  if(typeof define === 'function' && define.amd) {
    define(["jquery", "underscore"], factory);
  } else if (typeof exports === "object") {
    module.exports = factory(require("jquery"), require("underscore"));
  } else {
    root.Requester = factory(root.$, root._);
  }
}(this, function ($, _) {
  // this is where I defined my module implementation
  var Requester = { /* ... */  };
  return Requester;
})
```

- 前后端通用
- umd更像是配置多模块系统的配置
- umd通常是rollup,webpack的候补选择.

