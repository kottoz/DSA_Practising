import asyncio 
from util import delay

async def main():    
    sleep_for_three = asyncio.create_task(delay(3))    
    sleep_for_three_2 = asyncio.create_task(delay(5))    
    sleep_for_three_3 = asyncio.create_task(delay(0.5))    



    print(type(sleep_for_three))

    result = await sleep_for_three    
    result = await sleep_for_three_2    
    result = await sleep_for_three_3    

    print(result) 

asyncio.run(main())