from collections import deque
ROW = 6
COL = 4

class Cell:

	def __init__(self,m: int, n: int):
		self.m = m
		self.n = n

class queueNode:
	def __init__(self,point: Cell, distance: int):
		self.point = point
		self.distance = distance


def checkValid(row: int, col: int):
	return ((row >= 0) and (row < ROW) and (col >= 0) and (col < COL))


rowNum = [1, 0, -1, 1]
colNum = [0, -1, 1, 1]


def bfsLee(mat, src: Cell, dest: Cell):
	
	if mat[src.m][src.n]!=1 or mat[dest.m][dest.n]!=1:
		return -1
	
	visited = [[False for i in range(COL)] for j in range(ROW)]
	 
	visited[src.m][src.n] = True
	
	q = deque()
	
	s = queueNode(src,0)
	q.append(s)
	 
	while q:

		curr = q.popleft()
		
		point = curr.point
		if point.m == dest.m and point.n == dest.n:
			return curr.distance
		
		for i in range(4):
			row = point.m + rowNum[i]
			col = point.n + colNum[i]
			

			if (checkValid(row,col) and
			mat[row][col] == 1 and
				not visited[row][col]):
				visited[row][col] = True
				Adjcell = queueNode(Cell(row,col),curr.distance+1)
				q.append(Adjcell)
	 
	return -1

mat = [
    [ 1, 0, 1, 1, 1, 1 ],
	[ 1, 0, 1, 0, 1, 0 ], 
	[ 1, 1, 1, 0, 1, 1 ], 
	[ 0, 0, 0, 0, 1, 1 ],
    ]

source = Cell(0,0)
dest = Cell(1,2)
	
distance = bfsLee(mat,source,dest)
	
if distance!=-1:
		print("Length of the Shortest Path is",distance)
else:
		print("Shortest Path doesn't exist")