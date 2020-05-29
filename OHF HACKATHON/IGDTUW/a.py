inp =input().split()
n=int(inp[0])
l=int(inp[1])
plates=input().split()
for i in range(len(plates)):
    plates[i]=int(plates[i])

colored=[]
term=[]
for i in range(1,n+1):
    if(i in plates):
        colored.append(1);
    else:
        colored.append(0);
print(colored)
nodes=[]
for i in range(1,n+1):
    j=i
    if(colored[i]==0):
        if(i!=1):
            if(colored[i-1]==1):
                while(j<=n):
                    if(colored[j]==1):
                        nodes.append(j-1)
                        term.append('2')
                        i=j
                        break
                    elif(j==n):
                        nodes.append(j-i+1)
                        term.append('1')
                j+=1
        else:
            while(j<=n):
                if(colored[j]==1):
                    nodes.append(j-i)
                    term.append('1')
                    i=j
                    break
                elif(j==n):
                    nodes.append(j-i+1)
                    term.append('1')
            j+=1


    # if(colored[i]==0):
    #     if(i!=1):
    #         if(colored[i-1]==1):
    #             while(j<=n):
    #                 if(colored[j]==1):
    #             		nodes.append(j-i)
    #             		term.append('2')
    #             		i=j
    #             		break
    #                 elif(j==n):
    #                     nodes.append(j-i+1)
    #                     term.append('1');
    #                     	# // cerr<<"2";
    #                 j+=1
    #
    #                 else:
    #                 while(j<=n):
    #                 		if(colored[j]):
    #                 			nodes.append(j-i)
    #                 			i=j
    #                 			term.append('1')
    #                 			break
    #                 		elif(j==n):
    #                 			nodes.append(j-i+1)
    #                 			term.append('1')
    #
    #
    #                 j++;

print(nodes)
print(term)
