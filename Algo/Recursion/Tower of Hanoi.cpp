#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define endl "\n"
typedef long long int lli;

void twrHan(int n, string src, string des, string hlp) {
	if (n == 1) {
		cout << "Move disk " << n << " from " << src << " to " << des << endl;
		return;
	}

	twrHan(n - 1, src, hlp, des);

	cout << "Move disk " << n << " from " << src << " to " << des << endl;

	twrHan(n - 1, hlp, des, src);
}

int main() {


	int n;
	cin >> n;

	string src = "Source", des = "Destination", hlp = "Helper";

	twrHan(n, src, des, hlp);

	return 0;
}


