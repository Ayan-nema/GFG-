#include <bits/stdc++.h>
using namespace std;

// Recurrsive and memoization approach
class Solution {
    public:
      int n;
      int t[1001][1001];
      int solve(vector<int>arr, int i, int P)
      {
          
          if(i>=n)
          return 0;
          
          if(P!=-1 && t[i][P]!=-1)
          return t[i][P];
          
          int take=0;
          
          if( P==-1 || arr[i]>arr[P])
          {
              take=1+solve(arr,i+1,i);
          }
          int skip=solve(arr, i+1, P);
          
          if(P!=-1)
          {
              t[i][P] = max(take,skip);
          }
          
          return max(take,skip);
      }
      int lis(vector<int>& arr) {
          // code here
          n=arr.size();
          memset(t,-1,sizeof(t));
          return solve(arr,0,-1);
      }
  };

  // Bottom up approach
  
class Solution {
    public:
      int lis(vector<int>& nums) {
          // code here
          int n =nums.size();
          vector<int> t(n,1);
          int maxL=1;
          for(int i=0;i<n;i++)
          {
              for(int j=0;j<i;j++)
              {   
                  if(nums[j]<nums[i]){
                      
                  t[i]=max(t[i],t[j]+1);
                  maxL=max(maxL,t[i]);
                  
                  }
                  
              }
          }
          return maxL;
      }
  };