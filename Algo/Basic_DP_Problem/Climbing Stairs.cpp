/*

Question Statement :-

In the Climb Stairs problem:

1. You are given a number n, representing the number of stairs in a staircase.
2. You are on the 0th step and are required to climb to the top.
3. In one move, you are allowed to climb 1, 2 or 3 stairs.
4. You are required to print the number of different paths via which you can climb to the top.

*/


/*

Complexity Analysis :-

Time Complexity: O(N). Only one traversal of the array is needed. So Time Complexity is O(N) where N is length of array.

Space Complexity: O(N).To store the values in a DP vector of length N, so N extra space is needed.

*/


#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define endl "\n"
typedef long long int ll;


// Using Recursion + Memoization


int countWaysMemo(int num, vector<int>&dp) {
	if (num == 0) {
		return 1;
	}
	else if (num < 0) {
		return 0;
	}

	if (dp[num] != -1) {
		return dp[num];
	}

	int first = countWaysMemo(num - 1, dp);
	int second = countWaysMemo(num - 2, dp);
	int third = countWaysMemo(num - 3, dp);

	int totalWays = first + second + third;
	dp[num] = totalWays;

	return dp[num];
}


//Using Tabulation


int countWaysTab(int num, vector<int>&dp) {
	dp[0] = 1;

	for (int i = 1; i <= num; i++) {
		if (i == 1) {
			dp[i] = dp[i - 1];
		}
		else if (i == 2) {
			dp[i] = dp[i - 1] + dp[i - 2];
		}
		else {
			dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		}
	}

	return dp[num];
}


int main() {
	int num;
	cin >> num;

	vector<int>dp(num + 1, -1);

	int answer = countWaysTab(num, dp);

	cout << answer << endl;
}


