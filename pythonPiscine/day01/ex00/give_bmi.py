
def give_bmi(height: list[int | float], weight: list[int | float]) -> list[int | float]:
    try:
        assert len(height) == len(weight)
        assert all([isinstance(item, int | float) for item in height])
        assert all([isinstance(item, int | float) for item in weight])

    except AssertionError:
        return False
    result = []
    for index, x in enumerate(weight):
        result.append(x / (height[index] ** 2))
    return result

    

def apply_limit(bmi: list[int | float], limit: int) -> list[bool]:
    try:
        assert all([isinstance(item, int | float) for item in bmi])
    except AssertionError:
        return False
    result = []
    for x in bmi:
        if x > limit:
            result.append(True)
        else:
            result.append(False)
    return result