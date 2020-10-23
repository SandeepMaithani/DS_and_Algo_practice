#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define endl "\n"
typedef long long int ll;

int spotInfection(vector <vector<int>>& graph, int person, int timeGiven) {
	vector<int>visitedAt(graph.size(), 0);
	int count = 0;

	queue<pair<int, int>>bfsHelper;
	bfsHelper.push({person, 1});

	while (!bfsHelper.empty()) {
		pair<int, int>currentPerson = bfsHelper.front();
		bfsHelper.pop();

		if (visitedAt[currentPerson.first] != 0) {
			continue;
		}

		visitedAt[currentPerson.first] = currentPerson.second;
		if (currentPerson.second > timeGiven) {
			break;
		}

		count++;

		for (auto neighbour : graph[currentPerson.first]) {
			if (visitedAt[neighbour] == 0) {
				bfsHelper.push({neighbour, currentPerson.second + 1});
			}
		}
	}

	return count;
}

int main() {

	int vertexCount, edgeCount, person, time;
	cin >> vertexCount >> edgeCount;

	vector<vector<int>>graph(vertexCount);
	vector<int>traversal;

	for (int i = 0; i < edgeCount; i++) {
		int vertex1, vertex2;
		cin >> vertex1 >> vertex2;

		graph[vertex1].push_back(vertex2);
		graph[vertex2].push_back(vertex1);
	}

	cin >> person >> time;

	cout << spotInfection(graph, person, time) << endl;

	return 0;
}


