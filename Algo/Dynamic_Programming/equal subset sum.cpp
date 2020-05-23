#include<bits/stdc++.h>
using namespace std;

//Method - 1 (Top - down)

int main() {
	
	int n,eqsum,sum = 0;
	cin>>n;
	
	vector<int>num(n);
	
	for(int i=0;i<n;i++) {
		cin>>num[i];
		sum = sum+num[i];
	}
	
	if(sum%2 != 0) {
		cout<<"Given set can not divided into equal sum subset\n";
	}
	else {
		
		eqsum = sum/2;
		vector<vector<bool>>dp(n+1,vector<bool>(eqsum+1));
		
		for(int i=0;i<=n;i++) {
			dp[i][0] = true;
		}
		
		for(int j=1;j<=eqsum;j++) {
			dp[0][j] = false;
		}
		
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=eqsum;j++) {
				if(num[i-1] <= j) {
					bool pick = dp[i-1][j-num[i-1]]; 
					bool drop = dp[i-1][j];
					
					dp[i][j] = pick||drop;
				}
				else {
					dp[i][j] = dp[i-1][j];
				}
			}
		}
		
		if(dp[n][eqsum]) {
			cout<<"We can divide given set into equal sum subset\n";
		}
		else {
			cout<<"Given set can not divided into equal sum subset\n";
		}
		
	}
	
	return 0;
}

//Method - 2 (Recursion + memoization)

/*
bool equalpart(vector<int>&num,vector<vector<int>>&dp,int sum,int n) {
	if(sum == 0) {
		return true;
	}
	
	if(sum !=0 && n == 0) {
		return false;
	}
	
	if(dp[n][sum] != -1) {
		if(dp[n][sum]) {
			return true;
		}
		else {
			return false;
		}
	}
	
	if(num[n-1] <= sum) {
		
		bool pick = equalpart(num,dp,sum-num[n-1],n-1);
		bool drop = equalpart(num,dp,sum,n-1);
		
		if (pick || drop) {
			dp[n][sum] = 1;			
		}
		else {
			dp[n][sum] = 0;
		}
		
		return (pick||drop);
	}
	else {
		
		if (equalpart(num,dp,sum,n-1)) {
			dp[n][sum] = 1;			
		}
		else {
			dp[n][sum] = 0;
		}
		
		if(dp[n][sum]) {
			return true;
		}
		else {
			return false;
		}
	}
}

int main() {
	
	int n,eqsum,sum = 0;
	cin>>n;
	
	vector<int>num(n);
	
	for(int i=0;i<n;i++) {
		cin>>num[i];
		sum = sum+num[i];
	}
	
	if(sum%2 != 0) {
		cout<<"Given set can not divided into equal sum subset\n";
	}
	else {
		
		eqsum = sum/2;
		
		vector<vector<int>>dp(n+1,vector<int>(eqsum+1,-1));
		
		if(equalpart(num,dp,eqsum,n)) {
		    dp[n][eqsum] = 1;
		}
	    else {
		    dp[n][eqsum] = 0;
		}
		
		if(dp[n][eqsum]) {
		    cout<<"We can divide given set into equal sum subset\n";
		}
	    else {
		    cout<<"Given set can not divided into equal sum subset\n";
		}
	}
	
	return 0;
}

*/
