/*

Question Statement :-

In the Climb Stairs in minimum moves problem:

1. You are given a number n, representing the number of stairs in a staircase.
2. You are on the 0th step and are required to climb to the top.
3. You are given n numbers, where ith element's value represents - till how far from the step you could jump to in a single move.  You can of-course fewer number of steps in the move.
4. You are required to print the number of minimum moves in which you can reach the top of staircase.

Note -> If there is no path through the staircase print null.

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


int minMovesMemo(int curStep, int n, vector<int>&jump, vector<int>&dp) {

    if (curStep == n) {
        return 0;
    }

    if (dp[curStep] != 0) {
        return dp[curStep];
    }

    int minMove = INT_MAX;

    for (int i = 1; i <= jump[curStep] && curStep + i <= n; i++) {
        int localMin;

        if (dp[curStep + i] != 0) {
            localMin = dp[curStep + i];
        }
        else {
            localMin = minMovesMemo(curStep + i, n, jump, dp);
        }

        if (localMin < minMove) {
            minMove = localMin;
        }
    }

    if (minMove == INT_MAX) {
        dp[curStep] = minMove;
    }
    else {
        dp[curStep] = 1 + minMove;
    }

    return dp[curStep];
}


//Using Tabulation Method


int minMovesTab(int n, vector<int>&jumps, vector<int>&dp) {
    dp[n] = 0;

    for (int i = n - 1; i >= 0; i--) {

        int minMove = INT_MAX;
        for (int j = 1; j <= jumps[i] && i + j <= n; j++) {
            if (dp[i + j] < minMove) {
                minMove = dp[i + j];
            }
        }

        if (minMove == INT_MAX) {
            dp[i] = minMove;
        }
        else {
            dp[i] = 1 + minMove;
        }
    }

    return dp[0];
}

int main() {
    int n;
    cin >> n;

    vector<int>jumps(n);

    for (int i = 0; i < n; i++) {
        cin >> jumps[i];
    }

    vector<int>dp(n + 1, 0);

    int answer = minMoves(n, jumps, dp);

    //int answer = minMovesMemo(0, n, jumps, dp);

    cout << answer << endl;

    return 0;
}