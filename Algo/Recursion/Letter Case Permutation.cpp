#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define endl "\n"
typedef long long int lli;

void letterCasePermutation(string input, string output) {
	if (input.length() == 0) {
		cout << output << endl;
		return;
	}

	if (isalpha(input[0])) {
		char lower = tolower(input[0]);
		char upper = toupper(input[0]);

		string pickLow = output + lower;
		string pickUp = output + upper;

		input.erase(input.begin());

		letterCasePermutation(input, pickUp);
		letterCasePermutation(input, pickLow);
	}
	else {
		output = output + input[0];
		input.erase(input.begin());
		letterCasePermutation(input, output);
	}
}


int main() {

	string input, output = "";
	cin >> input;

	letterCasePermutation(input, output);

	return 0;
}


