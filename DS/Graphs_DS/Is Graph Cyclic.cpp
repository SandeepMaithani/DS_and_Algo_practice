#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define endl "\n"
typedef long long int ll;


bool cyclicHelper(vector<vector<int>>& graph, int source, vector<bool>& visited) {
	queue<int>bfsHelper;
	bfsHelper.push(source);

	while (!bfsHelper.empty()) {

		int currentNode = bfsHelper.front();
		bfsHelper.pop();

		if (visited[currentNode] == true) {
			return true;
		}

		visited[currentNode] = true;
		for (auto neighbour : graph[currentNode]) {
			if (visited[neighbour] == false) {
				bfsHelper.push(neighbour);
			}
		}
	}
	return false;
}


bool isCyclic(vector<vector<int>>& graph, int V)
{
	vector<bool>visited(V, false);

	for (int i = 0; i < V; i++) {
		if (visited[i] == false) {
			bool cycleDetected = cyclicHelper(graph, i, visited);

			if (cycleDetected) {
				return true;
			}
		}
	}

	return false;
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

	cout << isCyclic(graph, graph.size()) << endl;

	return 0;
}


