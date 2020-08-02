/*

Complexity Analysis:

Time Complexity: O(N * M).

Only one traversal of the matrix is required, so the time complexity is O(N*M)

Space Complexity: O(M).

Stack is required to store the columns, so so space complexity is O(M)

*/


#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long int lli;

void fillleft(vector<int>&hist, vector<int>&left) {
	stack<int>st;
	int extrme = -1;

	for (int i = 0; i < hist.size(); i++) {
		if (st.empty()) {
			left.push_back(extrme);
		}
		else if (hist[st.top()] < hist[i]) {
			left.push_back(st.top());
		}
		else {
			while (!st.empty() && hist[st.top()] >= hist[i]) {
				st.pop();
			}
			if (st.empty()) {
				left.push_back(extrme);
			}
			else {
				left.push_back(st.top());
			}
		}
		st.push(i);
	}
}

void fillright(vector<int>&hist, vector<int>&right) {

	stack<int>st;
	int extrme = hist.size();

	for (int i = hist.size() - 1; i >= 0; i--) {

		if (st.empty()) {
			right.push_back(extrme);
		}
		else if (hist[st.top()] < hist[i]) {
			right.push_back(st.top());
		}
		else {

			while (!st.empty() && hist[st.top()] >= hist[i]) {
				st.pop();
			}
			if (st.empty()) {
				right.push_back(extrme);
			}
			else {
				right.push_back(st.top());
			}
		}
		st.push(i);
	}
	reverse(right.begin(), right.end());
}

int largestarea(vector<int>&hist) {

	vector<int>left;
	vector<int>right;
	vector<int>area;

	fillleft(hist, left);
	fillright(hist, right);

	for (int i = 0; i < hist.size(); i++) {
		int width = right[i] - left[i] - 1;
		int answer = width * hist[i];

		area.push_back(answer);
	}

	return *max_element(area.begin(), area.end());
}


int main() {

	int n, m;
	cin >> n >> m;

	vector<vector<int>>matrix(n, vector<int>(m));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> matrix[i][j];
		}
	}

	for (int i = 1; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[0].size(); j++) {
			if (matrix[i][j] == 1) {
				matrix[i][j] = 1 + matrix[i - 1][j];
			}
			else {
				matrix[i][j] = 0;
			}
		}
	}

	int answer = INT_MIN;

	for (int i = 0; i < n; i++) {
		answer = max(answer, largestarea(matrix[i]));
	}

	cout << answer << endl;

	return 0;
}


