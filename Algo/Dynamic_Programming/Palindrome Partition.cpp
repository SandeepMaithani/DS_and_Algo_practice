#include <bits/stdc++.h>
using namespace std;

//Recursion + Memoization (optimized)
//Time Complexity O(N^3)

bool ispalin(string s, int i, int j) {

	while (i < j) {
		if (s[i] != s[j]) {
			return false;
		}

		i++;
		j--;
	}

	return true;
}

int cutpalin(string s, vector<vector<int>>&dp, int i, int j) {

	if (i >= j) {
		dp[i][j] = 0;
		return 0;
	}

	if (dp[i][j] != -1) {
		return dp[i][j];
	}

	if (ispalin(s, i, j)) {
		dp[i][j] = 0;
		return 0;
	}

	int answer = INT_MAX;

	for (int k = i; k <= j - 1; k++) {

		int first, second;

		if (dp[i][k] != -1) {
			first = dp[i][k];
		}
		else {
			first = cutpalin(s, dp, i, k);
		}

		if (dp[k + 1][j] != -1) {
			second = dp[k + 1][j];
		}
		else {
			second = cutpalin(s, dp, k + 1, j);
		}

		int temp = first + second + 1;

		if (temp < answer) {
			answer = temp;
		}
	}

	dp[i][j] = answer;
	return answer;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	cin >> str;

	int n = str.length();

	vector<vector<int>>dp(n + 1, vector<int>(n + 1, -1));

	int answer = cutpalin(str, dp, 0, n - 1);

	cout << answer << endl;

	return 0;
}


//Recursion + Memoization (Unoptimized)
//Time Complexity O(N^3)

/*

bool ispalin(string s, int i, int j) {

	while (i < j) {
		if (s[i] != s[j]) {
			return false;
		}

		i++;
		j--;
	}

	return true;
}

int cutpalin(string s, vector<vector<int>>&dp, int i, int j) {

	if (i >= j) {
		dp[i][j] = 0;
		return 0;
	}

	if (dp[i][j] != -1) {
		return dp[i][j];
	}

	if (ispalin(s, i, j)) {
		dp[i][j] = 0;
		return 0;
	}

	int answer = INT_MAX;

	for (int k = i; k <= j - 1; k++) {

		int first = cutpalin(s, dp, i, k);
		int second = cutpalin(s, dp, k + 1, j);

		int temp = first + second + 1;

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

	string str;
	cin >> str;

	int n = str.length();

	vector<vector<int>>dp(n + 1, vector<int>(n + 1, -1));

	int answer = cutpalin(str, dp, 0, n - 1);

	cout << answer << endl;

	return 0;
}

*/
