t=int(input())
temp=t
# t-=1
while(t):
    s=input()
    multiplier=int(1)
    stack=[]
    freq={}
    for m in s:
        if(ord(m)>48 and ord(m)<58):
            multiplier*=int(m)
            # print("mul",multiplier)
            stack.append(int(m))
        elif (m==')'):
            k=stack.pop()
            multiplier=multiplier//k
        elif (m=='('):
            continue
        else:
            if(m in freq.keys()):
                freq[m]+=multiplier
            else:
                freq[m]=multiplier
    if('S' not in freq.keys()):
        freq['S']=0
        # print('s')
    if('N' not in freq.keys()):
        freq['N']=0
        # print('n')

    if('E' not in freq.keys()):
        freq['E']=0
        # print('e')

    if('W' not in freq.keys()):
        freq['W']=0
        # print('w')

    x= freq['S']-freq['N']+1
    y=freq['E']-freq['W']+1
    # x=-1000000000132
    if(x>1000000000):
        x=x%1000000000
    elif(x<=0):
        xpos=abs(x)
        xpos= xpos%1000000000
        x=1000000000-xpos
    if(y>1000000000):
        y=y%1000000000
    elif(y<=0):
        ypos=abs(y)
        ypos= ypos%1000000000
        y=1000000000-ypos



    # for k in freq.keys():
    #     print(k,freq[k])
    ans="Case #"+str(int(temp-t+1))+": "+str(int(y))+" "+str(int(x))
    print(ans)
    t-=1
