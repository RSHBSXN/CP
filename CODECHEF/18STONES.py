t = int(input())
for i in range(t):
    lst = input().split()
    n = int(lst[0])
    r,c = lst[1].split(',')
    r = int(r[1:])
    c = int(c[:len(c)-1])
    count = n-1 + n-1
    if r == 1 or c == 1 or r == n or c == n:
        count += n-1
    else:
        r -= 1
        c -= 1
        count += min(r,c) + min(r,n-(c+1)) + min(n-(r+1),c) + min(n-(r+1),n-(c+1))
    count = (n*n) - count
    print(count)
    