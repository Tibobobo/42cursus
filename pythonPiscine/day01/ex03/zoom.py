from load_image import ft_load
import numpy as np
from PIL import Image


def main():
    img = ft_load("animal.jpeg")
    print(img)
    image = Image.open("animal.jpeg")
    zoomed = image.crop((450,100,850,500))
    zoomed.save("zoomed.jpeg")
   

if __name__ == "__main__":
    main()