import asyncio
import datetime

async def main():
    print('Hello')
    print('World')
    await asyncio.sleep(1)


async def display_date():
    # loop = asyncio.get_running_loop()
    loop = asyncio.get_event_loop()
    print(f'Loop: {loop}')
    t1 = loop.time()
    await asyncio.sleep(1)
    print(f'Loop Time: {loop.time()- t1}')

if __name__ == '__main__':
    asyncio.run(display_date())
