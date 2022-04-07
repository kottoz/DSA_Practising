import threading  
def hello_from_thread():    
    print(f'Hello from thread {threading.current_thread()}!')  

hello_thread = threading.Thread(target=hello_from_thread)
hello_thread.start() 
total_threads = threading.active_count()
thread_name = threading.current_thread().name

print(f'Python is currently running {total_threads} thread(s)')
print(f'The current thread is {thread_name}')

hello_thread.join()                                                     # Wait for the thread to finish - join will cause the program to pause until the thread we started completed.
