import os
import multiprocessing
import time
def hello_from_process():
    print(f'Hello from process {os.getpid()}!')

if __name__ == '__main__':
    hello_process = multiprocessing.Process(target=hello_from_process)
    hello_process.start()
    # time.sleep(1)
    print(f'Hello from main process {os.getpid()}!')
    hello_process.join()