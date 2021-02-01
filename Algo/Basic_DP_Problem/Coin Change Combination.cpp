/*

Question Statement :-

In the Coin Change Combination problem:

1. You are given a number n, representing the count of coins.
2. You are given n numbers, representing the denominations of n coins.
3. You are given a number "amt".
4. You are required to calculate and print the number of combinations of the n coins using which the amount "amt" can be paid.

Note1 -> You have an infinite supply of each coin denomination i.e. same coin denomination can be used for many installments in payment of "amt"

Note2 -> You are required to find the count of combinations and not permutations i.e. 2 + 2 + 3 = 7 and 2 + 3 + 2 = 7 and 3 + 2 + 2 = 7 are
different permutations of same combination. You should treat them as 1 and not 3.

*/


/*

Complexity Analysis :-

Time Complexity: O(N*M). We will look what amount we can change with a particular coin to do so and completly fill our dp vector
we will pick all coin and all possible amount one by one which cost worst case time of O(N*M).

Space Complexity: O(M). We will need a dp vector of size M+1 to memoize no of ways for a particular amount. Here M is given amount.

*/


#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define endl "\n"
typedef long long int ll;

int main() {

	int n, amount;
	cin >> n;

	vector<int>coins(n);

	for (int i = 0; i < n; i++) {
		cin >> coins[i];
	}

	cin >> amount;

	vector<int>dp(amount + 1, 0);

	dp[0] = 1;

	for (int i = 0; i < n; i++) {
		for (int j = coins[i]; j <= amount; j++) {
			dp[j] = dp[j] + dp[j - coins[i]];
		}
	}

	cout << dp[amount] << endl;

	return 0;
}