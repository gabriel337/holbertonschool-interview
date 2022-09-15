#!/usr/bin/python3
""" script that reads stdin line by line and computes metrics """

import sys

CODES = {
    '200': 0,
    '301': 0,
    '400': 0,
    '401': 0,
    '403': 0,
    '404': 0,
    '405': 0,
    '500': 0
}

total_size = 0
lines = 0
try:
    for line in sys.stdin:
        on_line = line.split(" ")
        if len(on_line) > 2:
            status = on_line[-2]
            current_size = int(on_line[-1])
            if status in CODES:
                CODES[status] += 1
            total_size += current_size
            lines += 1
            if lines == 10:
                print("File size: {:d}".format(total_size))
                for key, value in sorted(CODES.items()):
                    if value != 0:
                        print("{}: {:d}".format(key, value))
                    lines = 0
except KeyboardInterrupt:
    pass
finally:
    print("File size: {:d}".format(total_size))
    for key, value in sorted(CODES.items()):
        if value != 0:
            print("{}: {:d}".format(key, value))
