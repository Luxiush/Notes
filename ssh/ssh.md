### 生成密钥对
```shell
$ ssh-keygen -t rsa
```
- 公钥：.ssh/id_rsa.pub
- 私钥: .ssh/id_rsa


### [管理多个ssh key]( https://www.cnblogs.com/Gent-Wang/p/7422433.html )

**ssh-agent**: 一个密钥管理器, 运行ssh-agent后使用ssh-add将密钥交给ssh-agent保管, 其他程序将验证申请交个ssh-agent来完成认证过程.

1. 启动ssh-agent
```shell
$ exec ssh-agent bash
```

2. 添加私玥
```shell
$ ssh-add <path-to-private-key>
```
*如果添加失败则重启ssh-agent*

3. 在.ssh目录下创建配置文件config
```
# git@github.com
Host xxxx.com
HostName github.com
IdentityFile ~/.ssh/id_rsa_github
User git
```
