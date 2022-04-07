import asyncio
from util import delay

async def main():
    long_task = asyncio.create_task(delay(3))

    elapsed_time = 0

    while not long_task.done():
        print('waiting for long task to finish')
        await asyncio.sleep(1)
        elapsed_time += 1
        if elapsed_time == 5:
            print('cancelling long task')
            long_task.cancel()
    try:
        await long_task
    except asyncio.CancelledError:
        print('long task was cancelled')

asyncio.run(main())