#!/usr/bin/python3
def islower(c):
    return ord('a') <= ord(c) <= ord('z')

result1 = islower('a')
result2 = islower('Z')

print(result1)  # Should print True
print(result2)  # Should print False

