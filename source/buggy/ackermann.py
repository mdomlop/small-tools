#!/usr/bin/env python

# Implements the Ackermann function to obtain big numbers. Too big even for
# our universe.

import sys
sys.setrecursionlimit(1000000000)


def A(m, n):
    if m == 0:
        return(n + 1)
    if m > 0 and n == 0:
        return(A(m - 1, 1))
    if m > 0 and n > 0:
        return(A(m - 1, A(m, n - 1)))


def badsyntax():
    print('Invalid arguments. They must be 2 numbers >= 0')
    exit(1)

if len(sys.argv) == 3:
    n1 = sys.argv[1]
    n2 = sys.argv[2]
else:
    badsyntax()

if n1.isdigit() and int(n1) >= 0 and n2.isdigit() and int(n2) >= 0:
    print(A(int(n1), int(n2)))
else:
    badsyntax()
