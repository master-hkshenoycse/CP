#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int triangularSum(vector<int>& nums) {
        
        vector<int> tmp;
        tmp=nums;
        
        while(tmp.size()>0){
            int n=tmp.size();
            vector<int> nx;
            for(int i=1;i<n;i++){
                nx.push_back((tmp[i]+tmp[i-1])%10);
            }
            tmp=nx;
        }
        
        
        return tmp[0];
        
        
    }
};