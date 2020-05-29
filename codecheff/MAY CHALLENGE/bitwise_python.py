def res(x, y):
    z = x | y
    return z


t = int(input())
while(t):
    t -= 1

    inp = input().split()
    print(res(int(inp[0]), int(inp[1])))
