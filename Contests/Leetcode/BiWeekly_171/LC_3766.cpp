#include<bits/stdc++.h>
using namespace std;
vector<int> palins;
int is_done=0;
bool is_palin(int n){
    vector<int> rep;
    while(n>0){
        rep.push_back(n%2);
        n/=2;
    }

    int sz=rep.size();
    for(int i=0;i<sz/2;i++){
        if(rep[i] != rep[sz-i-1])
            return 0;
    }
    return 1;
}
void pre_cum(){
    if(is_done){
        return;
    }

    is_done=1;
    for(int i=1;i<=8192;i++){
        if(is_palin(i)){
            palins.push_back(i);
        }
    }
}
class Solution {
public:
    
    vector<int> minOperations(vector<int>& nums) {
        pre_cum();
        int n=nums.size();
        vector<int> ret;

        for(auto e:nums){
            int ind=lower_bound(palins.begin(),palins.end(),e)-palins.begin();
            int res=palins[ind]-e;
            if(ind-1>=0){
                res=min(res,e-palins[ind-1]);
            }
            ret.push_back(res);
        }

        return ret;
    }
};