"""
Python program for Bitonic Sort.
Notes:

- bitonic works only when size of input is a power of 2 (4, 8, 16, 32, ...)
- bitonic is a series of numbers that first increasing, and then decreasing.
- Increasing series is also bitonic, as the decrerasing part is embty, Decreasing also.
- 

Bitonic Algorthim
- Breakdown list into bitonic sebsequences.(Bitonic sort)
- Combine then into larger bitonic sequences.(Bitonic merge)

Worst-case performance	O ( log 2 ⁡ ( n ) )  parallel time
Best-case performance	O ( log 2 ⁡ ( n ) ) parallel time
Average performance	O ( log 2 ⁡ ( n ) )  parallel time
Worst-case space complexity	O ( n log 2 ⁡ ( n ) )  non-parallel  
"""

from typing import List

#compare and swap


def comp_and_swap(array: List[int], index1: int, index2: int, direction: int):
    """
        Compare the value at given index1 and index2 of the array and swap them as per
        the given direction.
        The parameter direction indicates the sorting direction, ASCENDING(1) order DESCENDING(0);
        if (a[i] > a[j]) agrees with the direction, then a[i] and a[j] are 
        interchanged.
        >>> arr = [12, 42, -21, 1]
        >>> comp_and_swap(arr, 1, 2, 1)
        >>> print(arr)
        [12, -21, 42, 1]

        >>> comp_and_swap(arr, 1, 2, 0)
        >>> print(arr)
        [12, 42, -21, 1]

        >>> comp_and_swap(arr, 0, 3, 1)
        >>> print(arr)
        [1, 42, -21, 12]

        >>> comp_and_swap(arr, 0, 3, 0)
        >>> print(arr)
        [12, 42, -21, 1]
    """
    if (direction == 1 and array[index1] > array[index2]) or (
        direction == 0 and array[index1] < array[index2]
    ):
        array[index1], array[index2] = array[index2], array[index1]

# bitonic merge


def bitonic_merge(array: List[int], low: int, length: int, direction: int):
    """
        It recursively sorts a bitonic sequence in ascending order, if direction = 1, and in
        descending if direction = 0.
        The sequence to be sorted starts at index position low, the parameter length is the
        number of elements to be sorted.

        >>> arr = [12, 42, -21, 1]
        >>> bitonic_merge(arr, 0, 4, 1)
        >>> print(arr)
        [-21, 1, 12, 42]

        >>> bitonic_merge(arr, 0, 4, 0)
        >>> print(arr)
        [42, 12, 1, -21]
    """


# bitonic sort
