import numpy as np
from PIL import Image

def transpose_image(image):
    w, h = image.size
    res = Image.new("RGB", (h, w))

    for y in range(h):
        for x in range(w):
            pixel = image.getpixel((x, y))
            res.putpixel((w - x - 1, y), pixel)
    return res

def main():
    image = Image.open("zoomed.jpeg")
    transposed = transpose_image(image)
    transposed.rotate(90).convert("L").show()
   

if __name__ == "__main__":
    main()