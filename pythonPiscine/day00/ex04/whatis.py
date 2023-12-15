import sys

try:
    assert len(sys.argv) == 2
except AssertionError:
    print("AssertionError: Wrong nuber of args")
    exit(1)
try:
    assert sys.argv[1].lstrip("-").isnumeric()
except AssertionError:
    print("AssertionError: Wrong type of argument")
    exit(1)
number = int(sys.argv[1])
if (number % 2 == 0):
    print("I'm even")
else:
    print("I'm odd")
