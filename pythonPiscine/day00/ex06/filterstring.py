from ft_filter import ft_filter
import sys

def isLongerThanN(word: str, n: int):
    if len(word) > n:
        return True
    else:
        return False

def main():
    try:
        assert len(sys.argv) == 3
        assert sys.argv[2].lstrip("-").isnumeric()
    except AssertionError:
        print("Arg Error")
        exit(1)
    split = sys.argv[1].split()
    num = int(sys.argv[2])
    iter = ft_filter(lambda x: isLongerThanN(x, num), split)
    print(list(iter))


if __name__ == "__main__":
    main()