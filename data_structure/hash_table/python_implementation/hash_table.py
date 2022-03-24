#!/usr/bin/env python3

from dataclasses import dataclass, field, InitVar

"""
    module to operations with prime numbers
"""


def check_prime(number):
    """
    it's not the best solution
    """
    special_non_primes = [0, 1, 2]
    if number in special_non_primes[:2]:
        return 2
    elif number == special_non_primes[-1]:
        return 3

    return all([number % i for i in range(2, number)])


def next_prime(value, factor=1, **kwargs):
    value = factor * value
    first_value_val = value

    while not check_prime(value):
        value += 1 if not ("desc" in kwargs.keys()
                           and kwargs["desc"] is True) else -1

    if value == first_value_val:
        return next_prime(value + 1, **kwargs)
    return value


@dataclass(order=True)
class HashTable:
    ''' 
    Basic Hash Table with open addressing and linear probing
    '''
    size_table: int
    values: list = field(init=False, default_factory=list, repr=False)
    charge_factor: int = field(default=None)
    lim_charge: int = field(default=None)
    __aux_list: list = field(default_factory=list, init=False, repr=False)
    keys: dict = field(default_factory=dict, init=False, repr=False)

    def __post_init__(self):
        self.values = [None]*self.size_table
        self.lim_charge = 0.75 if self.lim_charge is None else self.lim_charge
        self.charge_factor = 1 if self.charge_factor is None else self.charge_factor
        print("Hi")


if __name__ == '__main__':
    ht = HashTable(5)
    print(ht.keys)
