#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int maxScoreSubseq(int n, vector<int> &arr) {
        // code here
        map<int,int> help;
        int ma=INT_MIN;
        for(int i=0;i<n;i++){
            ma=max(ma,arr[i]);
        }
        
        if(ma<0){
            return ma;
        }
        
        int ans=0;
        for(int i=0;i<n;i++){
            help[arr[i]-i]+=max(0,arr[i]);
            ans=max(ans,help[arr[i]-i]);
        }
        
        return ans;
    }
};