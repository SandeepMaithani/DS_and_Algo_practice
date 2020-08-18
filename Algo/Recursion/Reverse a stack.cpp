#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long int lli;

void insertAtEnd(stack<int>&st, int num) {
	if (st.size() == 0) {
		st.push(num);
		return;
	}

	int temp = st.top();
	st.pop();

	insertAtEnd(st, num);
	st.push(temp);
}

void reverse(stack<int>&st) {
	if (st.size() == 1) {
		return;
	}

	int temp = st.top();
	st.pop();

	reverse(st);
	insertAtEnd(st, temp);
}

int main() {

	int n;
	cin >> n;

	stack<int>st;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		cout << temp << " ";

		st.push(temp);
	}

	cout << endl;

	reverse(st);

	while (!st.empty()) {
		cout << st.top() << " ";
		st.pop();
	}

	cout << endl;

	return 0;
}
