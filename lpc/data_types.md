### 主要数据类型
- int, float, string

- object: `Object pointer`.
They are references to LPC programs that has been loaded into memory.

- function: `Function pointer`.
函数指针

- array: list. (int * arr = [];)

- mapping: dict.

- void: 只用于声明不反回任何数据的`函数`

- mixed: 可以赋其他任何类型的值(有点像c里面的viod类型).


#### string
- 常用函数: strlen, sprintf, sscanf, atoi, atof, write
```c++
string buffer_out = "";
s1 = "abcde";
int a = 23;
string s = s1 + "_" + a;
for (int i = 0; i < strlen(s); i++){
	buffer_out += sprintf("%c ", s[i]);
}
// buffer_out: a b c d e _ 2 3

// atoi, atof    --- ascii to int/float
string s_i = "123", s_f = "34.5";
int num_i = atoi(s_i);		// 123
int num_i2 = atoi(s_f); 	// 34;
float num_f = atof(s_f);	// 34.5

//

```

- 时间函数: time, ctime, file_time, object_time
```c++
int time()				// 获取当前时间
string ctime(int tm)	// 转换成字符串	Thu Jan 18 03:02:21 2018
int mktime(int year, int month, int date, int hour, int minute, int second)
int file_time(string obref)		// 获取文件创建时间
int object_time(object ob)		/// obj最后一次被调用的时间
```


#### array
```c++
int * arr = allocate(3);	// 为数组预分配空间, 并初始化为0;
arr += [1]; // 添加一个元素
number_array(1, arr); // 返回1第一次出现的位置, 不存在时返回-1
arr -= [1]; // 删除一个元素

int * arr2 = arr1;	// 传引用
arr2 += [3,4,5,6,7];

printf("%s", impode(arr, "|"));		// 将array合并成string,  explode用于将string查分成array

foreach (int i in arr){
	printf("%d" , i);
}

// sizeof获取元素个数
for (int i = 0; i < sizeof(arr); i++){
	printf("%d", arr[i])
}
```


#### mapping(hash表)
- 访问不存在的key时, 返回 0
```c
mapping m = {
	key1: "value1",
	key2: "value2",
	....
};

m["key3"] = "value3";	// add key

foreach ( string k, string v in m)
	printf("%s, %s", k, v)

map_delete(m, "key1")	//  删除一个key

mixed v = m["key1"]
undefinedp(v)	// key1不存在时返回true

foreach (mixed k in keys(m))	// 获取mapping的所有key值
	map_delete(m, k);

```



#### object



##### 数据类型判断:
intp, stringp, arrayp, mapp,
