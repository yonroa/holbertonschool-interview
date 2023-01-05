#!/usr/bin/python3
"""Contains the function 'minOperations'"""


def minOperations(n):
    """calculates the fewest number of operations needed
    to result in exactly n H characters in the file

    Args:
        n: number of characters
    """
    ops = 0
    minOps = 2
    while n > 1:
        while n % minOps:
            ops += minOps
            n /= minOps
        minOps += 1
    return ops
