#include<bits/stdc++.h>
using namespace std;

//Bottom Up

int main() {
	
	int n,w;
	cin>>n>>w;
	
	vector<int>wt(n);
	vector<int>val(n);
	
	vector<vector<int>>dp(n+1,vector<int>(w+1,0));
	
	for(int i=0;i<n;i++) {
		cin>>wt[i];
	}
	
	for(int i=0;i<n;i++) {
		cin>>val[i];
	}
	
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=w;j++) {
			if(wt[i-1] <= j) {
				int pick = val[i-1] + dp[i][j-wt[i-1]];
				int drop = dp[i-1][j];
				
				dp[i][j] = max(pick,drop);
			}
			else {
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	
	int answer = dp[n][w];
	
	cout<<answer<<endl;
	
	return 0;
}

//Recursion + Memoization

/*
int ubknapsack(vector<int>&wt,vector<int>&val,vector<vector<int>>&dp,int w,int n) {
	if(n == 0) {
		dp[n][w] = 0;
		return 0;
	}
	if(w == 0) {
		dp[n][w] = 0;
		return 0;
	}
	
	if(dp[n][w]!= -1) {
		return dp[n][w];
	}
	
	if(wt[n-1] <= w) {
		int pick = val[n-1] + ubknapsack(wt,val,dp,w-wt[n-1],n);
		int drop = ubknapsack(wt,val,dp,w,n-1);
		
		dp[n][w] = max(pick,drop);
		return dp[n][w];	
	}
	else {
		dp[n][w] = ubknapsack(wt,val,dp,w,n-1);
		return dp[n][w];
	}	
}

int main() {
	
	int n,w;
	cin>>n>>w;
	
	vector<int>wt(n);
	vector<int>val(n);
	
	vector<vector<int>>dp(n+1,vector<int>(w+1,-1));
	
	for(int i=0;i<n;i++) {
		cin>>wt[i];
	}
	
	for(int i=0;i<n;i++) {
		cin>>val[i];
	}
	
	int answer = ubknapsack(wt,val,dp,w,n);
	
	cout<<answer<<endl;
	
	return 0;
}

*/

