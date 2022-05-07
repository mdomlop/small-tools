#!/usr/bin/env python

# Shows Collatz conjecture results.

# Prints the number of steps to reach number 1 as result, meaning that the
# conjecture works for the given number. Otherwise if a result were yet reached
# this will mean that the Collatz conjecture fails, and you can reclaim your
# award.

# Good luck!

import sys


def collatz(x):
    a = []
    steps = 0
    x = int(x)

    while True:
        a.append(x)
        if x % 2:  # odd
            x = x * 3 + 1
        else:  # even
            x /= 2
        x = int(x)

        if x in a:  # Collatz fails!
            print('You win:', x)
            break

        print(a[-1])

        if (x == 1):  # Collatz works!!
            print(1)
            break
    steps += 1


n = sys.argv[1]

if n.isdigit() and int(n) > 0:
    collatz(int(n))
else:
    print('ERROR: The argument must be any natural number.')
