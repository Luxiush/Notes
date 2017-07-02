arm-elf-gcc -S max.c	
	得到由c文件生成的汇编文件max.s

arm-elf-gcc -c max.s
	由汇编文件编译得到Object文件max.o
	
arm-elf-readelf -a max.o > max_elfinfo
	这个命令将给出全部的Object文件信息,保存在
	max_elfinfo这个文件中

hexdump -C max.o > max_hex  
	打印出Object文件的全部字节，保存在max_hex文件中

arm-elf-ld.real -o max2.out max.o
    链接指定Object文件，max2.out为生成的文件，max.o为源文件

 	

	Section Header Table中保存了所有Section的描述信息，
通过Section Header Table可以找到每个Section在文件中的位置。

	.text和.data是我们在汇编程序中声明的Section，而其它Section是汇编器自动添加的。
	Addr是这些段加载到内存中的地址，加载地址要在链接时填写，
	
	
.strtab section 
	中存储着的都是以字符 为分割符的字符串，这些字符串所表示的内容，
通常是程序中定义的函数名称、所定义过的变量名称等等。	
	字符串表在真正链接和生成进程映像过程中是不需要使用的，
但是其对我们调试程序来说就特别有帮助，
因为我们人看起来最舒服的还是自然形式的字符串，
而非像天书一样的数字符号。


