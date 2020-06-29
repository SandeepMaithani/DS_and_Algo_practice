#include<bits/stdc++.h>
using namespace std;

int first(vector<int> &vec, int target, int start, int end) {

	int answer = -1;

	while (start <= end) {

		int mid = start + (end - start) / 2;

		if (vec[mid] == target) {
			answer = mid;
			end = mid - 1;
		}

		else if (vec[mid] > target) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
	return answer;
}

int second(vector<int> &vec, int target, int start, int end) {

	int answer = -1;

	while (start <= end) {

		int mid = start + (end - start) / 2;

		if (vec[mid] == target) {
			answer = mid;
			start = mid + 1;
		}

		else if (vec[mid] > target) {
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

	int n, target, count;
	cin >> n >> target;

	vector<int>vec(n);

	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}

	int foccur = first(vec, target, 0, n - 1);
	int soccur = second(vec, target, 0, n - 1);

	if (soccur == -1 || foccur == -1) {
		count = 0;
	}
	else {
		count = soccur - foccur + 1;
	}

	cout << count << endl;

	return 0;
}