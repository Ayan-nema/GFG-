#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
      string decodedString(string &s) {
          // code here
          stack<char> charstk;
          stack<int> intstk;
          string temp="";
          string res="";
         
          
          for(int i=0;i<s.length();i++)
          {
              int count=0;
              if(s[i]>='0' && s[i]<='9')
              { 
                  while(s[i]>='0' && s[i]<='9')
                  {
                      count=count*10 + s[i]-'0';
                      i++;
                  }
              intstk.push(count);
              i--;
              
              }
              else if(s[i]==']')
              { temp="";
                  count = intstk.top();
                  intstk.pop();
                  
                  while(charstk.top()!='[')
                  {
                      temp=charstk.top()+temp;
                      charstk.pop();
                  }
                  charstk.pop();
                  
                  for(int j=0;j<count;j++)
                  {
                      res=res.append(temp);
                  }
                  
                  for(int j=0;j<res.length();j++)
                  {
                      charstk.push(res[j]);
                  }
                  
                  res="";
              }
              else
              {
                  charstk.push(s[i]);
              }
          }
          while(!charstk.empty())
          {
              res=charstk.top()+res;
              charstk.pop();
          }
          return res;
          
      }
  };