import sys


def main():
    try:
        assert len(sys.argv) < 3
    except AssertionError:
        print("Too many arguments")
        exit(1)
    if len(sys.argv) == 2:
        str = sys.argv[1]
    else:
        str = input("What is the text to count?\n")
    print("The text contains {} characters:".format(len(str)))
    print("{} upper letters".format(sum(1 for c in str if c.isupper())))
    print("{} lower letters".format(sum(1 for c in str if c.islower())))
    print("{} punctuation marks".format
            (sum(1 for c in str if (c.isupper() is False
            and c.islower() is False and c.isspace()
            is False and c.isdigit() is False))))
    print("{} spaces".format(sum(1 for c in str if c.isspace())))
    print("{} digits".format(sum(1 for c in str if c.isdigit())))


if __name__ == "__main__":
    main()
