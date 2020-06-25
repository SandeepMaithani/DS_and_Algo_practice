#include<bits/stdc++.h>
using namespace std;

//Recursion + Memoization

int drop(int egg, int floor, vector<vector<int>>&dp) {

	if (egg == 1) {
		return floor;
	}

	if (floor == 0 || floor == 1) {
		return floor;
	}

	if (dp[egg][floor] != -1) {

		return dp[egg][floor];
	}

	int answer = INT_MAX;

	for (int k = 1; k <= floor; k++) {

		int crack = drop(egg - 1, k - 1, dp);
		int nocrack = drop(egg, floor - k, dp);

		int temp = 1 +  max(crack, nocrack);

		answer = min(temp, answer);
	}

	dp[egg][floor] = answer;
	return answer;

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int egg, floor;
	cin >> egg >> floor;

	vector<vector<int>>dp(egg + 1, vector<int>(floor + 1, -1));

	int answer = drop(egg, floor, dp);

	cout << answer << endl;

	return 0;

}
