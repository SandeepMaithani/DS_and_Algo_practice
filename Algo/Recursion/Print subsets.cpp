#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define endl "\n"
typedef long long int lli;

void subSet(string input, string output) {
	if (input.length() == 0) {
		cout << output << endl;
		return;
	}

	string pick = output + input[0];
	string drop = output;

	input.erase(input.begin());

	subSet(input, drop);
	subSet(input, pick);
}


int main() {

	string input, output = "";
	cin >> input;

	subSet(input, output);

	return 0;
}


