#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long int lli;

void matBsearch(vector<vector<int>>&mat, int target, int n, int m) {
	int row = 0;
	int col = m - 1;
	int checker;

	while (row < n && col >= 0) {
		checker = mat[row][col];

		if (checker == target) {
			cout << "Found at : (" << row << "," << col << ")\n";
			return;
		}
		else if (checker > target) {
			col--;
		}
		else {
			row++;
		}
	}
	cout << "Element Not Found" << endl;
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input1.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output1.txt", "w", stdout);
#endif

	int n, m , target;

	cin >> n >> m >> target;

	vector<vector<int>>mat(n, vector<int>(m));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mat[i][j];
		}
	}

	matBsearch(mat, target, n, m);

	return 0;
}
