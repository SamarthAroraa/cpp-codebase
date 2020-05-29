def compute(n,k):
    x=int(k/2)
    ans=pow(n+x,2)+x
    return ans
t=int(input())
while(t):
    inp=input().split()
    n=int(inp[0])
    k=int(inp[1])
    if(k%2==0):
        ans=compute(n,k-1)
        ans+=2*n

    else:
        ans=compute(n,k)
    print(ans%1000000007)

    t-=1
