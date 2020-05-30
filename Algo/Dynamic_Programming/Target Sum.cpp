/*

we can't make sum = 0 as base case here because there are many ways to create sum = 0 

for eg [0,0,0,0,0,0,0,0,1] and target = 1

here answer will 256

there for only dp[0][0] = 1 and rest dp[0][j] = 0 this will be out base case 
only first row of dp array will act as base condition here

*/

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        
        int n = nums.size();
        long long int range = 0,answer = 0,subsum;
        for(int i=0;i<n;i++) {
            range += nums[i];
        }
        
        if((range+S)%2 == 1 || range < S) {
            return answer;
        }
        else {
            subsum = (range+S)/2;
            vector<vector<int>>dp(n+1,vector<int>(subsum+1));
    
                dp[0][0] = 1; 
            
            for(int j=1;j<=subsum;j++) {
                dp[0][j] = 0;
            }
            for(int i=1;i<=n;i++) {
                for(int j=0;j<=subsum;j++) {
                    
                    if(nums[i-1] <= j) {
                        int pick = dp[i-1][j-nums[i-1]];
                        int drop = dp[i-1][j];
                        dp[i][j] = pick+drop;
                    }
                    else {
                        dp[i][j] = dp[i-1][j];
                    }    
                }
            }
            
            answer = dp[n][subsum];
            
        }
        
        return answer;        
    }
};
