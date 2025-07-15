#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    ll get_ops(vector<int> &nums,int st){
        ll n=nums.size(),ret=0;
        ll od=0,ev=0;
        if(st==0){
            ev=0,od=1;
        }else{
            od=0,ev=1;
        }

        for(int i=0;i<n;i++){
            if(nums[i]%2){
                ret = ret + abs(od-i);
                od+=2;
            }else{
                ret = ret + abs(ev-i);
                ev+=2;
            }
        }
    
        return ret/2ll;
    }
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        int cnt_ev=0,cnt_od=0;
        for(int i=0;i<n;i++){
            if(nums[i]%2){
                cnt_od++;
            }else{
                cnt_ev++;
            }
        }

        if(abs(cnt_od-cnt_ev)>1){
            return -1;
        }

        ll ret=n;
        if(cnt_od == cnt_ev){
            ret=min(get_ops(nums,0),get_ops(nums,1));
        }else if(cnt_od>cnt_ev){
            ret=get_ops(nums,1);
        }else{
            ret=get_ops(nums,0);
        }
        
        return ret;

    }
};