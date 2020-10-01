/*

Complexity Analysis :-

Time Complexity : O(Log(N)), Where N is size of array. 
Space Complexity : O(1), No extra Space required.


*/

#include<bits/stdc++.h>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, target;
	cin >> n >> target;

	vector<int>vec(n);

	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}

	int start = 0;
	int end = n - 1;

	while (start <= end) {

		int mid = start + (end - start) / 2;

		if (vec[mid] == target) {
			cout << "Element found at : " << mid << endl;
			return 0;
		}

		if (vec[mid] > target) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}

	cout << "Element not found " << endl;

	return 0;
}
