#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        map<int,int> help;
        for(auto b:banned){
            help[b]=1;
        }
        
        int rem=maxSum,ans=0;
        
        for(int i=1;i<=n;i++){
            if(help[i]==0 and rem>=i){
                ans++;
                rem-=i;
            }
        }
        
        
        return ans;
    }
};