#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    void adjust(set<pair<ll,ll> > &top_x,set<pair<ll,ll> > &bot_x,ll x,ll &sum_topx){

        while(top_x.size()<x and bot_x.size()>0){
            auto it=*(--bot_x.end());
            bot_x.erase(it);
            top_x.insert(it);

            sum_topx+=(it.first * it.second);
        }

        while(top_x.size()==x and bot_x.size()>0){
            auto bot_x_best=*(--bot_x.end());
            auto top_x_worst=*(top_x.begin());
            if(top_x_worst < bot_x_best){

                top_x.erase(top_x_worst);
                bot_x.erase(bot_x_best);

                sum_topx-=top_x_worst.first * top_x_worst.second;
                sum_topx+=bot_x_best.first * bot_x_best.second;

                top_x.insert(bot_x_best);
                bot_x.insert(top_x_worst);
                
            }else{
                break;
            }
        }
    }

    vector<int> findXSum(vector<int>& nums, int k, int x) {
        map<ll,ll> freq;
        set<pair<ll,ll> > top_x,bot_x;
        ll sum_topx=0;
        ll n=nums.size();

        vector<int> sol;

        for(ll i=0;i<n;i++){
            
            if(i>=k){
                auto fi=make_pair(freq[nums[i-k]],nums[i-k]*1ll);
                if(top_x.find(fi) != top_x.end()){
                    top_x.erase(fi);
                    sum_topx-=(fi.first * fi.second);
                }else{
                    bot_x.erase(fi);
                }

                freq[nums[i-k]]--;

                if(freq[nums[i-k]]>0){
                    bot_x.insert({freq[nums[i-k]],nums[i-k]});
                }
            }

            auto fi=make_pair(freq[nums[i]],nums[i]);

            if(top_x.find(fi) != top_x.end()){
                top_x.erase(fi);
                sum_topx-=(fi.first * fi.second);
            }else if(bot_x.find(fi) != bot_x.end()){
                bot_x.erase(fi);
            }

            freq[nums[i]]++;
            bot_x.insert({freq[nums[i]],nums[i]});
            
            adjust(top_x,bot_x,x,sum_topx);
            if(i>=k-1){
                sol.push_back(sum_topx);
            }

        }

        return sol;
    }
};