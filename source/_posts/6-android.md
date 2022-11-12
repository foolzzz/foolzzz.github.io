---
title: android
date: 2022-10-30 16:54:12
tags:
---

[TOC]

## 3.init进程
## 4. JNI与NDK
4.1 Android 与 JNI
4.2 JNI的基本原理
4.3 调用JNI函数
4.4 在C程序中运行Java类
4.5 直接注册JNI本地函数
4.6 使用Android NDK开发
## 5. Zygote P137
5.1 Zygote是什么
5.2 由app_process运行ZygoteInit class

Zygote由Java编写, 不能直接由init启动。需要由app_process进程生成dalvik虚拟机，在虚拟机上状态运行ZygoteInit类。

5.2.1 生成AppRuntime对象
AppRuntime --> AndroidRuntime

`app_process [java-options] cmd-dir start-class-name [options]`
- java-options 传给虚拟机的选项，必须以-开始
- cmd-dir 所需要运行的进程所在的目录
- start-class-name 在虚拟机中运行的类的名称, 在加载到虚拟机后调用类的main
- \[options\] 传递给类的选项

```sh
/system/bin/app_process -Xzygote /system/bin --zygote --start-system-server
```

5.2.2 调用AppRuntime对象

5.2.3 创建Dalvik虚拟机

5.2.4 运行ZygoteInit类

5.3 ZygoteInit类的功能

5.3.1 绑定/dev/socket/zygote套接字

5.2.3 加载应用程序Framework中的类与平台资源

5.3.3 运行SystemServer


## 6. Android服务概要
## 7. Android Binder IPC
## 8. Android Service Framework
## 9. 本地系统服务 Native System Service
## 10. Java服务框架 Java Service Framework
## 11. Java系统服务运行分析




