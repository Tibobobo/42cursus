def NULL_not_found(object: any) -> int:
    if (object == None):
        print("Nothing: None", type(object))
    elif (type(object) is float and object != object):
        print("Cheese: nan", type(object))
    elif (object == 0 and type(object) is int):
        print("Zero: 0", type(object))
    elif (object == False and type(object) is bool):
        print("Fake: False", type(object))
    elif (object == ''):
        print("TOTO")
    else:
        print("Type not Found")
        return (1)
    return (0)