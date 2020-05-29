t=int(input())
joji=int(0)
while(joji<t):
    n=int(input())
    pq=input()
    pq=pq.split()
    q=int(pq[-1])
    p=int(pq[0])
    k=input()
    k=k.split()
    a=input()
    a=a.split()
    s=input()
    s=s.split()
    bin=input()
    kf=int(0)
    kd=int(0)
    af=int(0)
    ad=int(0)
    for i in range(n):
        sum= int(k[i])+int(a[i])
        if(sum==int(s[i])):
            if(bin[i]=='0'):
                kf+=int(k[i])
                af+=int(a[i])
            else:
                kd+=int(k[i])
                ad+=int(a[i])
    if(p*kf+q*af<p*kd+q*ad):
        print("DustinKiller")
    elif(p*kf+q*af>p*kd+q*ad):
        print("Frost")


    joji+=1
