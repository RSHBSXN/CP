def decrypt(num):
    print(num)
    return chr(97 + num)
def solve(A):
    num = ""
    res = ""
    isNum = False
    for i in A:
        if i > '9':
            if isNum:
                res += decrypt(int(num)%26)
                isNum = False
        else:
            if isNum == False:
                isNum = True
            num += i
    if isNum:
        res += decrypt(int(num) %26)
    return res

print(solve(input()))