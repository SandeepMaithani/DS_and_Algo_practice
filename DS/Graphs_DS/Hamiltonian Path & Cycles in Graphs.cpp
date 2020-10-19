#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define endl "\n"
typedef long long int ll;

void hamiltonianHelper(vector<vector<int>>& graph)

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input1.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output1.txt", "w", stdout);
#endif

	int vertexCount, edgeCount, pairCount = 0;
	cin >> vertexCount >> edgeCount;

	vector<vector<int>>componentHolder;
	vector<vector<int>>graph(vertexCount);
	vector<bool>visited(vertexCount, false);

	for (int i = 0; i < edgeCount; i++) {
		int vertex1, vertex2;
		cin >> vertex1 >> vertex2;

		graph[vertex1].push_back(vertex2);
		graph[vertex2].push_back(vertex1);
	}


	return 0;
}