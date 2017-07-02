# python 面向对象编程
##
* 可以在创建实例的时候绑定必要属性
* 可以自由地给一个实例绑定附加属性(成员变量)
* 私有变量：变量名以“__”开头
* 特殊变量(__xxx__)：可以直接访问，不是私有变量

```
class Student(object):
	pass
```

## 继承 && 多态
```
class Animal(object):
	def run(self):
		print 'Animal is running'

class Dog(Animal):
	pass
	
class Cat(Animal):
	def run(self):
		print 'Cat is running'
		
def run2(animal):
	animal.run()
	

if(__name__=='__main__'):
	dog = Dog()
	dog.run() #继承
	
	cat = Cat()
	run2(cat) #多态

```

## 获取对象信息
* type(): 获取对象类型
* isinstance()：获取class的类型
* dir()：获取对象的所有属性和方法
o getattr()
o setattr()
o hasattr()


