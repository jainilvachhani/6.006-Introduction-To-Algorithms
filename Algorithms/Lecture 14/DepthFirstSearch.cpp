#include <iostream>
#include <vector>
#include <list>
#include <stack>
using namespace std;

int dfs(vector <list<int>>adjlist, int source, int target, int visited[])
{
	stack <int> dfsq;
	visited[source] =1;
	dfsq.push(source);
	while(!dfsq.empty())
	{
		int u = dfsq.top();
		dfsq.pop();
		for(int v : adjlist[u])
		{
			if(visited[v] == 0)
			{
				visited[v] = 1;
				dfsq.push(v);
				
			}
		}
	}
	if(visited[target] == 1)
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
	vector <list <int>> adjlist(n);
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
	scanf("%d",&source);
	scanf("%d",&target);
	int visited[n];
	for(i=0;i<n;i++)
	{
		visited[i]=0;
	}
	if(dfs(adjlist,source,target,visited))
	{
		printf("Found\n");
	}
	else
	{
		printf("Not Found\n");
	}
	return 0;
}
