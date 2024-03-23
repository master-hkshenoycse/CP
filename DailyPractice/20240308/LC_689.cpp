#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {

        int n=nums.size();
        vector<ll> csum(n,0);
        for(ll i=0;i<n;i++){
            csum[i]=nums[i];
            if(i-1>=0){
                csum[i]+=csum[i-1];
            }
        }

        vector<ll> prefix_max_value(n,-1),suffix_max_value(n,-1);
        vector<int> prefix_max_ind(n,-1),suffix_max_ind(n,-1);
        

        for(ll i=0;i<n;i++){
            if(i>=k-1){
                ll sum_ending=csum[i];
                if(i-k>=0){
                    sum_ending-=csum[i-k];
                }
                prefix_max_ind[i]=i-k+1;
                prefix_max_value[i]=sum_ending;

                if(i-1>=0 and prefix_max_value[i-1]>=prefix_max_value[i]){
                    prefix_max_ind[i]=prefix_max_ind[i-1];
                    prefix_max_value[i]=prefix_max_value[i-1];
                }
                
            }
        }

        for(ll i=n-1;i>=0;i--){
            if(i+k-1<n){
                ll sum_ending=csum[i+k-1];
                if(i-1>=0){
                    sum_ending=sum_ending-csum[i-1];
                }

                suffix_max_value[i]=sum_ending;
                suffix_max_ind[i]=i;

                if(i+1<n and suffix_max_value[i+1]>suffix_max_value[i]){
                    suffix_max_value[i]=suffix_max_value[i+1];
                    suffix_max_ind[i]=suffix_max_ind[i+1];
                }
            }
        }

        vector<int> sol={n+1,n+1,n+1};
        ll max_value=0;

        for(int i=0;i<n;i++){
            int st=i;
            int en=i+k-1;


            if(en<n){

                
                ll sum_ending=csum[en];
                if(st-1>=0){
                    sum_ending-=csum[st-1];
                }

                if(st-1>=0 and prefix_max_value[st-1]>0 and en+1<n and suffix_max_value[en+1]>0){
                    ll current=sum_ending+prefix_max_value[st-1]+suffix_max_value[en+1];
                    //cout<<i<<" "<<current<<endl;
                    if(current>max_value){
                        max_value=current;
                        sol={prefix_max_ind[st-1],i,suffix_max_ind[en+1]};
                    }else if(current==max_value){
                        sol=min(sol,{prefix_max_ind[st-1],i,suffix_max_ind[en+1]});
                    }
                }

            }
        }


        return sol;
        
    }
};