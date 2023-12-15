from PIL import Image
import numpy as np

def ft_load(path: str):
    img = Image.open(path)
    return np.array(img)