#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define endl "\n"
typedef long long int ll;

bool hasPath(vector<vector<int>>&graph, vector<bool> &visited, int source, int destination) {
	if (source == destination) {
		return true;
	}

	visited[source] = true;

	for (int i = 0; i < graph[source].size(); i++) {
		int neighbor = graph[source][i];

		if (visited[neighbor] == false) {
			bool pathPossible = hasPath(graph, visited, neighbor, destination);

			if (pathPossible == true) {
				return true;
			}
		}
	}

	return false;
}

int main() {

	int vertexCount, edgeCount, source, destination;
	cin >> vertexCount >> edgeCount;

	vector<vector<int>>graph(vertexCount);
	vector<bool>visited(vertexCount, false);

	for (int i = 0; i < edgeCount; i++) {
		int vertex1, vertex2;
		cin >> vertex1 >> vertex2;

		graph[vertex1].push_back(vertex2);
		graph[vertex2].push_back(vertex1);
	}

	cout << hasPath(graph, visited, source, destination) << endl;

	return 0;
}