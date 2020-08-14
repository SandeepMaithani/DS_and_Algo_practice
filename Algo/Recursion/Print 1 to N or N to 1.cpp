#include <bits/stdc++.h>
using namespace std;

void OtoN(int n) {
	if (n == 1) {
		cout << n << " ";
		return;
	}

	OtoN(n - 1);

	cout << n << " ";
}

void NtoO(int n) {

	if (n == 1) {
		cout << n << " ";
		return;
	}

	cout << n << " ";

	NtoO(n - 1);
}


int main() {

	int n;
	cin >> n;

	OtoN(n);
	cout << endl;
	NtoO(n);

	return 0;
}


