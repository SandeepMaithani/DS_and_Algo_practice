#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define endl "\n"
typedef long long int ll;


void topologicalSortHelper(vector<vector<int>>& graph, vector<bool>& visited, stack<int>& st, int source) {
	visited[source] = true;

	for (auto neighbour : graph[source]) {
		if (visited[neighbour] == false) {
			topologicalSortHelper(graph, visited, st, neighbour);
		}
	}
	st.push(source);
}


void topologicalSort(vector<vector<int>>& graph, vector<bool>& visited) {
	stack<int>st;

	for (int vertex = 0; vertex < graph.size(); vertex++) {
		if (visited[vertex] == false) {
			topologicalSortHelper(graph, visited, st, vertex);
		}
	}

	while (!st.empty()) {
		cout << st.top() << " ";
		st.pop();
	}
}

int main() {

	int vertexCount, edgeCount;
	cin >> vertexCount >> edgeCount;

	vector<vector<int>>graph(vertexCount);
	vector<bool>visited(vertexCount, false);

	for (int i = 0; i < edgeCount; i++) {
		int vertex1, vertex2;
		cin >> vertex1 >> vertex2;

		graph[vertex1].push_back(vertex2);
	}

	topologicalSort(graph, visited);

	return 0;
}


