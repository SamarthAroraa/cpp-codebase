def subarraySum( nums,k):
        preSum = 0
        k=int(k)
        preSum_dict = {0:1}
        res = 0
        for n in nums:
            preSum += n
            res += preSum_dict.get(preSum-k, 0)
            preSum_dict[preSum] = preSum_dict.get(preSum, 0) + 1
        return int(res)
t=int(input())
k=int(0)
while(k<t):
    n=int(input())
    arr=input()
    arr=arr.split()
    pow=[]
    for m in arr:
        m=int(m)
        count=int(0)
        while(m%2==0 and m!=0):
            count+=1
            m/=2
        pow.append(count)
    total=n*(n+1)/2
    print(int(total-subarraySum(pow,1)))

    k+=1
