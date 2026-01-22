#include <bits/stdc++.h>
using namespace std;

void print(vector<int> adjList[], int n)
{
  vector<int> visited(n, 0);
  queue<int> q;
  q.push(0);
  visited[0] = 1;

  while (!q.empty())
  {
    int node = q.front();
    q.pop();
    cout << node << " ";
    for (auto it : adjList[node])
    {
      if (!visited[it])
      {
        q.push(it);
        visited[it] = 1;
      }
    }
  }
}
int main()
{
  int n;
  cout << "Enter the number of Nodes" << endl;
  cin >> n;

  // create adjaceny list
  vector<int> adjList[n];

  cout << "Enter the edges" << endl;
  for (int i = 0; i < n; i++)
  {
    int u, v;
    cin >> u >> v;
    adjList[u].push_back(v);
    adjList[u].push_back(u);
  }

  cout << "print BFS" << endl;
  print(adjList, n);
}