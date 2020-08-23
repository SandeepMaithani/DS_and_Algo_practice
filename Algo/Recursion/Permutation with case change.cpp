#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define endl "\n"
typedef long long int lli;

void caseChange(string input, string output) {
	if (input.length() == 0) {
		cout << output << endl;
		return;
	}

	char temp = toupper(input[0]);

	string pick = output + temp;
	string drop = output + input[0];

	input.erase(input.begin());

	caseChange(input, drop);
	caseChange(input, pick);
}


int main() {

	string input, output = "";
	cin >> input;

	caseChange(input, output);

	return 0;
}


