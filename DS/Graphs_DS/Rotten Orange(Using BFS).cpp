/*

using BFS             Verdict : Accepted

Complexity Analysis:

Time Complexity: O(R *C).

Each element of the matrix can be inserted into the queue only once so the upperbound of iteration is O(R*C), i.e. the number of elements. So time complexity is O(R * C).

Space Complexity: O(R*C).

To store the elements in a queue O(R*C) space is needed.

*/


struct info {
    int timeframe;
    int x;
    int y;
};

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int freshCount = 0, timeReq = 0;
        int row = grid.size(), col = grid[0].size();

        queue<info>bfs;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    freshCount++;
                }
                else if (grid[i][j] == 2) {
                    bfs.push({0, i, j});
                }
            }
        }

        while (!bfs.empty()) {
            info rotten = bfs.front();
            bfs.pop();

            int x = rotten.x;
            int y = rotten.y;
            int timeFrame = rotten.timeframe;

            timeReq = max(timeReq, timeFrame);

            if (x > 0 && grid[x - 1][y] == 1) {
                grid[x - 1][y] = 2;
                freshCount--;
                bfs.push({timeFrame + 1, x - 1, y});
            }
            if (y > 0 && grid[x][y - 1] == 1) {
                grid[x][y - 1] = 2;
                freshCount--;
                bfs.push({timeFrame + 1, x, y - 1});
            }
            if (x < row - 1 && grid[x + 1][y] == 1) {
                grid[x + 1][y] = 2;
                freshCount--;
                bfs.push({timeFrame + 1, x + 1, y});
            }
            if (y < col - 1 && grid[x][y + 1] == 1) {
                grid[x][y + 1] = 2;
                freshCount--;
                bfs.push({timeFrame + 1, x, y + 1});
            }
        }

        if (freshCount == 0) {
            return timeReq;
        }
        else {
            return -1;
        }
    }
};