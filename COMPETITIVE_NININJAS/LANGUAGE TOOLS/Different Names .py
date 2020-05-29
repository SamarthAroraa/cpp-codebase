def differentNames(names=[]):
    dict={}
    for n in names:
        if(n not in dict):
            dict[n]=1
        else:
            dict[n]+=1


    return dict

# Main
names=input().strip().split()
m=differentNames(names)
p=False
if m:
    for name in m:
        if(m[name]>1):
            print(name, m[name])
            p=True
if p==False:
    print(-1)
