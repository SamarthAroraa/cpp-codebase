t=int(input())
while(t):
    inp=input()
    n=int(inp[0])
    a=int(inp[-1])
    p=1
    ans=int(0)
    for i in range(1,n+1):
        p=pow(a%1000000007,2*i-1,1000000007)
        a=(a)*(p)
        ans= (ans%1000000007 + p%1000000007)%1000000007
    print(ans)
    t-=1
