#!/usr/bin/env python3

'''
 If a chessboard were to have wheat placed upon each square such that one
grain were placed on the first square, two on the second, four on the third,
and so on (doubling the number of grains on each subsequent square), how many
grains of wheat would be on the chessboard at the finish?


The last value must be 18446744073709551615
'''

x = 1
t = 1

for i in range(64):
    print(i + 1, ': ', x, ', ', t, sep="")
    x *= 2
    t += x
