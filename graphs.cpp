#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<climits>
using namespace std;
vector<pair<pair<int, int>, int>>
calprimsalgo(int n, int m, vector<pair<pair<int, int>, int>> &g) {
  // create adjency list
  unordered_map<int, vector<pair<int, int>>> adj;
  for (int i = 0; i < g.size(); i++) {
    int u = g[i].first.first;
    int v = g[i].first.second;
    int w = g[i].second;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }
  vector<int> key(n + 1);
  vector<bool> parent(n + 1);
  vector<int> mst(n + 1);
  for (int i = 0; i <= n; i++) {
    key[i] = INT32_MAX;
    parent[i] = -1;
    mst[i] = false;
  }
  // lest start algo
  key[1] = 0;
  parent[1] = -1;
  for (int i = 0; i < n; i++) {
    int mini = INT32_MAX;
    int u;
    for (int v = 1; v <= n; v++) {
      if (!mst[v] && key[v] < mini) {
        u = v;
        mini = key[v];
      }
    }
    mst[u] = true;
    // check the adjacent node
    for (auto it : adj[u]) {
      int v = it.first;
      int w = it.second;
      if (mst[v] == 0 && w < key[v]) {
        parent[v] = w;
        key[v] = w;
      }
    }
  }
  for (int i = 0; i <= n; i++)
    cout << parent[i] << " " << mst[i] << " ";
  vector<pair<pair<int, int>, int>> result;
  for (int i = 2; i <= n; i++)
    result.push_back({{parent[i], i}, key[i]});
  for (int i = 0; i < result.size(); i++)
    cout << result[i].first.first << " " << result[i].first.second << ' '
         << result[i].second << "\n";
  return result;
}
class graph {
public:
  std::unordered_map<int, std::vector<int>> adj;
  std::unordered_map<int, bool> visited;
  void addedge(int u, int v, bool direction) {
    adj[u].push_back(v);
    if (!direction)
      adj[v].push_back(u);
  }
  void print() {
    for (auto i : adj) {
      std::cout << i.first << "->";
      for (auto j : i.second) {
        std::cout << j << ", ";
      }
      std::cout << std::endl;
    }
  }
  void dfs(int node, std::unordered_map<int, bool> &visited,
           std::unordered_map<int, std::vector<int>> adj,
           std::vector<int> &component) {
    component.push_back(node);
    visited[node] = true;
    for (auto i : adj[node]) {
      if (!visited[i])
        dfs(i, visited, adj, component);
    }
  }
  std::vector<int> bfs(int node, std::unordered_map<int, bool> &visited,
                       std::unordered_map<int, std::vector<int>> adj) {
    std::vector<int> ans;
    std::queue<int> q;
    q.push(node);
    visited[node] = 1;
    while (!q.empty()) {
      int fnode = q.front();
      q.pop();
      // store node in ans
      ans.push_back(fnode);
      for (auto i : adj[fnode]) {
        if (!visited[i]) {
          q.push(i);
          visited[i] = 1;
        }
      }
    }
    return ans;
  }
  std::vector<int> BFS(int noofvertex,
                       std::unordered_map<int, std::vector<int>> adj) {
    std::vector<int> ans;
    for (int i = 0; i < noofvertex; i++) {
      if (!visited[i])
        ans = bfs(i, visited, adj);
    }
    return ans;
  }
};
std::vector<int> BFS(int node, std::unordered_map<int, bool> &visited,
                     std::unordered_map<int, std::vector<int>> adj) {
  std::vector<int> ans;
  std::queue<int> q;
  q.push(node);
  visited[node] = 1;
  while (!q.empty()) {
    int fnode = q.front();
    q.pop();
    // store node in ans
    cout << fnode << " ";
    ans.push_back(fnode);
    for (auto i : adj[fnode]) {
      if (!visited[i]) {
        q.push(i);
        visited[i] = 1;
      }
    }
  }
  return ans;
}
vector<int> bfs( vector<pair<int, int>> &edges) {
  unordered_map<int, vector<int>> adj;
  for(auto k:edges)
  {
      int u=k.first;
      int v=k.second;
      adj[u].push_back(v);
  }
  for(auto i:adj) 
  {
      int u=i.first;
      cout<<""<<u<<" -";
      for(auto j:i.second)
      {
          cout<<j<<" ";
      }
      cout<<endl;
  }
  
  unordered_map<int, bool> visited;
  vector<int> ans;
  for (int i = 0; i < edges.size(); i++) {
    if (!visited[i])
      ans = BFS(i, visited, adj);
  }
  return ans;
}
int main() {
  vector<pair<int, int>> p;
  p.push_back({0, 1});
  p.push_back({1, 2});
  p.push_back({2, 1});
  bfs(p);
}
