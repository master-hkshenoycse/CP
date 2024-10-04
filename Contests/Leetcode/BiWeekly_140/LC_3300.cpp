#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int get_sod(int n){
        int s=0;
        while(n>0){
            s=s+(n%10);
            n/=10;
        }
        return s;
    }
    int minElement(vector<int>& nums) {
        int ans=1e9;
        for(auto e:nums){
            ans=min(ans,get_sod(e));
        }
        return ans;
    }
};