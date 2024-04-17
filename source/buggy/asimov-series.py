#!/usr/bin/env python3

import sys
import math

def print_help():
    text = '''
Print Isaac Asimov series for calculating decimals of e number.

This program accepts an integer number as argument. Otherwise
this help text will be printed.
'''
    print(text)

arg = sys.argv[1]

try:
    arg = int(arg)
except:
    print_help()
    sys.exit(1)

e = 0
for i in range(0, arg, 2):
    print(i,i+1)
    e =+ i/math.factorial(i + 1)
    print(e)
print(e)
print(math.pow(e, -1))

f=math.factorial
a=0/f(1)+2/f(3)+4/f(5)+6/f(7)
b=1/f(2)-3/f(4)-5/f(6)
print(a)
print(b)
print(math.pow(a, -1))
print(math.pow(b, -1))
