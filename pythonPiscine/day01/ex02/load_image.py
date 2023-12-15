from PIL import Image
import numpy

def ft_load(path: str):
    img = Image.open(path)
    print("The shape of image is: {}".format(img.size))
    data = list(img.getdata())
    data2 = numpy.array(data)
    img.close()
    return data2