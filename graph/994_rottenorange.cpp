#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int n = grid.size();      // Number of rows
        int m = grid[0].size();   // Number of columns

        int vis[n][m];            // Visited matrix to track rotten oranges
        queue<pair<pair<int, int>, int>> q; // Queue to store {{row, col}, time}
        int cntfresh = 0;         // Count of fresh oranges

        // Initialize the queue with all initially rotten oranges
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < m; j++) 
            {
                if (grid[i][j] == 2) // Rotten orange found
                {
                    q.push({{i, j}, 0}); // Push its position and time = 0
                    vis[i][j] = 2;      // Mark as visited
                } 
                else 
                {
                    vis[i][j] = 0;      // Not yet rotten
                }

                if (grid[i][j] == 1)    // Count fresh oranges
                {
                    cntfresh++;
                }
            }
        }

        int tm = 0;                     // To track total time to rot all oranges
        int drow[] = {-1, 0, +1, 0};    // Up, Right, Down, Left movement
        int dcol[] = {0, +1, 0, -1};
        int cnt = 0;                    // Count of oranges turned rotten during BFS

        // Start BFS traversal
        while (!q.empty()) 
        {
            int r = q.front().first.first;    // Current row
            int c = q.front().first.second;   // Current column
            int t = q.front().second;         // Time at which it became rotten
            tm = max(tm, t);                  // Update max time
            q.pop();

            // Visit 4 neighbors
            for (int i = 0; i < 4; i++) 
            {
                int nrow = r + drow[i];       // Neighbor row
                int ncol = c + dcol[i];       // Neighbor col

                // Check if within bounds, not already rotten, and is a fresh orange
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1) 
                {
                    q.push({{nrow, ncol}, t + 1}); // Mark it to rot in next minute
                    vis[nrow][ncol] = 2;           // Mark visited (rotten)
                    cnt++;                         // Count this orange as processed
                }
            }
        }

        // If not all fresh oranges were rotted, return -1
        if (cnt != cntfresh) return -1;

        // Otherwise, return total time taken
        return tm;
    }
};

/**
Dry Run Example:
Input:
grid = {
  {2,1,1},
  {1,1,0},
  {0,1,1}
}

Step 1: Initially rotten oranges at (0,0)
Step 2: BFS Level 1 => Rot (0,1) and (1,0)
Step 3: BFS Level 2 => Rot (0,2), (1,1)
Step 4: BFS Level 3 => Rot (2,1)
Step 5: BFS Level 4 => Rot (2,2)
All oranges rotten in 4 units of time => return 4

If any fresh orange is unreachable (not adjacent to a rotten one), cnt != cntfresh and we return -1.
*/
