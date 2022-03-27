/*
backtracking (DFS) to find a valid path from start to end.
(There are maybe multiple paths to reach the end node, here dfs only finds a single path)
If you want to find the number of paths to reach the end node, use bottom-up dynamic programming.
*/
#include <bits/stdc++.h>
using namespace std;

template < typename T > void print (T t)
{
    for (const auto & e:t) cout << e << " ";
    cout << endl;
}

void dfs(int start_node, int end_node, int cur_node, unordered_map <int, unordered_set <int> > graph, vector <int> &vec1, unordered_set <int> &visited)
{
    if (cur_node == end_node)
    {
        for (auto x : vec1) cout << x << " ";
        cout << endl;
        return;
    }
    for (auto a : graph[cur_node])
    {
        if (!visited.count(a))
        {
            visited.insert(a);
            vector <int> vec2 = vec1;
            vec2.emplace_back(a);
            dfs(start_node, end_node, a, graph, vec2, visited);
        }
    }
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    unordered_map <int, unordered_set <int> > graph = {{0, {1, 3}}, {1, {2}}, {2, {}}, {3, {4, 6}}, {4, {5, 7}}, {5, {}}, {6, {7}}, {7, {8}}, {8, {}}};
    int start_node = 0, end_node = 8;
    vector <int> vec1 = {start_node};
    unordered_set <int> visited = {start_node};
    dfs(start_node, end_node, start_node, graph, vec1, visited);
}
