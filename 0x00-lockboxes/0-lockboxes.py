#!/usr/bin/python3
"""
determines if all the boxes can be opened
"""


def canUnlockAll(boxes):
    """Unlock boxes"""
    keys = [0]
    for key in keys:
        for unlocked in boxes[key]:
            if unlocked not in keys and unlocked < len(boxes):
                keys.append(unlocked)

    return len(keys) == len(boxes)
