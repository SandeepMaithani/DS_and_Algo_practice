#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define endl "\n"
typedef long long int lli;

void spacePer(string input, string output) {
	if (input.length() == 0) {
		cout << output << endl;
		return;
	}
	else {

		string pick = output + " " + input[0];
		string drop = output + input[0];

		input.erase(input.begin());

		spacePer(input, drop);
		spacePer(input, pick);
	}
}


int main() {

	string input, output = "";
	cin >> input;

	output += input[0];
	input.erase(input.begin());

	spacePer(input, output);

	return 0;
}


