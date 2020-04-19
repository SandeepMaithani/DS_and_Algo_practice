#include<bits/stdc++.h>
using namespace std;

vector<int> graph[10];

/*

Consider a directed graph 

Sample Input

4    ->  no of  nodes
5    ->  no of  edges
1 2  ->  showing edge from node 1 to node 2
2 4  ->  showing edge from node 2 to node 4
3 1  ->  showing edge from node 3 to node 1
3 4  ->  showing edge from node 3 to node 4
4 2  ->  showing edge from node 4 to node 2

*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int x,y,nodes, edges;
	
	//Number of nodes
	      
    cin >> nodes; 
	
	//Number of edges
	      
    cin >> edges; 

	
	for(int i = 0; i < edges; i++) {
		
		cin>>x>>y;
		
		//Insert y in adjacency list of x
			
		graph[x].push_back(y);	
	}
	
	for(int i = 1; i <= nodes; i++) {
		
		cout << "Adjacency list of node " << i << ": ";
		
		for(int j = 0; j < graph[i].size(); j++) {
			
			if(j == graph[i].size()-1) {
				cout<< graph[i][j]<<endl;
			}
			else {
				cout<< graph[i][j]<<" --> ";
			}
		}
	}
	
	return 0;
}
