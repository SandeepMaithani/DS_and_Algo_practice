#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define endl "\n"
typedef long long int ll;

void hamiltonianHelper(vector<vector<int>>& graph, unordered_set<int>& hashSet, int source, string path, int initialPoint) {

	if (hashSet.size() == graph.size() - 1) {
		cout << path << endl;

		bool isCycle = false;

		for (auto neighbor : graph[source]) {
			if (neighbor == initialPoint) {
				isCycle = true;
				break;
			}
		}

		if (isCycle) {
			cout << "hamiltonian Cycle" << endl;
		}
		else {
			cout << "hamiltonian path" << endl;
		}

		return;
	}

	hashSet.insert(source);

	for (auto neighbor : graph[source]) {
		if (hashSet.find(neighbor) == hashSet.end()) {
			hamiltonianHelper(graph, hashSet, neighbor, path + to_string(neighbor), initialPoint);
		}
	}

	hashSet.erase(source);
}



int main() {

	int vertexCount, edgeCount, initialPoint, source;
	cin >> vertexCount >> edgeCount;

	vector<vector<int>>graph(vertexCount);
	unordered_set<int>hashSet;

	for (int i = 0; i < edgeCount; i++) {
		int vertex1, vertex2;
		cin >> vertex1 >> vertex2;

		graph[vertex1].push_back(vertex2);
		graph[vertex2].push_back(vertex1);
	}

	cin >> source;

	hamiltonianHelper(graph, hashSet, source, to_string(source) + "", source);

	return 0;
}