#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define endl "\n"
typedef long long int ll;

int main() {

	int vertexCount, edgeCount;
	cin >> vertexCount >> edgeCount;

	vector<vector<int>>graph(vertexCount, vector<int>);

	for (int i = 0; i < edgeCount; i++) {
		int vertex1, vertex2;
		cin >> vertex1 >> vertex2;

		graph[vertex1].push_back(vertex2);
		graph[vertex2].push_back(vertex1);
	}

	return 0;
}