#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
      int count(vector<int>& coins, int sum) {
          // code here.
          int  n = coins.size();
          vector<vector<int>> t (n+1,vector<int> (sum+1));
          
          // initialization
          
          for(int i=0;i<n+1;i++)
          {
              for(int j=0;j<sum+1;j++)
              {
                  if(i==0)t[i][j]=0;
                  if(j==0)t[i][j]=1;
              }
          }
          for(int i=1;i<n+1;i++)
          {
              for(int j=0;j<sum+1;j++)
              {
                  if(coins[i-1]<=j)
                  {
                      t[i][j] = t[i-1][j] + t[i][j-coins[i-1]] ;
                  }
                  else 
                  t[i][j]=t[i-1][j];
              }
          }
          return t[n][sum];
      }
  };