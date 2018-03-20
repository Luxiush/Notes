## SVN(Subversion)
```
-> checkout, update
[repository](远程版本库)              [working copy](本地工作拷贝)             [workspace](实时工作区)
<- add, commit
```

### 配置
- 配置文件: .../conf/svnserver.conf

- 相关命令: propset, propget, propedit, proplist

#### [配置.svnignore文件]( https://www.jianshu.com/p/c02d8b335495 )
- 新建.svnignore文件
- 设置svn:ignore属性
```
$ svn propset svn:ignore -R -F .svnignore .   # R: recursively, F: file
```
> svn属性和源文件一样, 也受svn版本版本的管理, 添加或修改svn属性需要先提交再更新本地工作目录才能生效.


### [SVN v.s. Git]( http://blog.csdn.net/jackjia2015/article/details/50607408 )
<https://www.cnblogs.com/chen5421/p/5642472.html>

1. git是一个**分布式**版本高控制系统, svn则是**集中式**的.

2. svn有比git更强大的权限控制, 能够为每个开发者指定对某个文件的权限, 而git据目前所知则只能是对某个分支进行保护.

- 个人的理解, svn与git的区别在于svn少了git中所说的`本地仓库`.

- 实际中可以将 svn 与 git 结合使用.


> 总之，公司的开发团队在进行的项目开发管理时，svn是更好的选择，团队成员共同维护公司的中心版本。

> 若是开源项目，则git更加适合，每个人都可以维护自己专属的版本，同时有github开源社区支持。


### 分支和标签
主干为trunk.
其他分支保存在`branches`目录下, 创建新分支实际上就是在branches目录下创建一个trunk的拷贝.
标签与分支类似, 所有标签保存在`tags`目录下

### [常用命令]( http://blog.csdn.net/yangzhongxuan/article/details/7018168 )
- 整个流程与git一致(先从服务器上拉取最新版代码, 本地修改代码, 之后提交), 但用到的命令略有不同.

- 版本库配置文件说明: <http://www.runoob.com/svn/svn-create-repo.html>
```
$ svnadmin create <repository_name>          # 创建版本库

```

#### checkout
将服务器上的文件取回本地, 在本地创建一个工作副本, 类似`git  clone`.

```
$ svn checkout svn://192.168.1.1/pro/domain <local_repo_name>
$ svn checkout file:///C:/Users/test/Desktop/test	# 切出本地版本库
$ svn checkout -r <URL>@<revision_no> <path> 		# 切出某个版本
```

#### add
添加`新文件`到版本控制中.


#### status
查看本地工作副本的改动, 类似`git status`.

#### commit
- 将本地的改动提交到版本库, **本地的还要update一下才会更新**
- 原子性操作: 要么提交成功, 要么失败回滚.
- 等于git中的add+commit+push三步.


```
svn commit -m "log messag" <file_name>
```

#### update
> Bring changes from the repository into the working copy.

```
svn update # 更新到最新版本
svn update -r <version_no> <path> # -r指定更新到某个版本
```  

#### revert
撤销文件或目录的更改(undo), 有点像git中的checkout某个文件.
```
svn revert <file_name>
svn revert -R <dir_name>
```

#### resolved
移除`冲突状态`. (当发生冲突时, 会生成相应的表示冲突的文件, 而resolved就是用来移除这些文件的)


#### diff

#### log

#### cat
查看某个文件的过去版本
``
svn cat -r <version_no> <file_name>
svn cat <file_name>@<version_no>
``


#### info
查看详细信息
```
svn info <path/file>
```

#### merge
```
svn merge <target_dir> 将目标目录(通常是branch)合并到当前目录.
```


#### copy
创建`分支`或`标签`

#### lock, unlock


####. delete
- alias: del, rm, remove

| 参数 | 说明 |
|:---|:---|
| --keep-local | 只从svn中删除, 不删除本地工作目录中的 |


#### export
导出某个版本


#### 命令对比
GIT和SVN之间的区别及基本操作对比 <http://blog.csdn.net/scythe666/article/details/51941622>
git之：常用的svn与git命令对比 <https://www.cnblogs.com/chen5421/p/5642472.html>

| git | svn |
|:---|:---|
| git init | svnadmin create |
| git clone | svn checkout |
| git add,commit,push | svn commit |
| git pull | svn update |
| git checkout <file_name> | svn revert <file_name> |
| status | . |
| log | . |
| diff | . |




### [客户端基本操作]( https://www.cnblogs.com/xilentz/archive/2010/05/06/1728945.html )
