#include<bits/stdc++.h>
using namespace std;

//Method - 1 (Top - down)

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n,cap;
	
	cout<<"Enter no of item :- \n";
	cin>>n;
	cout<<"Enter the capacity of knapsack :- \n";
	cin>>cap;
	
	vector<int>weight(n);
	vector<int>profit(n);
	vector<vector<int>>dp(n+1,vector<int>(cap+1));
	
	cout<<"Enter weight and profit of item :- \n";
	
	for(int i=0;i<n;i++) {
		cin>>profit[i];
	}
	
	for(int i=0;i<n;i++) {
		cin>>weight[i];
	}
	
	for(int i=0;i<=n;i++) {
		dp[i][0] = 0;
	}
	
	for(int j=0;j<=cap;j++) {
		dp[0][j] = 0;
	}
	
	
	for(int i=1;i<=n;i++) {
	    for(int j=1;j<=cap;j++) {
		    
		    if(weight[i-1] <= j) {
		    	dp[i][j] = max(profit[i-1]+dp[i-1][j-weight[i-1]],dp[i-1][j]);
			}
			else {
				dp[i][j] = dp[i-1][j];
			}
		}
	}
		
	cout<<dp[n][cap]<<"\n";
	
	return 0;
}


//Method - 2 (Recursion + memoization)

/*

int knaps(vector<int> &weight,vector<int> &profit,vector<vector<int>>&dp,int cap,int n) {
	
	if(n == 0 || cap == 0) {
		return 0;
	}
 
	if(dp[n][cap] != -1) {
		return dp[n][cap];
	}
	
	if(weight[n-1] <= cap) {
		
		int pick = profit[n-1] + knaps(weight,profit,dp,cap-weight[n-1],n-1);
		int drop = knaps(weight,profit,dp,cap,n-1);
		dp[n][cap] = max(pick,drop);
		return dp[n][cap];		
	}
	else {
		dp[n][cap] = knaps(weight,profit,dp,cap,n-1);
		return dp[n][cap];
	}
}
 
int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n,cap,solution;
	
	cin>>n;
	cin>>cap;
	
	vector<vector<int>>dp(n+1,vector<int>(cap+1,-1));
	vector<int>weight(n);
	vector<int>profit(n);
	
	for(int i=0;i<n;i++) {
		cin>>profit[i];
	}
 
	for(int i=0;i<n;i++) {
		cin>>weight[i];
	}
	
	solution = knaps(weight,profit,dp,cap,n);
	
	cout<<solution<<"\n";
	
	return 0;
}

*/
