#include<bits/stdc++.h> 
using namespace std; 
  

int minCoins(vector<int> &change, int amt, int denom) 
{ 
    /* dp[i] will be storing the minimum number of coins 
       required for i value.  So dp[amt] will have result
	*/ 
    
    vector<int>dp(amt+1);
	  
    // Base case (If given value amt is 0)
	
	dp[0] = 0; 
    
  
    /*Initialize all table values as Infinite 
      Compute minimum coins required for all 
      values from 1 to V
	*/
	
	for(int i=1;i<=amt;i++) {
		dp[i] = INT_MAX;
		
		for(int j=0;j<change.size();j++) {
			
			// Go through all coins smaller than i 
			
			if(change[j] <= i) {
				int curmin = dp[i-change[j]] + 1;
				if(curmin < dp[i]) {
					dp[i] = curmin;
				}
			}
		}
	}
        
    return dp[amt];
        
} 
  

int main() 
{ 
    int amt;
    cout<<"Enter amount to get change :- "<<endl;
    cin>>amt;
    
    vector<int>change{10, 6, 1}; 
    int denom = change.size();
    
    cout<<"Minimum numbers of coin change will be :- "<< minCoins(change, amt, denom); 
    return 0; 
} 
