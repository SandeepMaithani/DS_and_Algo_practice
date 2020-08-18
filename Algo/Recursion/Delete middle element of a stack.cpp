#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long int lli;


void delMid(stack<int>&st, int mid) {
	if (st.size() == mid || st.size() == 1) {
		st.pop();
		return;
	}

	int topEle = st.top();
	st.pop();

	delMid(st, mid);
	st.push(topEle);
}


int main() {

	int n;
	cin >> n;

	stack<int>st;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;

		st.push(temp);
	}

	int mid = (n / 2) + 1;

	delMid(st, mid);

	while (!st.empty()) {
		cout << st.top() << " ";
		st.pop();
	}

	cout << endl;

	return 0;
}


