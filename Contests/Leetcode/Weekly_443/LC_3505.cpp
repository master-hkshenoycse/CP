#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    
    ll get_median(multiset<ll> &top_set,multiset<ll> &bot_set){
        
        if(top_set.size() >= bot_set.size()){
            return *top_set.begin();
        }

        return  *(--bot_set.end());
    }
    void balance(multiset<ll> &top_set,multiset<ll> &bot_set,ll &top_sum,ll &bot_sum){

        ll top_sz=top_set.size();
        ll bot_sz=bot_set.size();

        if(abs(top_sz-bot_sz)<=1){
            return ;
        }

        if(top_sz > bot_sz){
            ll val=*top_set.begin();
            top_sum-=(val);
            top_set.erase(top_set.begin());

            bot_set.insert(val);
            bot_sum+=val;
        }else{

            ll val= *(--bot_set.end());
            bot_sum-=val;
            bot_set.erase(--bot_set.end());

            top_set.insert(val);
            top_sum+=val;
        }
    }
    long long minOperations(vector<int>& nums, int x, int k) {
        ll n=nums.size();


        vector<ll> get_ops(n+1,0);
        multiset<ll> top_set,bot_set;
        
        ll median=0,top_sum=0,bot_sum=0;

        for(ll i=1;i<=n;i++){

            if(nums[i-1]>=median){
                top_set.insert(nums[i-1]);
                top_sum+=nums[i-1];
            }else{
                bot_set.insert(nums[i-1]);
                bot_sum+=nums[i-1];
            }

            balance(top_set,bot_set,top_sum,bot_sum);


            if(i-x>=1){

                if(top_set.find(nums[i-x-1]) != top_set.end()){
                    top_set.erase(top_set.find(nums[i-x-1]));
                    top_sum-=nums[i-x-1];
                }else{
                    bot_set.erase(bot_set.find(nums[i-x-1]));
                    bot_sum-=nums[i-x-1];
                }

                balance(top_set,bot_set,top_sum,bot_sum);
            }

            median = get_median(top_set,bot_set);
            if(i>=x){
                //  cout<<i<<" "<<median<<" "<<top_set.size()<<" "<<bot_set.size()<<endl;
                ll gt_cnt=top_set.size();
                ll ls_cnt=bot_set.size();
                get_ops[i]=(median*ls_cnt- bot_sum)+(top_sum-median*gt_cnt);
                //cout<<i<<" "<<get_ops[i]<<endl;
            }
        }

        
        vector<vector<ll> > dp(n+1,vector<ll> (k+1,1e18));
        dp[0][0]=0;
        
        for(ll i=1;i<=n;i++){
            for(ll j=0;j<=k;j++){
                dp[i][j]=dp[i-1][j];
                
                if(i-x>=0 && j>0){
                    dp[i][j]=min(dp[i][j],dp[i-x][j-1]+get_ops[i]);
                }
                
            }
        }
        
        return dp[n][k];
        
    }
};