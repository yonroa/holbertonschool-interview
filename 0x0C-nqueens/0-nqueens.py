#!/usr/bin/python3
"""This module contains an script to solve the problem of N Queens"""


def n_queens(n):
    solutions = []
    board = [-1] * n

    def is_valid(row, col):
        for i in range(row):
            if board[i] == col or \
                    row - i == abs(col - board[i]):
                return False
        return True

    def backtrack(row):
        if row == n:
            solutions.append([[i, board[i]] for i in range(n)])
        else:
            for col in range(n):
                if is_valid(row, col):
                    board[row] = col
                    backtrack(row + 1)

    backtrack(0)
    for solution in solutions:
        print(solution)


if __name__ == '__main__':
    import sys
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        exit(1)
    N = sys.argv[1]
    try:
        N = int(N)
    except Exception:
        print("N must be a number")
        exit(1)
    if N < 4:
        print("N must be at least 4")
        exit(1)
    n_queens(N)
