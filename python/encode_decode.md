## [python 编码问题]( http://in355hz.iteye.com/blog/1860787 )
Python2 新手 编码问题 吐血总结: <https://www.cnblogs.com/yangruiGB2312/p/5790405.html>

### str & unicode
```python
s_str = '你好'        # str 字符串
s_uni = u'你好'       # unicode字符串
```
在python中str都是用字符集编码的`ansi`字符串; 而unicde则是字符串在python内部的编码方式.  


### encode & decode
- 字符串在Python内部的表示是`unicode编码`, 而我们日常用的字符集(如gb2312, utf-8, ascii等)都是字符的`二进制(字节)编码`形式.
- 任何两者编码的转换都需要经过unicode, 即先将其他编码的字符串解码成unicode, 再从unicode编码成另一种编码.
- encode: unicode -> utf8
- decode: utf8 -> unicode


### UnicodeEncodeError
> UnicodeEncodeError: 'ascii' codec can't encode characters in position 0-3: ordinal not in range(128) --- 用`ascii`编码含中文的unicode字符串所致


### 关于 unicode_escape
对于像`\u6768\u777f`这样被转义的unicode编码形式的文本字符串, 无论怎样print都没法显示成中文, 需要先escape成unicode再encode:
```java
s = '\u6768\u777f'
print "%s" % s.decode('unicode_escape').encode('utf-8')  # 杨睿
```

### 关于 stirng_escape
...
