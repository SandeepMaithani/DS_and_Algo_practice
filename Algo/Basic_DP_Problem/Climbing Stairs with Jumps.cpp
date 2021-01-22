/*

Question Statement :-

In the Climb Stairs with jumps problem:

1. You are given a number N, representing the number of stairs in a staircase.
2. You are on the 0th step and are required to climb to the top.
3. You are given N numbers, where ith element's value represents - till how far from the step  you could jump to in a single move.
4. You are required to print the number of different paths via which you can climb to the top.

*/


/*

Complexity Analysis :-

Time Complexity: O(N*N). Here it is possible that one can jump to each subsequent steps so we can say in worst case one can jump to
all subsequent steps from each step, so time complexity will be O(N*N).

Space Complexity: O(N).To store the values in a DP vector of length N, so N extra space is needed.

*/


#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define endl "\n"
typedef long long int ll;


//Using Recursion + Memoization


int countWaysMemo(int curStep, int n, vector<int>&jump, vector<int>&dp) {

	if (curStep == n) {
		return 1;
	}

	if (dp[curStep] != 0) {
		return dp[curStep];
	}

	int answer = 0;

	for (int i = 1; i <= jump[curStep] && curStep + i <= n; i++) {
		if (dp[curStep + i] != 0) {
			answer += dp[curStep + i];
		}
		else {
			answer += countWaysMemo(curStep + i, n, jump, dp);
		}
	}

	dp[curStep] = answer;

	return answer;
}


//Using Tabulation


int countWaysTab(int n, vector<int>&jump, vector<int>&dp) {
	dp[n] = 1;

	for (int i = n - 1; i >= 0; i--) {
		for (int j = 1; j <= jump[i] && i + j <= n; j++) {
			dp[i] += dp[i + j];
		}
	}

	return dp[0];
}


int main() {

	int n;
	cin >> n;

	vector<int>jump(n);

	for (int i = 0 ; i < n ; i++) {
		cin >> jump[i];
	}

	vector<int>dp(n + 1, 0);

	int answer = countWaysMemo(0, n, jump, dp);

	cout << answer << endl;

	return 0;
}



