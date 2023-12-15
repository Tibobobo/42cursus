import sys

MORSE_CODE_DICT = { ' ': '/', 'A':'.-', 'B':'-...',
                    'C':'-.-.', 'D':'-..', 'E':'.',
                    'F':'..-.', 'G':'--.', 'H':'....',
                    'I':'..', 'J':'.---', 'K':'-.-',
                    'L':'.-..', 'M':'--', 'N':'-.',
                    'O':'---', 'P':'.--.', 'Q':'--.-',
                    'R':'.-.', 'S':'...', 'T':'-',
                    'U':'..-', 'V':'...-', 'W':'.--',
                    'X':'-..-', 'Y':'-.--', 'Z':'--..',
                    '1':'.----', '2':'..---', '3':'...--',
                    '4':'....-', '5':'.....', '6':'-....',
                    '7':'--...', '8':'---..', '9':'----.',
                    '0':'-----', ', ':'--..--', '.':'.-.-.-',
                    '?':'..--..', '/':'-..-.', '-':'-....-',
                    '(':'-.--.', ')':'-.--.-'}

def main():
    try:
        assert len(sys.argv) == 2
        assert all(c.isalpha() or c.isspace() or c.isnumeric() for c in sys.argv[1])
    except AssertionError:
        print("Arg Error")
        exit(1)
    str = sys.argv[1].upper()
    encoded = ""
    for index, c in enumerate(str):
        if c in MORSE_CODE_DICT:
            encoded += MORSE_CODE_DICT[c]
            if index != len(str) - 1:
                encoded += " "
    print(encoded)

if __name__ == "__main__":
    main()