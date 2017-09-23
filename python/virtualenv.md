# [virtualenv](https://github.com/lzjun567/note/blob/master/note/python/virtualenv.md)

为每个应用配置一套独立的Python运行环境, 便于python版本的管理和python库的管理

## 基本使用

### 安装
```
$ pip install virtualenv
```

### 创建虚拟环境
```
$ virtualenv <venv_name> 
```
默认会继承当前系统python环境的所有第三方包, 加上`--no-site-packages`参数会生成一个纯净的环境


### 激活
```
$ source <venv_name/bin/activate
```

### 退出
```
$ deactivate
```


## [其他](https://pythonguidecn.readthedocs.io/zh/latest/dev/virtualenvs.html)
为了保证虚拟环境的可移植性, 可以将当前环境包"冷冻": 
```
$ pip freez > requirements.txt
```
这样会创建一个requirements.txt文件, 其中包含了当前环境中的所有包及各自版本的简单列表.
当需要重新创建这样的环境时,只需要将当前环境恢复即可:
```
$ pip install -r requirements.txt
```
从而确保`安装`,`部署`和`开发`之间的一致性.
