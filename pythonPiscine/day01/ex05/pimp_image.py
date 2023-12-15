import numpy as np
from PIL import Image

def ft_invert(array):
    res = 255 - array
    Image.fromarray(res).show()

def ft_red(array):
    for elem in array:
        for elem2 in elem:
            elem2[1] = 0
            elem2[2] = 0
    Image.fromarray(array).show()



def main():
    image = Image.open("landscape.jpg")
    # ft_invert(np.array(image))
    ft_red(np.array(image))
    # ft_green(np.array(image))
    # ft_blue(np.array(image))
    # ft_grey(np.array(image))

if __name__ == "__main__":
    main()