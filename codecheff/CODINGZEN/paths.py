
# Python code to find number of unique paths in a
# matrix with obstacles.

def uniquePathsWithObstacles(A):

	# create a 2D-matrix and initializing with value 0
	paths = [[0]*len(A[0]) for i in A]

	# initializing the left corner if no obstacle there
	if A[0][0] == 0:
		paths[0][0] = 1

	# initializing first column of the 2D matrix
	for i in range(1, len(A)):
		if A[i][0] == 0: # If not obstacle
			paths[i][0] = paths[i-1][0]

	# initializing first row of the 2D matrix
	for j in range(1, len(A[0])):
		if A[0][j] == 0: # If not obstacle
			paths[0][j] = paths[0][j-1]

	for i in range(1, len(A)):
		for j in range(1, len(A[0])):

			# If current cell is not obstacle
			if A[i][j] == 0:
				paths[i][j] = paths[i-1][j] + paths[i][j-1]

		# returning the corner value of the matrix
	return paths[-1][-1]


# Driver Code
t=int(input())
k=t
while(k):
	inp=input()
	dimen=inp.split()
	inp=input()
	pothole=inp.split()
	cols=int(dimen[1])+1
	rows=int(dimen[0])+1
	A = [[0 for i in range(cols)] for j in range(rows)]
	#A=[[0,0,0],[0,1,0],[0,0,0]]
	pot_x=int(pothole[0])
	pot_y=int(pothole[1])
	A[pot_x][pot_y]=1
	k-=1

	print(uniquePathsWithObstacles(A))
	# print(A)
