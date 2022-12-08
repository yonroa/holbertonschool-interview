#!/usr/bin/python3
"""Contanins the 'canUnlockAll' function"""


def canUnlockAll(boxes):
    """Determines if all the boxes can be opened"""
    if isinstance(boxes, list) and all(isinstance(x, list) for x in boxes):
        key_box = [0]
        attemp = 0
        while attemp != len(boxes):
            for keys in key_box:
                for key in boxes[keys]:
                    if key not in key_box and key < len(boxes):
                        key_box.append(key)
            attemp += 1
        if len(key_box) == len(boxes):
            return True
        else:
            return False
    return False


if __name__ == "__main__":
    boxes = [[1], [2], [3], [4], []]
    print(canUnlockAll(boxes))

    boxes = [[1, 4, 6], [2], [0, 4, 1], [5, 6, 2], [3], [4, 1], [6, 7]]
    print(canUnlockAll(boxes))

    boxes = [[1, 4], [2], [0, 4, 1], [3], [], [4, 1], [5, 6]]
    print(canUnlockAll(boxes))
