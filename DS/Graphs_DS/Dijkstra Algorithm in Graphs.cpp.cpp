#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define endl "\n"
typedef long long int ll;

void dijkstraAlgo(vector <vector<int>>& graph, int person, int time) {
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input1.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output1.txt", "w", stdout);
#endif

	int vertexCount, edgeCount, person, time;
	cin >> vertexCount >> edgeCount;

	vector<vector<int>>graph(vertexCount);
	vector<int>traversal;

	for (int i = 0; i < edgeCount; i++) {
		int vertex1, vertex2, weight;
		cin >> vertex1 >> vertex2 >> weight;

		graph[vertex1].push_back(vertex2);
		graph[vertex2].push_back(vertex1);
	}

	return 0;
}
