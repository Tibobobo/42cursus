from collections.abc import Iterable


def ft_filter(function, iterable: Iterable):
    if callable(function) is False:
        return False
    resArray = [element for element in iterable if function(element) is True]
    return iter(resArray)
