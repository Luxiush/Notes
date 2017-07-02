## AndroidStudio
sdk 路径： E:\Users\LuXiushun\AppData\Local\Android\sdk
adb 路径： E:\Users\LuXiushun\AppData\Local\Android\sdk\platform-tools

## android系统文件路径
* 锁屏密码信息
/data/system/password.key 

* wifi信息
/data/misc/wifi/wpa_supplicant.conf

## 常用adb命令
```shell
adb shell 				# 进入adb shell
	
adb devices 				# 查看设备

adb root  				# 获取root权限
adb su

adb push [source] [destination] 	# 向设备添加文件
adb pull [source] [destination] 	# 从设备上复制文件

adb uiautomator dump 			# creates an XML dump of current UI hierarchy
```
