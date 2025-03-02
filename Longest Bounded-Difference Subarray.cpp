#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
      vector<int> longestSubarray(vector<int>& arr, int x) {
          // code here
          int n= arr.size();
          int left=0;
          int max_len=0;
          multiset<int> window;
          vector<int> best_yet;
          
          for(int right=0;right<n;right++)
          {
              window.insert(arr[right]);
          
          
          while(*window.rbegin()-*window.begin()>x)
          {
              window.erase(window.find(arr[left]));
              left++;
          }
          
          if(right-left + 1 > max_len)
          {
              max_len=right-left + 1;
              best_yet=vector<int>(arr.begin()+left,arr.begin()+right+1);
          }
          }
          return best_yet;
      }
  };