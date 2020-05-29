onum=input()

i=int(0)
for k in onum:
	if(onum[0]=='9'):
		continue
	k=int(k)
	temp=9-k
	dupli=onum[0:i]+str(temp)+onum[i+1:]
	
	dupli=int(dupli)
	onum=int(onum)
	if(dupli<onum):
		onum=dupli
	i+=1
	onum=str(onum)
print(onum)
