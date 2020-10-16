#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define endl "\n"
typedef long long int ll;

void componentHelper(vector<vector<int>> &graph, vector<bool> &visited, vector<int> &component, int source) {
	visited[source] = true;
	component.push_back(source);

	for (auto neighbor : graph[source]) {
		if (visited[neighbor] == false) {
			componentHelper(graph, visited, component, neighbor);
		}
	}
}

vector<vector<int>>getConnectedComponent(vector<vector<int>>&graph, vector<bool> &visited) {
	vector<vector<int>>componentHolder;

	for (int i = 0; i < visited.size(); i++) {
		if (visited[i] == false) {
			vector<int>component;
			componentHelper(graph, visited, component, i);
			componentHolder.push_back(component);
		}
	}

	return componentHolder;
}

int main() {

	int vertexCount, edgeCount, source, destination;
	cin >> vertexCount >> edgeCount;

	vector<vector<int>>graph(vertexCount);
	vector<bool>visited(vertexCount, false);

	for (int i = 0; i < edgeCount; i++) {
		int vertex1, vertex2, weight;
		cin >> vertex1 >> vertex2 >> weight;

		graph[vertex1].push_back(vertex2);
		graph[vertex2].push_back(vertex1);
	}

	vector<vector<int>>componentHolder = getConnectedComponent(graph, visited);

	for (int i = 0; i < componentHolder.size(); i++) {
		for (int j = 0; j < componentHolder[i].size(); j++) {
			cout << componentHolder[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}


