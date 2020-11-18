#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define endl "\n"
typedef long long int ll;

void iterativeDFS(vector<vector<int>>& graph, vector<bool>& visited, int source) {
	stack<pair<int, string>>dfsHelper;
	dfsHelper.push({source, to_string(source)});

	while (!dfsHelper.empty()) {
		pair<int, string>vertexInfo = dfsHelper.top();
		dfsHelper.pop();

		int curVertex = vertexInfo.first;
		string psf = vertexInfo.second;

		if (visited[curVertex] == true) {
			continue;
		}

		visited[curVertex] = true;

		cout << curVertex << " via " << psf << endl;

		for (auto neighbour : graph[curVertex]) {
			if (visited[neighbour] == false) {
				dfsHelper.push({neighbour, psf + to_string(neighbour)});
			}
		}
	}
}

int main() {

	int vertexCount, edgeCount, source;
	cin >> vertexCount >> edgeCount;

	vector<vector<int>>graph(vertexCount);
	vector<bool>visited(vertexCount, false);

	for (int i = 0; i < edgeCount; i++) {
		int vertex1, vertex2;
		cin >> vertex1 >> vertex2;

		graph[vertex1].push_back(vertex2);
		graph[vertex2].push_back(vertex1);
	}

	cin >> source;

	iterativeDFS(graph, visited, source);

	return 0;
}


