# include <iostream>
# include <algorithm>
# include <list>
# include <vector>
# define sizeX 40001
# define sizeY 3
using namespace std;

typedef list<int> intList;
typedef struct Node
{
	int x;
	int y;
	int z;
}Node;

bool compare1(Node, Node);
bool compare2(Node, Node);
int findParent(int);

int parent[sizeX];
Node graph[sizeX];

int main()
{
	// Input
	int idx = 0, dotNum = 0, minIdx = 40001;
	long long int sum = 0;

	while (cin >> graph[idx].x >> graph[idx].y >> graph[idx].z)
	{
		// get the max dot no.(dotNum) and min dot no.(minIdx)
		if (graph[idx].y > dotNum)
			dotNum = graph[idx].y;
		if (graph[idx].x > dotNum)
			dotNum = graph[idx].x;
		if (graph[idx].x < minIdx)
			minIdx = graph[idx].x;
		else if (graph[idx].y < minIdx)
			minIdx = graph[idx].y;
		idx++;
	}
	dotNum++; // because dot start at 0

	// declare and sort
	int** ansPath = new int* [dotNum - 1], * connectYN = new int[dotNum];
	for (int i = 0; i < (dotNum - 1); i++)
		ansPath[i] = new int[sizeY];
	for (int i = 0; i < dotNum; i++)
		parent[i] = i, connectYN[i] = 1;
	sort(graph, graph + idx, compare2);

	/*
	for (int i = 0; i < idx; i++)
		cout << graph[i].x << " " << graph[i].y << " " << graph[i].z << endl;*/

	// Add element to STL Adjacency linked list
	intList* stlListArray = new intList[dotNum];
	for (int i = 0; i < idx; i++)
	{
		int node1 = graph[i].x, node2 = graph[i].y;
		stlListArray[node1].push_back(node2);
		stlListArray[node2].push_back(node1);
	}

	// Sort stlListArray
	for (int i = 0; i < dotNum; i++)
		stlListArray[i].sort();

	// Union find
	int counter = 0;
	for (int i = 0; i < idx && counter < dotNum; i++)
	{
		int a, b;
		a = findParent(graph[i].x);
		b = findParent(graph[i].y);
		if (a != b)
		{
			if (connectYN[a] > connectYN[b])
				parent[b] = a, connectYN[a] += connectYN[b];
			else
				parent[a] = b, connectYN[b] += connectYN[a];
			// get ansPath and sum
			ansPath[counter][0] = graph[i].x;
			ansPath[counter][1] = graph[i].y;
			ansPath[counter][2] = graph[i].z;
			sum += graph[i].z;
			counter++;
		}
	}

	// Print adjacency list
	cout << "Adjacency list:" << endl;
	for (int i = minIdx; i < dotNum; i++)
	{
		cout << i << ": ";
		int temp = -1;
		while (!stlListArray[i].empty())
		{
			if (stlListArray[i].front() == temp)
			{
				stlListArray[i].pop_front();
				continue;
			}
			temp = stlListArray[i].front();
			cout << stlListArray[i].front() << " -> ";
			stlListArray[i].pop_front();
		}
		cout << "end" << endl;
	}
	cout << endl;

	// Print minimum spanning tree
	cout << "minimum spanning tree:" << endl;
	for (int i = 0; i < dotNum - (1 + minIdx); i++)
		cout << i + 1 << ": " << "<" << ansPath[i][0] << "," << ansPath[i][1] << ">" << endl;
	cout << endl << "The cost of minimum spanning tree: " << sum << endl;

	delete[]ansPath;
	delete[]connectYN;
	delete[]stlListArray;
	return 0;
}

bool compare1(Node a, Node b)
{
	return a.x < b.x;
}

bool compare2(Node a, Node b)
{
	return a.z < b.z;
}

int findParent(int a)
{
	while (a != parent[a])
		a = parent[a];
	return a;
}
