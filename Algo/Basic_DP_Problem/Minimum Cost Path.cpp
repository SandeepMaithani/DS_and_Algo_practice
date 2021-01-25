/*

Question Statement :-

In the Min Cost In Maze Traversal problem:

1. You are given a number n, representing the number of rows.
2. You are given a number m, representing the number of columns.
3. You are given n*m numbers, representing elements of 2d array a, which represents a maze.
4. You are standing in top-left cell and are required to move to bottom-right cell.
5. You are allowed to move 1 cell right (h move) or 1 cell down (v move) in 1 motion.
6. Each cell has a value that will have to be paid to enter that cell (even for the top-left and bottom-right cell).
7. You are required to traverse through the matrix and print the cost of path which is least costly.

*/


/*

Complexity Analysis :-

Time Complexity: O(N*M). Since we will be traversing each and every cell once in order to find min cost to reach that cell
it will cost us O(N*M) time where N is no of rows and M is no of columns.

Space Complexity: O(N*M). We will need a DP matrix to store min cost to reach that cell so it will cost us O(N*M) extra memory.

*/

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define endl "\n"
typedef long long int ll;


int main() {

	int n, m;
	cin >> n >> m;

	vector<vector<int>>maze(n, vector<int>(m));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> maze[i][j];
		}
	}

	vector<vector<int>>dp(n, vector<int>(m));

	dp[0][0] = maze[0][0];

	for (int i = 1; i < n; i++) {
		dp[i][0] = dp[i - 1][0] + maze[i][0];
	}

	for (int j = 1; i < m; j++) {
		dp[0][j] = dp[0][j - 1] + maze[0][j];
	}

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			dp[i][j] = dp[i - 1][j - 1] + min(maze[i - 1][j], maze[i][j - 1]);
		}
	}

	cout << dp[n - 1][m - 1] << endl;

	return 0;

}


