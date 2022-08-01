#!/usr/bin/python3
"""
determines if all the boxes can be opened
"""


def join(T, R):
    """returns result"""
    result = []
    for e in R:
        result += T[e]
    return result


def canUnlockAll(boxes):
    """Unlock boxes"""
    index = 0
    total = list(set(boxes[0]) | {0})
    added = True
    while added:
        added = False
        for j in join(boxes, total[index:]):
            if j not in total:
                total.append(j)
                index += 1
                added = True

    return len(total) == len(boxes)
