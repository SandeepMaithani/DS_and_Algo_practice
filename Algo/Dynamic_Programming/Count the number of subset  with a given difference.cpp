#include<bits/stdc++.h>
using namespace std;

//Bottom - Up

int main() {
	
	int n,diff,sum,range = 0,count;
	cin>>n>>diff;
	
	vector<int>num(n);
	
	for(int i=0;i<n;i++) {
		cin>>num[i];
		range += num[i];
	}
	
	if((diff+range)%2 == 1) {
		count = 0;
	}
	else {
		sum = (diff+range)/2;
		
		vector<vector<int>>dp(n+1,vector<int>(sum+1));
		
		for(int i=0;i<=n;i++) {
			dp[i][0] = 1;
		}
		
		for(int j=1;j<=sum;j++) {
			dp[0][j] = 0;
		}
		
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=sum;j++) {
				if(num[i-1] <= j) {
					
					int pick = dp[i-1][j-num[i-1]];
					int drop = dp[i-1][j];
					
					dp[i][j] = pick + drop;
				}
				else {
					dp[i][j] = dp[i-1][j];
				}
			}
		}
		
		count = dp[n][sum];
	}
	
	cout<<"No of subset will be :  "<<count<<endl;

	return 0;	
}

//Recursion + Memoization

/*

int subsetcount(vector<int>&num,vector<vector<int>>&dp,int sum,int n) {
	if(sum == 0) {
		dp[n][sum] = 1;
		return 1;
	}
	if(sum != 0 && n == 0) {
		dp[n][sum] = 0;
		return 0;
	}
	
	if(dp[n][sum] != -1) {
		return dp[n][sum];
	}
	
	if(num[n-1] <= sum) {
		int pick = subsetcount(num,dp,sum-num[n-1],n-1);
		int drop = subsetcount(num,dp,sum,n-1);
		
		dp[n][sum] = pick + drop;
		return dp[n][sum];
		
	}
	else {
		dp[n][sum] = subsetcount(num,dp,sum,n-1);
		return dp[n][sum]; 
	}
	
}

int main() {
	
	int n,diff,sum,range = 0,count;
	cin>>n>>diff;
	
	vector<int>num(n);
	
	for(int i=0;i<n;i++) {
		cin>>num[i];
		range += num[i];
	}
	
	if((diff+range)%2 == 1) {
		count = 0;
	}
	else {
		sum = (diff+range)/2;
		
		vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
		count = subsetcount(num,dp,sum,n);
	}
	
	cout<<"No of subset will be :  "<<count<<endl;

	return 0;	
}

*/
