#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    char str[100005];
    int minCost(string s, vector<int>& cost) {
        int ma_cost=0;
        int dup=1;
        int c=0;
        int ma=0;
        
        int n=s.size();
        
        
        for(int i=1;i<=n;i++) str[i]=s[i-1]; 
        int tc=0;
        for(int i=1;i<=n;i++){
            if(str[i]!=str[i-1]){
                ma_cost+=ma;
                ma=cost[i-1];
            }
            else{
                ma=max(ma,cost[i-1]);
            }
            tc+=cost[i-1];
        }
       
        if(ma)ma_cost+=ma;
       
        return tc-ma_cost;
        
    }
};