#!/usr/bin/python3
"""
Given a pile of coins of different values,
determine the fewest number of coins needed to
meet a given amount total
"""


def makeChange(coins, total):
    """
    Return: number of coins needed to meet total
        - If total is 0 or less, return 0
        - If total cannot be met by any number of coins you have, return -1
        - Coins is a list of the values of the coins in your possession
        - The value of a coin will always be an integer greater than 0
        - You can assume you have an infinite number of each denomination of
        coin in the list
    """
    if total <= 0:
        return 0

    coins.sort(reverse=True)
    sum = 0
    i = 0
    counter = 0
    num_coins = len(coins)
    while sum < total and i < num_coins:
        while coins[i] <= total - sum:
            sum += coins[i]
            counter += 1
            if sum == total:
                return counter
        i += 1
    return -1
