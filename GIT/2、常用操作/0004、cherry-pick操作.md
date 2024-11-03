# 1、合并提交

## 1-1、合并单个提交

```shell
git cherry-pick <hash>
```

## 1-2、合并多个提交

```shell
git cherry-pick <hash1> <hash2> <hash3> <hashN>
```

## 1-3、合并提交范围

```shell
git cherry-pick <hashA> .. <hashB>
```

# 2、编辑本次提交的信息

在`cherry-pick`的时候，可以使用`-e`选项来编辑提交信息。

```shell
git cherry-pick -e <hash>
```

# 3、保留提交信息

使用`-x`选项可以在提交信息中加入原始提交的引用信息，方便追溯。

```shell
git cherry-pick -x <hash>
```

# 4、忽略空提交

使用`--skip`选项可以跳过空的提交（即已经应用的变更）。

```shell
git cherry-pick --skip
```

# 5、放弃本次提交

```shell
git cherry-pick --abort
```

# 6、继续cherry-pick过程

```shell
git cherry-pick --continue
```