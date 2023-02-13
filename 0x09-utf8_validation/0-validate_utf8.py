#!/usr/bin/python3
"""Containt the method 'validUTF8'"""


def validUTF8(data):
    """Determines if a given data set represents a valid UTF-8 encoding"""
    num_bytes = 0
    for num in data:
        binary_num = format(num, '#010b')[-8:]
        if num_bytes == 0:
            for binary in binary_num:
                if binary == '0':
                    break
                num_bytes += 1
            if num_bytes == 0:
                continue
            if num_bytes == 1 or num_bytes > 4:
                return False
        else:
            if not (binary_num[0] == '1' and binary_num[1] == '0'):
                return False
        num_bytes -= 1
    return True
