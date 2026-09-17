#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        ll cnt_ls=0,cnt_bt=0,cnt_gt=0;
        ll mod=1e9+7,swaps=0;
        for(auto e:nums){
            if(e<a){
                swaps=(swaps+cnt_bt+cnt_gt)%mod;
                cnt_ls++;
            }else if(e>=a && e<=b){
                swaps=(swaps+cnt_gt)%mod;
                cnt_bt++;
            }else{
                cnt_gt++;
            }
        }
        return swaps;
    }
};