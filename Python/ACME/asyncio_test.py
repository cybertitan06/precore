import asyncio

async def func1():
    print('one')
    await asyncio.sleep(5)
    await func2()
    print('four')
    await asyncio.sleep(1)

async def func2():
    print('two')
    await asyncio.sleep(1)
    print('three')
    await asyncio.sleep(3)
    
asyncio.run(func1())