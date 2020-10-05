#include <bits/stdc++.h>
using namespace std;

bool A[10][10];

//Function to set all adjacency matrix element to zero initially

void initialize()
{
    for(int i = 0;i < 10;++i)
	    for(int j = 0;j < 10;++j)
            A[i][j] = false;
}

/*

4    ->  no of  nodes
5    ->  no of  edges
1 2  ->  showing edge from node 1 to node 2
2 4  ->  showing edge from node 2 to node 4
3 1  ->  showing edge from node 3 to node 1
3 4  ->  showing edge from node 3 to node 4
4 2  ->  showing edge from node 4 to node 2

*/


int main()
{
    int x, y, nodes, edges;
    
    //Since there is no edge initially
    
    initialize(); 
	
	//Number of nodes
	      
    cin >> nodes; 
	
	//Number of edges
	      
    cin >> edges;       
    
	for(int i = 0;i < edges;++i) {
		
	    cin >> x >> y;
	    
	    //Mark the edges from vertex x to vertex y
	    
        A[x][y] = true;
		     
	}
	
    if(A[3][4] == true)
       cout << "There is an edge between 3 and 4 " << endl;
       
    else 
        cout << "There is no edge between 3 and 4 " << endl;


    if(A[2][3] == true)
       cout << "There is an edge between 2 and 3" << endl;
       
    else 
        cout << "There is no edge between 2 and 3 " << endl;

    return 0;
}
