#!/usr/bin/python3
"""Contain a script that reads stdin line by line and computes metrics"""

import sys


if __name__ == "__main__":
    status_code = {
        "200": 0,
        "301": 0,
        "400": 0,
        "401": 0,
        "403": 0,
        "404": 0,
        "405": 0,
        "500": 0,
    }
    counter = 1
    size = 0


    def parse_line(line):
        """Read and grab data"""
        try:
            parse = line.split()
            status = parse[-2]
            if status in status_code.keys():
                status_code[status] += 1
            return int(parse[-1])
        except Exception:
            return 0


    def print_stats():
        """Print the stats"""
        print("File size: {}".format(size))
        for key in sorted(status_code.keys()):
            if status_code[key]:
                print("{}: {}".format(key, status_code[key]))

    try:
        for line in sys.stdin:
            size += parse_line(line)
            if counter % 10 == 0:
                print_stats()
            counter += 1
    except KeyboardInterrupt:
        print_stats()
        raise
    print_stats()
