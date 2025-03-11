#include<bits/stdc++.h>
using namespace std;
//top down approach with memoization
class Solution {
    public:
        int minCostClimbingStairs(vector<int>& cost) {
            int len = cost.size();
            vector<int> dp(len, -1);
            return min(minCost(cost, dp, len - 1), minCost(cost, dp, len - 2));
        }
    
    private:
        int minCost(vector<int>& cost, vector<int>& dp, int i) {
            if (i < 0) {
                return 0;
            }
            
            if (dp[i] != -1) {
                return dp[i];
            }
            
            dp[i] = cost[i] + min(minCost(cost, dp, i - 1), minCost(cost, dp, i - 2));
            return dp[i];
        }
    };

//bottom up approach
class Solution {
    public:
        int minCostClimbingStairs(vector<int>& cost) {
            int len = cost.size();
            vector<int> dp(len + 1, 0);
            dp[0] = cost[0];
            dp[1] = cost[1];
            
            for (int i = 2; i < len; i++) {
                dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
            }
            
            return min(dp[len - 1], dp[len - 2]);
        }
    };

    //bottom up approach with space optimization
class Solution {
    public:
        int minCostClimbingStairs(vector<int>& cost) {
            int len = cost.size();
            int first = cost[0];
            int second = cost[1];
            
            for (int i = 2; i < len; i++) {
                int curr = cost[i] + min(first, second);
                first = second;
                second = curr;
            }
            
            return min(first, second);
        }
    };
// Time Complexity: O(n)