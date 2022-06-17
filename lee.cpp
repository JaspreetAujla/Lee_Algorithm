#include <bits/stdc++.h>
using namespace std;
#define ROW 5
#define COL 5


struct Cell
{
	int x;
	int y;
};

struct queueNode
{
	Cell point;
	int distance;
};

bool checkValid(int row, int col)
{
	return ((row >= 0) && (row < ROW) &&	(col >= 0) && (col < COL));
}

int rowNum[] = {-1, 0, 0, 1};
int colNum[] = {0, -1, 1, 0};

int bfsLee(int mat[][COL], Cell src, Cell dest)
{
	if (!mat[src.x][src.y] || !mat[dest.x][dest.y])
		return -1;

	bool visited[ROW][COL];
	memset(visited, false, sizeof visited);
	
	visited[src.x][src.y] = true;

	queue<queueNode> q;
	
	queueNode s = {src, 0};
	q.push(s); 

	while (!q.empty())
	{
		queueNode curr = q.front();
		Cell point = curr.point;

		if (point.x == dest.x && point.y == dest.y)
			return curr.distance;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int row = point.x + rowNum[i];
			int col = point.y + colNum[i];
			
			if (checkValid(row, col) && mat[row][col] && 
			!visited[row][col])
			{
				
				visited[row][col] = true;
				queueNode Adjcell = { {row, col},curr.distance + 1 };
				q.push(Adjcell);
			}
		}
	}

	return -1;
}

int main()
{
	int mat[ROW][COL] =
	{
		{ 1, 0, 1, 1, 0 },
		{ 1, 1, 1, 0, 1 },
		{ 0, 1, 0, 1, 0 },
		{ 0, 0, 0, 0, 1 },
		{ 1, 1, 1, 1, 0 }};

	Cell source = {0, 0};
	Cell dest = {1, 1};

	int distance = bfsLee(mat, source, dest);

	if (distance != -1)
		cout<< "Length of the Shortest Path is "<<distance ;
	else
		cout<< "Shortest Path doesn't exist";

	return 0;
}
