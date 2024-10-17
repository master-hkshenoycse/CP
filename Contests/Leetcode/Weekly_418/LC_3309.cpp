#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string get_rep(int n){
        string ret;
        while(n>0){
            ret+=char('0'+n%2);
            n/=2;
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }

    int get_val(string &s){
        int ret=0;
        for(auto ch:s){
            ret=ret*2+(ch-'0');
        }
        return ret;
    }
    int maxGoodNumber(vector<int>& nums) {
        vector<int> ord;
        int n=nums.size();
        for(int i=0;i<n;i++){
            ord.push_back(i);
        }

        int ans=0;
        do{
            string tmp;
            for(int i=0;i<n;i++){
                tmp+=get_rep(nums[ord[i]]);
            }

            ans=max(ans,get_val(tmp));
            

        }while(next_permutation(ord.begin(),ord.end()));

        return ans;
    }
};