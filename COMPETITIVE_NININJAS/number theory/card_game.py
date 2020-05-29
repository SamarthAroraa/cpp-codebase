inp=input()
inp=inp.split()
n=int(inp[0])
k=int(inp[1])
arr=input()
arr=arr.split()
prod=[]
cumulative=int(1)
for i in range(n):
    cumulative*=int(arr[i])
    prod.append(cumulative)
sum=int(0)
for i in range(n):
    if(prod[i]%k==0):
        sum+=1
    for j in range(0,i):
        if((prod[i]//prod[j])%k==0):
            sum+=1
        else:
            break
print(sum)
