#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
    ll prefix_max,suffix_max,max_subarray,tot_sum;
    node(){
        prefix_max=-1e18;
        suffix_max=-1e18;
        max_subarray=-1e18;
        tot_sum=0;
    }
};

class Solution {
public:
    node combine(node &a,node &b){
        node ret;
        ret.tot_sum=a.tot_sum+b.tot_sum;
        ret.prefix_max=max({a.prefix_max,a.tot_sum+b.prefix_max,ret.tot_sum});
        ret.suffix_max=max({b.suffix_max,b.tot_sum+a.suffix_max,ret.tot_sum});
        ret.max_subarray=max({a.max_subarray,b.max_subarray,ret.prefix_max,ret.suffix_max,a.suffix_max+b.prefix_max,ret.tot_sum});
        return ret;
    }
    void upd(int i,int l,int r,int index,int val,vector<node> &tree){
        if(l>r){
            return;
        }

        if(l==r){
            tree[i].tot_sum=val;
            tree[i].prefix_max=val;
            tree[i].suffix_max=val;
            tree[i].max_subarray=val;
            return;
        }

        int mid=(l+r)/2;
        if(index<=mid){
            upd(i*2,l,mid,index,val,tree);
        }else{
            upd(i*2+1,mid+1,r,index,val,tree);
        }

        tree[i]=combine(tree[i*2],tree[i*2+1]);
    }
    long long maxSubarraySum(vector<int>& nums) {
        int n=nums.size();
        vector<node> tree(4*n+5);
        map<ll,vector<ll> > help;
        int neg_cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]<0){
                neg_cnt++;
            }
            upd(1,0,n-1,i,nums[i],tree);
            help[nums[i]].push_back(i);
        }

        if(neg_cnt==n){
            sort(nums.begin(),nums.end());
            return nums[n-1];
        }
        
        ll ans=tree[1].max_subarray;

        for(auto it:help){
            for(auto ind:it.second){
                upd(1,0,n-1,ind,0,tree);
            }


            ans=max(ans,tree[1].max_subarray);
            

            for(auto ind:it.second){
                upd(1,0,n-1,ind,it.first,tree);
            }
        }

        return ans;
        
    }
};