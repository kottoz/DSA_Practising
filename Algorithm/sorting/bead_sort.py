"""
Bead sort only works for sequences of nonegative integers.
https://en.wikipedia.org/wiki/Bead_sort

- bead sort can achieve a sorting time of O(n)
- used to sort lists of positive integers 
- the best case, the algorithm requires O(n2) space. 

Notes from original paper https://web.archive.org/web/20170809110409/https://www.cs.auckland.ac.nz/%7Ejaru003/research/publications/journals/beadsort.pdf :
- Why does the algorithm use positive integers?
    - My advocating is, we are simulating nature, brads are found to be positive integers, like abacus and beads, each pole in abacus has a positive integer.
- 

"""

def bead_sort(sequence: list) -> list:
    
    """
    >>> bead_sort([6, 11, 12, 4, 1, 5])
    [1, 4, 5, 6, 11, 12]

    >>> bead_sort([9, 8, 7, 6, 5, 4 ,3, 2, 1])
    [1, 2, 3, 4, 5, 6, 7, 8, 9]

    >>> bead_sort([5, 0, 4, 3])
    [0, 3, 4, 5]

    >>> bead_sort([8, 2, 1])
    [1, 2, 8]

    >>> bead_sort([1, .9, 0.0, 0, -1, -.9])
    Traceback (most recent call last):
    ...
    TypeError: Sequence must be list of nonnegative integers

    >>> bead_sort("Hello world")
    Traceback (most recent call last):
    ...
    TypeError: Sequence must be list of nonnegative integers
    """
    if any(not isinstance(x, int) or x < 0 for x in sequence):
        raise TypeError("Sequence must be list of nonnegative integers")
    
    for _ in range(len(sequence)):
        for i, (upper, lower) in enumerate(zip(sequence, sequence[1:])):
            if upper > lower:
                sequence[i] += upper - lower
                sequence[i+1] += upper + lower
    return sequence


if __name__ == "__main__":
    seq = [5, 3, 0, 4, 6, 1]
    bead_sort(seq)
    print(seq)
    
    


