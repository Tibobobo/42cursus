def slice_me(family: list, start: int, end: int) -> list:
    it = iter(family)
    the_len = len(next(it))
    if not all(len(l) == the_len for l in it):
        raise ValueError("Not all lists have same length")
    print("My shape is : ({}, {})".format(len(family), the_len))
    slice_object = slice(start, end)
    print ("My new shape is : ({}, {})".format(len(family[slice_object]), the_len))
    return family[slice_object]
