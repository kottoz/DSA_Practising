import asyncio
from util import delay  

async def hello_every_second():    
    for i in range(4):        
        await asyncio.sleep(0.5)        
        print("I'm running other code while I'm waiting!")  

async def main():    
    first_delay = asyncio.create_task(delay(3))    
    second_delay = asyncio.create_task(delay(3))    
    hello_every_second_task_obj = asyncio.create_task(hello_every_second())    
    await first_delay    
    await second_delay
    await hello_every_second_task_obj   

asyncio.run(main())