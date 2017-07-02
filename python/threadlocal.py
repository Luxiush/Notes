# threadlocal.py

import threading

connection_ctx = threading.local()

def connect(sessionid, username, password):
	connection_ctx.sessionid = sessionid
	connection_ctx.username = username
	connection_ctx.password = password 
	
	show_connection_info()

	
def show_connection_info():
	print ('Thread %s: sessionid=%s, username=%s, password=%s' % (threading.current_thread().name, connection_ctx.sessionid, connection_ctx.username, connection_ctx.password)) 


t1 = threading.Thread(target=connect, args=('1', 'Alice', 'aaaa'), name='A')	
t2 = threading.Thread(target=connect, args=('2', 'Bob', 'abab'), name='B')	
t3 = threading.Thread(target=connect, args=('3', 'Tom', 'toto'), name='C')	

t1.start()
t2.start()
t3.start()

t1.join()
t2.join()
t3.join()
