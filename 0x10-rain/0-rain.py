#!/usr/bin/python3
"""This module contains the function 'rain'"""


def rain(walls):
    """
    calculate how many square units of water
    will be retained after it rains
    """
    squares = 0
    left = False
    right = False
    for i in range(len(walls)):
        if not left and walls[i] != 0:
            left = walls[i]
            iLeft = i
        if left != walls[i] and walls[i] != 0:
            right = walls[i]
            iRight = i
        if left and right and left != right:
            altura = min(left, right)
            base = (iRight - iLeft) - 1
            squares += (base * altura)
            left = right
            iLeft = iRight
    return squares
