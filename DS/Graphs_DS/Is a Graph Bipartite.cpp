#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define endl "\n"
typedef long long int ll;

bool bipartiteHelper(vector<vector<int>>& graph, vector<int>& visitedAt, int src) {
	queue<pair<int, int>>bfsHelper;
	bfsHelper.push({src, 0});

	while (!bfsHelper.empty()) {
		pair<int, int> currentNode = bfsHelper.front();
		bfsHelper.pop();

		if (visitedAt[currentNode.first] != -1) {
			if (currentNode.second != visitedAt[currentNode.first]) {
				return false;
			}
		}
		else {
			visitedAt[currentNode.first] = currentNode.second;
		}

		for (auto neighbour : graph[currentNode.first]) {
			if (visitedAt[neighbour] == -1) {
				bfsHelper.push({neighbour, currentNode.second + 1});
			}
		}
	}
	return true;
}

bool isBipartite(vector<vector<int>>& graph) {

	vector<int>visitedAt(graph.size(), -1);

	for (int i = 0; i < graph.size(); i++) {
		if (visitedAt[i] == -1) {
			bool isBipt = bipartiteHelper(graph, visitedAt, i);

			if (isBipt == false) {
				return false;
			}
		}
	}

	return true;
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

	if (isBipartite(graph)) {
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}

	return 0;
}
