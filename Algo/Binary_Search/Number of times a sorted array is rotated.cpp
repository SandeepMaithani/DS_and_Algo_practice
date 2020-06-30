#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &vec, int n, int start, int end) {

	int answer;

	while (start <= end) {

		int mid = start + (end - start) / 2;
		int next = (mid + 1) % n;
		int prev = (mid + n - 1) % n;

		if (vec[mid] < vec[prev] && vec[mid] < vec[next]) {
			answer = mid;
			break;
		}

		else if (vec[mid] < vec[end]) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
	return answer;
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, answer;
	cin >> n;

	vector<int>vec(n);

	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}

	if (vec[0] < vec[n - 1] || n == 1) {
		answer = vec[0];
	}
	else {
		answer = solve(vec, n, 0, n - 1);
	}

	cout << (n - answer) << endl;

	return 0;
}