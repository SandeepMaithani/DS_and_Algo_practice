#include<bits/stdc++.h>
using namespace std;

//Recursion + Memoization

int MCM(vector<int>&arr, vector<vector<int>>&dp, int i, int j) {
	if (i >= j) {

		dp[i][j] = 0;
		return 0;
	}

	if (dp[i][j] != -1) {
		return dp[i][j];
	}

	int answer = INT_MAX;

	for (int k = i; k <= j - 1; k++) {

		int first = MCM(arr, dp, i, k);
		int second = MCM(arr, dp, k + 1, j);

		int cost = arr[i - 1] * arr[k] * arr[j];

		int temp = first + second + cost;

		if (temp < answer) {
			answer = temp;
		}
	}

	dp[i][j] = answer;

	return dp[i][j];
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int>arr(n);

	vector<vector<int>>dp(n + 1, vector<int>(n + 1, -1));

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int minimum = MCM(arr, dp, 1, n - 1);

	cout << minimum << endl;

	return 0;
}
