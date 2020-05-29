def minimize(n,arr,k,moves):
    unsorted=set()
    for i in range(1,n+1):
        arr[i]=int(arr[i])
        if(i!=arr[i]):
            unsorted.add(i)
    ans=int(0)
    while(len(unsorted)!=0):
        if(len(unsorted)==2):
            return -1
        f=int(0)
        for f in unsorted:
            break
        unsorted.remove(f)
        s=arr[f]
        unsorted.remove(s)
        t=arr[arr[f]]
        if(t==f):
            for t in unsorted:
                break
        else:
            unsorted.remove(t)
        arr[f],arr[s]= arr[s],arr[f]
        arr[f],arr[t]=arr[t],arr[f]
        if(arr[f]!=f):
            unsorted.add(f)
        if(arr[s]!=s):
            unsorted.add(s)
        if(arr[t]!=t):
            unsorted.add(t)
        moves.append(f)
        moves.append(s)
        moves.append(t)
        ans+=1
    if(k>=ans):
        return ans
    return -1

t=int(input())
while(t):
    t-=1
    inp=input().split()
    n=int(inp[0])
    k=int(inp[1])
    arr=[0]
    arr2=input().split()
    arr=arr+arr2
    # print(arr)
    moves=[]
    ans=minimize(n,arr,k,moves)
    print(ans)
    if(ans!=-1):
        for i in range(0,len(moves),3):
            print(moves[i],moves[i+1],moves[i+2])



    # for i in range(1,n):
