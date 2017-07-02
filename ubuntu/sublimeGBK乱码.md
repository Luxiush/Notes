ref:
* <a href="http://blog.csdn.net/lxyhenpiaoliang/article/details/51939033"> link1 </a>
1. 安装包管理器
1.1. 打开命令行: View -> Show Console 
1.2. 执行命令：
```
import urllib.request,os; pf = 'Package Control.sublime-package'; ipp = sublime.installed_packages_path(); urllib.request.install_opener( urllib.request.build_opener( urllib.request.ProxyHandler()) ); open(os.path.join(ipp, pf), 'wb').write(urllib.request.urlopen( 'http://sublime.wbond.net/' + pf.replace(' ',' ')).read())
```

2. 安装乱码处理插件
ctrl+shift+p -> `install package` -> `ConvertToUTF8`(or `GBK Encoding Support`) -> install

* [由于 Sublime Text 3 内嵌的 Python 限制，ConvertToUTF8 可能无法正常工作,的解决方案]( https://github.com/seanliang/Codecs33/blob/linux-x64/README.zh_CN.md )

