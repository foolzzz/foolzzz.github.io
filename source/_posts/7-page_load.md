---
title: page-load
date: 2022-11-01 11:21:39
tags:
---


- preload
提升资源加载的优先级.
```html
<link rel="preload" as="script" href="./main.js">
```

- prefetch
用于加载未来页面会用到的资源, 并且告诉浏览器在空闲的时候下载.
```html
<link rel="prefetch" as="script" href="https://cdn.bootcss.com/jquery/2.1.4/jquery.min.js">
```

- preconnect
预建立连接

- dns-prefetch
预解析dns
```html
<link rel="dns-prefetch" href="https://cdn.bootcss.com">
```



https://blog.51cto.com/u_15089765/2600770?articleABtest=1

