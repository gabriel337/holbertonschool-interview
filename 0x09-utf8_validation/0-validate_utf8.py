#!/usr/bin/python3
""" validUTF8 method """


def validUTF8(data):
    """
    method that determines if a given data set represents a valid
    UTF-8 encoding
    Args:
        data (list): list of ints to check within the data
    Returns:
        True UTF-8 encoding is present within valid data. Else, False.
    """
    b_1 = 1 << 7
    b_2 = 1 << 6
    nbytes = 0
    if not data or len(data) == 0:
        return True
    for num in data:
        bit = 1 << 7
        if nbytes == 0:
            while (bit & num):
                nbytes += 1
                bit = bit >> 1
            if nbytes == 0:
                continue
            if nbytes == 1 or nbytes > 4:
                return False
        else:
            if not (num & b_1 and not (num & b_2)):
                return False
        nbytes -= 1
    if nbytes:
        return False
    else:
        return True
