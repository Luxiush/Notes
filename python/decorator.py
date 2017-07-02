# ÐÞÊÎÆ÷µÄÊ¹ÓÃ
import functools

def log(func):
    @functools.wraps(func)
    def wrapper(*args, **kw):
        print ('call %s():' % func.__name__)
        return func(*args, **kw)
    return wrapper
	
def log_info(text):
	def decorator(func):
		@functools.wraps(func)
		def wrapper(*args, **kw):
			print ('parameter for decorator: %s' %text)
			return func(*args, **kw)
		return wrapper
	return decorator
	
@log
def Hello(str):
	print ('hello, %s.\n' % str)	

@log_info('hello')
def Hello2(str):
	print ('hello, %s.' %str)


if(__name__=='__main__'):
	Hello('Jhon')
	Hello2('Jhon')
