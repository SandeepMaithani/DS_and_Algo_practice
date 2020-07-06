#include<bits/stdc++.h>
using namespace std;

char nextGreatestLetter(vector<char>& letters, char target, int start, int end) {

	char answer = '#';

	while (start <= end) {

		int mid = start + (end - start) / 2;

		if (letters[mid] > target) {

			answer = letters[mid];
			end = mid - 1;
		}
		else {
			start = start + 1;
		}
	}

	return answer;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	char target;

	cin >> n >> target;

	vector<char>letters(n);

	for (int i = 0; i < n; i++) {
		cin >> letters[i];
	}

	char answer = nextGreatestLetter(letters, target, 0, n - 1);

	cout << answer << endl;

	return 0;
}




