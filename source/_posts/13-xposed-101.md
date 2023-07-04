---
title: 13-xposed-101
date: 2023-06-20 17:30:54
tags:
---


- https://juejin.cn/post/7194438728381628474 xposed native hook
- https://github.com/Breathleas/xposedhookso 一个xp so hook demo.
修改了加载的so，在自己的so里加载了真正的so，有点不优雅。
Hook点
- https://www.jianshu.com/p/93828be3ff58 另一个xp so hook demo

Dobby

`loadLibrary`
http://aospxref.com/android-11.0.0_r21/xref/external/jsilver/src/org/clearsilver/jni/JNI.java#81
```java
81    public static void loadLibrary() {
82  
83      // Library already loaded? Great - nothing to do.
84      if (successfullyLoadedLibrary) {
85        return;
86      }
87  
88      synchronized (callbackLock) {
89  
90        // Search librarySearchPaths...
91        String platformLibraryName = System.mapLibraryName(libraryName);
92        for (String path : librarySearchPaths) {
93          try {
94            // Attempt to load the library in that path.
95            System.load(new File(path, platformLibraryName).getAbsolutePath()); // 调用了System.Load
96            // If we got here, it worked. We're done.
97            successfullyLoadedLibrary = true;
98            return;
99          } catch (UnsatisfiedLinkError e) {
100            // Library not found. Continue loop.
101          }
102        }
103  
104        // Still here? Couldn't load library. Fail.
105        if (failureCallback != null) {
106          failureCallback.run();
107        }
108      }
109  
110    }
```

`System.Load` 调用了 `Runtime.load0`
http://aospxref.com/android-11.0.0_r21/xref/libcore/ojluni/src/main/java/java/lang/System.java
```java
1626      @CallerSensitive
1627      public static void load(String filename) {
1628          Runtime.getRuntime().load0(Reflection.getCallerClass(), filename);
1629      }
```

所以hook点可以是 `Runtime.load0`




REF:
https://juejin.cn/post/7194438728381628474 so文件加载原理
