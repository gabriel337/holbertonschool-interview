#!/usr/bin/python3
"""
In a text file, there is a single character H.
Your text editor can execute only two operations in this file:
Copy All and Paste. Given a number n, write a method that calculates
the fewest number of operations needed to result in exactly n H characters
in the file.
Returns:
    int: minimum number of operations needed
"""


def minOperations(n):
    """Prototype: minOperations
    Args:
        n (int): Number of H characters to get to
    Returns:
        int: Min num of operations needed to return n number of the letter H
    """
    buf = n
    div = 2
    count = 0
    if type(n) is not int or n < 2:
        return 0
    while buf > 1:
        if buf % div == 0:
            buf /= div
            count += div
        else:
            div += 1
    return count