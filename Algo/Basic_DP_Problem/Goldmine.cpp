/*

Question Statement :-

In the Gold Mine problem:

1. You are given a number n, representing the number of rows.
2. You are given a number m, representing the number of columns.
3. You are given n*m numbers, representing elements of 2d array a, which represents a gold mine.
4. You are standing in front of left wall and are supposed to dig to the right wall. You can start from any row in the left wall.
5. You are allowed to move 1 cell right-up (d1), 1 cell right (d2) or 1 cell right-down(d3).
6. Each cell has a value that is the amount of gold available in the cell.
7. You are required to identify the maximum amount of gold that can be dug out from the mine.

*/


/*

Complexity Analysis :-

Time Complexity: O(N*M). Since we will be visiting each and every cell atmost 4 time in order to find max gold possible at that cell
it will cost us O(N*M) time where N is no of rows and M is no of columns.

Space Complexity: O(N*M). We will need a DP matrix to store max gold mined till that cell so it will cost us O(N*M) extra memory.

*/


#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define endl "\n"
typedef long long int ll;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>>mine(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mine[i][j];
        }
    }

    vector<vector<int>>dp(n, vector<int>(m, 0));
    int maxGold = 0;

    for (int i = 0; i < n; i++) {
        dp[i][0] = mine[i][0];
    }

    for (int j = 0; j < m - 1; j++) {
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                int upVal =  dp[i][j] + mine[i - 1][j + 1];
                dp[i - 1][j + 1] = max(dp[i - 1][j + 1], upVal);
            }

            int rightVal = dp[i][j] + mine[i][j + 1];
            dp[i][j + 1] = max(dp[i][j + 1], rightVal);

            if (i < n - 1) {
                int downVal =  dp[i][j] + mine[i + 1][j + 1];
                dp[i + 1][j + 1] = max(dp[i + 1][j + 1], downVal);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        maxGold = max(maxGold, dp[i][m - 1]);
    }

    cout << maxGold << endl;

    return 0;
}