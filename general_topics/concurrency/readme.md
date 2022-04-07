What is Asynchronous: 

Coroutines are a more generalized form of subroutines. Subroutines are entered at one point and exited at another point. Coroutines can be entered, exited, and resumed at many different points. They can be implemented with the async def statement.

coroutine function : A function which returns a coroutine object. A coroutine function may be defined with the async def statement, and may contain await, async for, and async with keywords. 


A Task A Future-like object that runs a Python coroutine. Not thread-safe.
Tasks are used to schedule coroutines concurrently.
Tasks are used to run coroutines in event loops. If a coroutine awaits on a Future, the Task suspends the execution of the coroutine and waits for the completion of the Future. When the Future is done, the execution of the wrapped coroutine resumes.
When a coroutine is wrapped into a Task with functions like asyncio.create_task() the coroutine is automatically scheduled to run soon:



An Event-Loop
The event loop is the core of every asyncio application. Event loops run asynchronous tasks and callbacks, perform network IO operations, and run subprocesses.
Event loops use cooperative scheduling, an event loop runs one Task at a time. While a Task awaits for the completion of a Future, the event loop runs other Tasks, callbacks, or performs IO operations.




A Future represents an eventual result of an asynchronous operation. Not thread-safe.
Future is an awaitable object. Coroutines can await on Future objects until they either have a result or an exception set, or until they are cancelled.
Future represents an eventual result of an asynchronous operation.
When a Future object is awaited it means that the coroutine will wait until the Future is resolved in some other place.


Awaitable: An object that can be used in an await expression. Can be a coroutine or an object 
with an __await__() --> Must return an iterator. Should be used to implement awaitable objects. For instance, asyncio.Future implements this method to be compatible with the await expression.



### Running an asyncio Program

`asyncio.run(coro, *, debug=False)`

    Execute the coroutine coro and return the result.

    This function runs the passed coroutine, taking care of managing the asyncio event loop and finalizing asynchronous generators.

    This function cannot be called when another asyncio event loop is running in the same thread.
    This function always creates a new event loop and closes it at the end. It should be used as a main entry point for asyncio programs, and should ideally only be called once.

### Creating Tasks

`asyncio.create_task(coro)`

    Wrap the coro coroutine into a Task and schedule its execution. Return the Task object.

### Sleeping

`coroutine asyncio.sleep(delay, result=None, *, loop=None)`

    Block for delay seconds.

    If result is provided, it is returned to the caller when the coroutine completes.

    sleep() always suspends the current task, allowing other tasks to run.

### Running Tasks Concurrently

awaitable asyncio.gather(*aws, loop=None, return_exceptions=False)

    Run awaitable objects in the aws sequence concurrently.

    If any awaitable in aws is a coroutine, it is automatically scheduled as a Task.

    If all awaitables are completed successfully, the result is an aggregate list of returned values. The order of result values corresponds to the order of awaitables in aws.