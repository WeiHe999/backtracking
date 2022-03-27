#include <bits/stdc++.h>
using namespace std;

template < typename T > void print (T t)
{
    for (const auto & e:t) cout << e << " ";
    cout << endl;
}

void dfs(int start_node, int end_node, unordered_map<int, unordered_set<int> > graph, unordered_set<int> & visited, vector<int> & path)
{
    if (!visited.count(start_node))
    {
        visited.insert(start_node);
        path.push_back(start_node);
        if (graph[start_node].size()==0) return;
        for (auto x: graph[start_node])
        {
            cout << "from " << start_node << " to " << x << endl; 
            if(x==end_node)
            {
                cout << "found the path" << endl;
                path.push_back(x);
                print(path);
                return;
            }
            dfs(x, end_node, graph, visited, path);
        }
        
    }
}

int main()
{
    unordered_map<int, unordered_set<int> > graph = {{0, {1, 3}}, {1, {2}}, {2, {}}, {3, {4, 6}}, {4, {5, 7}}, {5, {}},
    {6, {7}}, {7, {8}}, {8, {}} };
    unordered_set<int> visited;
    vector<int> path;
    dfs(0, 8, graph, visited, path);
 
}
