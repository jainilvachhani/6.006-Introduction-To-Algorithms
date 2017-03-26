#include <iostream>
#include <vector>
#include <list>
#include <stack>
using namespace std;

void topologicalSort(vector <list<int>>adjlist, int source,int visited[], int n)
{
	stack <int> dfsq;
	visited[source] =1;
	dfsq.push(source);
	
	printf("%d ",source);
	while(!dfsq.empty())
	{
		int u = dfsq.top();
		dfsq.pop();
		for(int v : adjlist[u])
		{
			if(visited[v] == 0)
			{
				dfsq.push(v);
				visited[v] = 1;
				printf("%d ",v);
				
			}
		}
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
	int visited[n];
	for(i=0;i<n;i++)
	{
		visited[i]=0;
	}
	topologicalSort(adjlist,source,visited,n);
	return 0;
}
