#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int findCircleNum(vector<vector<int>>& isConnected) 
        {
            int n = isConnected.size();
            int province = 0;
            vector<bool> visited(n, false);
            for (int i = 0; i < n; i++)
            {
                if(!visited[i])
                {
                    province++;
                    dfs(isConnected, visited, i);
                }
            }
            return province;
        }
    
        void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int node)
        {
            visited[node] = true;
            for (int neighbor = 0; neighbor < isConnected.size(); neighbor++)
            {
                if (isConnected[node][neighbor] == 1 && !visited[neighbor])
                {
                    dfs(isConnected, visited, neighbor);
                }
            }
        }
    };