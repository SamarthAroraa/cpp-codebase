def ans(a,b):
    a=int(a,2)
    b=int(b,2)
    # print(a,b)
    steps=int(0)
    while (b > 0):
        steps+=1
        U = a^b
        V = a & b
        a = U
        b = V << 1
    print(U,V)
    return steps

t=int(input())
k=int(0)

while (k<t):
    a=input()
    b=input()
    print(ans(a,b))
    k+=1
