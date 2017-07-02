# [Python2](http://www.runoob.com/python/python-tutorial.html)
## MySQL数据库操作

  
## 网络编程


## 进程和线程
### 多进程
**....**
### 多线程
* Python解释器由于设计时有GIL全局锁，导致了多线程无法利用多核。多线程的并发在Python中就是一个美丽的梦。
### ThreadLocal
* 对于一个全局的ThreadLocal对象，每个Thread都可以访问其属性，但是每个属性都是线程的局部变量。
* ThreadLocal最常用的地方就是为每个线程绑定一个数据库连接，HTTP请求，用户身份信息等，这样一个线程的所有调用到的处理函数都可以非常方便地访问这些资源。  
### 分布式进程
Python的multiprocessing模块不但支持多进程，其中managers子模块还支持把多进程分布到多台机器上。一个服务进程可以作为调度者，将任务分布到其他多个进程中，依靠网络通信。