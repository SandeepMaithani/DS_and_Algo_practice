#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define endl "\n"
typedef long long int lli;

void josephus(vector<int> &people, int k, int index, int &answer) {

	if (people.size() == 1) {
		answer = people[0];
		return;
	}

	index = (index + k) % people.size();
	people.erase(people.begin() + index);

	josephus(people, k, index, answer);

}


int main() {

	int n, k;
	cin >> n >> k;

	int answer = -1;

	vector<int>people(n);

	for (int i = 0; i < n; i++) {
		people[i] = i + 1;
	}

	josephus(people, k - 1, 0, answer);

	cout << answer << endl;

	return 0;
}


