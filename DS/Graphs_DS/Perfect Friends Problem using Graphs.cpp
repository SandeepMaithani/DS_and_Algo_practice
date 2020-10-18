#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define endl "\n"
typedef long long int ll;

void componentHelper(vector<vector<int>>& graph, vector<bool>& visited, vector<int>& component, int source) {
	visited[source] = true;
	component.push_back(source);

	for (auto neighbor : graph[source]) {
		if (visited[neighbor] == false) {
			componentHelper(graph, visited, component, neighbor);
		}
	}
}

void getConnectedComponent(vector<vector<int>>& graph, vector<vector<int>>& componentHolder, vector<bool> &visited) {
	for (int i = 0; i < visited.size(); i++) {
		if (visited[i] == false) {
			vector<int>component;
			componentHelper(graph, visited, component, i);
			componentHolder.push_back(component);
		}
	}
}

int main() {

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

	getConnectedComponent(graph, componentHolder, visited);

	for (int i = 0; i < componentHolder.size(); i++) {
		for (int j = i + 1; j < componentHolder.size(); j++) {
			int ways = componentHolder[i].size() * componentHolder[j].size();
			pairCount += ways;
		}
	}

	cout << pairCount << endl;

	return 0;
}
