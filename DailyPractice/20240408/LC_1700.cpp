#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
       int n=students.size();
       queue<pair<int,int> > q;
       stack<int> s;
        
       for(int i=0;i<n;i++)q.push({i,students[i]});
       for(int i=n-1;i>=0;i--)s.push(sandwiches[i]);
        
       vector<int> vis(n,0);
     
       while(q.size()){
           auto v=q.front();
           q.pop();
           
           if(v.second == s.top()){
               s.pop();
               continue;
           }
           q.push(v);
           if(vis[v.first]>n){
               break;
           }
           vis[v.first]++;
       } 
        
        
      return q.size();
    }
};