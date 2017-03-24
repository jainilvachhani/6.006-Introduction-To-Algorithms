#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;

int bfs(vector <list<int>> adjlist, int target, int source, int visited[], int distance[])
{
	distance[source] = 0;
	visited[source] = 1;
	queue <int> bfsq;
	bfsq.push(source);
	while(!bfsq.empty())
	{
		int u = bfsq.front();
		bfsq.pop();
		for(int v : adjlist[u])
		{
			if(visited[v]==-1)
			{
				visited[v] = 1;
				distance[v] = distance[u] + 1;
				bfsq.push(v);
			}
		}
	}
	if(distance[target]!=-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main() {
	int n,m;
	scanf("%d",&n);
	scanf("%d",&m);
	vector <list<int>> adjlist(n);
	int i;
	for(i=0;i<m;i++)
	{
		int a,b;
		scanf("%d",&a);
		scanf("%d",&b);
		adjlist[a].push_back(b);
		adjlist[b].push_back(a);
	}
	int target,source;
	scanf("%d",&target);
	scanf("%d",&source);
	int visited[n];
	for(i=0;i<n;i++)
	{
		visited[i] = 0;
	}
	int distance[n];
	for(i=0;i<n;i++)
	{
		distance[i] = -1;
	}
	if(bfs(adjlist, source, target,visited, distance))
	{
		printf("Found\n");
	}
	else
	{
		printf("Not Found\n");
	}
	return 0;
}
