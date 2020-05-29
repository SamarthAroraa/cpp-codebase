t=int(input())
test=0
while test<t:
	inp=input()
	inp=inp.split()
	a=int(inp[0])
	b=int(inp[1])
	d=int(inp[2])
	e=int(inp[3])
	mx=(1<<60)-1
	k=a^b
	ans= mx^e^d^k
	# ans= ans^axb
	print(ans)
	test+=1