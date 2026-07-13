def discount_applies(age: int) -> bool:
    if 18 > age:
        return True
    elif 18 > age or 65 <= age:
        return True
    
    return False



# don't modify this code below this line
print(discount_applies(17))
print(discount_applies(18))
print(discount_applies(40))
print(discount_applies(65))
print(discount_applies(70))
