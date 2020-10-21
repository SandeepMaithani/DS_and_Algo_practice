#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define endl "\n"
typedef long long int ll;

void bfs(vector < vector<int>>& graph, vector<int> &traversal, int N) {

	vector<int>visited(N, false);
	queue<int>bfsHelper;

	bfsHelper.push(0);

	while (!bfsHelper.empty()) {

		int curVertex = bfsHelper.front();
		bfsHelper.pop();

		if (visited[curVertex] == true) {
			continue;
		}

		visited[curVertex] = true;
		traversal.push_back(curVertex);

		for (auto neighbour : graph[curVertex]) {
			if (visited[neighbour] == false) {
				bfsHelper.push(neighbour);
			}
		}
	}
}


int main() {

	int vertexCount, edgeCount;
	cin >> vertexCount >> edgeCount;

	vector<vector<int>>graph(vertexCount);
	vector<int>traversal;

	for (int i = 0; i < edgeCount; i++) {
		int vertex1, vertex2;
		cin >> vertex1 >> vertex2;

		graph[vertex1].push_back(vertex2);
		graph[vertex2].push_back(vertex1);
	}

	bfs(graph, traversal, graph.size());

	for (auto it : traversal) {
		cout << it << " ";
	}

	return 0;
}


