### [gcc常用命令]( http://blog.csdn.net/u013467442/article/details/44560443 )

### 编译过程的四个阶段
预处理(也称预编译，Preprocessing)、编译(Compilation)、汇编 (Assembly)和连接(Linking).

1. -E选项，可以让编译器在预处理后停止，并输出预处理结果
	gcc -E test.c -o test.i 或 gcc -E test.c
	
2. -S选项，表示在程序编译期间，在生成汇编代码后，停止，-o输出汇编代码文件
	gcc -S test.i -o test.s
	
3. -C 编译为目标文件(.o)
	gcc -c test.s -o test.o
	
4. 将程序的目标文件与所需的所有附加的目标文件连接起来，最终生成可执行文件。附加的目标文件包括静态连接库(.a)和动态连接库(.dll)。
	gcc test.o -o test


### gcc的 -l参数、-L参数 和 -I参数	
1. `-l`参数指定程序要链接的库，`-l`参数紧接着就是库名，
> 那么库名跟真正的库文件名有什么关系呢？
> 就拿数学库来说，他的库名是m，他的库文件名是libm.so，
> 很容易看出，把库文件名的头lib和尾.so去掉就是库名了。


2.`-L`参数跟着的是库文件所在的目录名
> 比如我们把libtest.so放在/aaa/bbb/ccc目录下，
> 那链接参数就是 
> -L/aaa/bbb/ccc -ltest

3. `-I`参数是用来指定头文件目录
> /usr/include目录一般是不用指定的，gcc知道去那里找，
> 但是如果头文件不在/usr/include里我们就要用-I参数指定了，
> 比如头文件放在/myinclude目录里，
> 那编译命令行就要加上-I/myinclude参数了。
