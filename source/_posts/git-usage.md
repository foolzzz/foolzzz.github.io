---
layout: title
title: git-usage
date: 2022-10-17 14:48:01
tags:
---

## Merge
git merge --abort


## 显示多个分支的共同commit
```
# 显示多个commit依次合并后的base
git merge-base $branch1 $branch2 

# 显示多个commit的共同base
git show-branch --merge-base $branch1 $branch2 
```

## cherry-pick

- 转移单个提交
```
git cherry-pick <commitHash>/<branch>
```
- 转移多次提交
```
git cherry-pick <HashA> <HashB>
git cherry-pick A..B # 不含A
git cherry-pick A^..B # 含A
```


## rebase
> https://www.jianshu.com/p/4a8f4af4e803

```sh
git rebase [startpoint] [endpoint] --onto [branchname]
```





# Ref
rebase https://zhuanlan.zhihu.com/p/75499871