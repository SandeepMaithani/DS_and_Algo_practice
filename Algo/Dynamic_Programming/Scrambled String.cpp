#include<bits/stdc++.h>
using namespace std;

//Recursion + Memoization

bool scram(string a, string b, unordered_map<string, bool> &dp) {

	int n = a.length();

	if (a.compare(b) == 0) {
		return true;
	}

	if (n <= 1) {
		return false;
	}

	string key = a + " " + b;

	if (dp.find(key) != dp.end()) {
		return dp[key];
	}

	bool result = false;

	for (int k = 1; k <= n - 1; k++) {

		bool isswap = false, noswap = false;

		if (scram(a.substr(0, k), b.substr(n - k, k), dp) && scram(a.substr(k, n - k), b.substr(0, n - k), dp)) {
			isswap = true;
		}
		else if (scram(a.substr(0, k), b.substr(0, k), dp) && scram(a.substr(k, n - k), b.substr(k, n - k), dp)) {
			noswap = true;
		}

		if (isswap || noswap) {
			result = true;
			break;
		}
	}

	dp[key] = result;

	return result;

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string a, b;
	cin >> a >> b;

	unordered_map<string, bool>dp;

	if (a.length() != b.length()) {
		cout << "NO" << endl;
	}
	else if (a == b) {
		cout << "YES" << endl;
	}
	else if (scram(a, b, dp)) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}

	return 0;

}
