#!/usr/bin/python3
"""Contanins the 'canUnlockAll' function"""


def canUnlockAll(boxes):
    """Determines if all the boxes can be opened"""
    if type(boxes) is not list or len(boxes) < 1:
        return False
    for box in boxes:
        if type(box) is not list:
            return False
    key_box = [0]
    attemp = 0
    while attemp != len(boxes):
        for keys in key_box:
            for key in boxes[keys]:
                if key not in key_box and type(key) is int and key > 0:
                    key_box.append(key)
        attemp += 1
    if len(key_box) == len(boxes):
        return True
    else:
        return False


if __name__ == "__main__":
    boxes = [[1], [2], [3], [4], []]
    print(canUnlockAll(boxes))

    boxes = [[1, 4, 6], [2], [0, 4, 1], [5, 6, 2], [3], [4, 1], [6]]
    print(canUnlockAll(boxes))

    boxes = [[1, 4], [2], [0, 4, 1], [3], [], [4, 1], [5, 6]]
    print(canUnlockAll(boxes))
