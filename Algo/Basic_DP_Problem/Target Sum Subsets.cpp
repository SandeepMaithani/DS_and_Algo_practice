/*

Question Statement :-

In the Target Sum problem:

1. You are given a number n, representing the count of elements.
2. You are given n numbers.
3. You are given a number "target".
4. You are required to calculate and print true or false, if there is a subset the elements of which add up to "target" or not.

*/

/*

Complexity Analysis :-

Time Complexity: O(N*M). our dp martrix will require O(N*M) time to get filled completly once our dp matrix is completly populated
we will have constant look up time so we require O(N*M) worst case time where N is size of num vector and M is given target.

Space Complexity: O(N*M). We will need a DP matrix to to store subset and their corresponding target sum.

*/

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define endl "\n"
typedef long long int ll;

bool targetSum(vector<int>&num, vector<vector<int>>&dp, int n, int target) {
    if (n <= 0 && target != 0) {
        return false;
    }

    if (target == 0) {
        return true;
    }

    if (dp[n][target] != -1) {
        return dp[n][target];
    }

    if (num[n - 1] <= target) {

        int pick = targetSum(num, dp, n - 1, target - num[n - 1]);
        int drop = targetSum(num, dp, n - 1, target);

        dp[n][target] = pick || drop;

    }
    else {

        dp[n][target] = targetSum(num, dp, n - 1, target);
    }

    return dp[n][target];
}

int main() {
    int n;
    cin >> n;

    vector<int>num(n);

    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    int target;
    cin >> target;

    vector<vector<int>>dp(n + 1, vector<int>(target + 1, -1));

    if (targetSum(num, dp, n, target)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }

    return 0;
}