#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define endl "\n"
typedef long long int lli;

void check1and0(int n, int cnt1, int cnt0, string output) {
	if (n == 0) {
		cout << output << endl;
		return;
	}


	string output1 = output + "1";
	check1and0(n - 1, cnt1 + 1, cnt0, output1);

	if (cnt0 < cnt1) {
		string output2 = output + "0";
		check1and0(n - 1, cnt1, cnt0 + 1, output2);
	}
}


int main() {

	string output = "";

	int n;
	cin >> n;

	check1and0(n, 0, 0, output);

	return 0;
}


