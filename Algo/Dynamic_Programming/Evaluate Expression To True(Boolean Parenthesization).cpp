#include<bits/stdc++.h>
using namespace std;

//Recursion + Memoization (Optimized)
//using 3D matrix

int dp[202][202][2];

int ways(string &str, int i, int j, bool target) {

	if (dp[i][j][target] != -1) {
		return dp[i][j][target];
	}

	if (i > j) {

		return false;
	}

	if (i == j) {

		if (target == true) {
			return (str[i] == 'T');
		}
		else {
			return (str[i] == 'F');
		}
	}

	int answer = 0;

	for (int k = i + 1; k <= j - 1; k = k + 2) {

		int LT, LF, RT, RF;

		if (dp[i][k - 1][1] != -1) {

			LT = dp[i][k - 1][1];
		}
		else {

			LT = ways(str, i, k - 1, true);
			dp[i][k - 1][1] = LT;
		}

		if (dp[i][k - 1][0] != -1) {

			LF = dp[i][k - 1][0];
		}
		else {

			LF = ways(str, i, k - 1, false);
			dp[i][k - 1][0] = LF;
		}

		if (dp[k + 1][j][1] != -1) {

			RT = dp[k + 1][j][1];
		}
		else {

			RT = ways(str, k + 1, j, true);
			dp[k + 1][j][1] = RT;
		}

		if (dp[k + 1][j][0] != -1) {

			RF = dp[k + 1][j][0];
		}
		else {

			RF = ways(str, k + 1, j, false);
			dp[k + 1][j][0] = RF;
		}

		if (str[k] == '&') {

			if (target == true) {

				answer += (LT * RT);
			}
			else {

				answer += (LF * RF) + (LF * RT) + (LT * RF);
			}
		}
		else if (str[k] == '|') {

			if (target == true) {

				answer += (LT * RT) + (LF * RT) + (LT * RF);
			}
			else {

				answer += (LF * RF);
			}
		}
		else {

			if (target == true) {

				answer += (LT * RF) + (LF * RT);
			}
			else {

				answer += (LT * RT) + (LF * RF);
			}
		}
	}

	dp[i][j][target] = answer;

	return dp[i][j][target];
}

int main() {

	string str;
	cin >> str;

	int n = str.length();

	memset(dp, -1, sizeof(dp));

	int result = ways(str, 0, n - 1, true);

	cout << result << endl;

	return 0;
}


//Recursion + Memoization
//Using HashMap

int ways(string str, unordered_map<string, int> &dp, int i, int j, bool target) {

	if (i > j) {

		return false;
	}

	if (i == j) {

		if (target == true) {
			return (str[i] == 'T');
		}
		else {
			return (str[i] == 'F');
		}
	}

	string key = to_string(i)  + to_string(j) + to_string(target);

	if (dp.find(key) != dp.end()) {
		return dp[key];
	}

	int answer = 0;

	for (int k = i + 1; k <= j - 1; k = k + 2) {

		int LT = ways(str, dp, i, k - 1, true);
		int LF = ways(str, dp, i, k - 1, false);
		int RT = ways(str, dp, k + 1, j, true);
		int RF = ways(str, dp, k + 1, j, false);

		if (str[k] == '&') {

			if (target == true) {

				answer += LT * RT;
			}
			else {

				answer += (LF * RF) + (LF * RT) + (LT * RF);
			}
		}
		else if (str[k] == '|') {

			if (target == true) {

				answer += (LT * RT) + (LF * RT) + (LT * RF);
			}
			else {

				answer += (LF * RF);
			}
		}
		else {

			if (target == true) {

				answer += (LT * RF) + (LF * RT);
			}
			else {

				answer += (LT * RT) + (LF * RF);
			}
		}
	}

	dp[key] = answer;
	return answer;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	cin >> str;

	int n = str.length();

	unordered_map<string, int>dp;
	dp.clear();

	int result = ways(str, dp, 0, n - 1, true);

	cout << result << endl;

	return 0;
}

