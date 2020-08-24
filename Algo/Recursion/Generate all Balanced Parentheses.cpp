#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define endl "\n"
typedef long long int lli;

void balancedParentheses(int open, int close, string output) {
	if (open == 0 && close == 0) {
		cout << output << endl;
		return;
	}

	if (open != 0) {
		string output1 = output + "(";
		balancedParentheses(open - 1, close, output1);
	}

	if (open < close) {
		string output2 = output + ")";
		balancedParentheses(open, close - 1, output2);
	}
}


int main() {

	string output = "";

	int n;
	cin >> n;

	balancedParentheses(n, n, output);

	return 0;
}


