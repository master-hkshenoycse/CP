#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    void upd(int ind,int v,int n,vector<int> &tree){
        while(ind<=n){
            tree[ind]+=v;
            ind+=(ind & (-ind));
        }
    }

    int query(int ind,vector<int> &tree){
        int res=0;
        while(ind>0){
            res=res+tree[ind];
            ind-=(ind & (-ind));
        }
        return res;
    }
    long long minInversionCount(vector<int>& nums, int k) {
       ll n=nums.size();
       map<ll,ll> hsh,rev_hsh;
       for(auto e:nums){
          hsh[e]++;
       } 
       int c=0;
       for(auto it:hsh){
        c++;
        rev_hsh[it.first]=c;
       }

       vector<int> fenwick_tree(c+1,0);
       ll ret=1e12,curr=0;

       for(int i=0;i<n;i++){
            int curr_ls=0,curr_gt=0;

            if(i-k>=0){
                curr_ls=query(rev_hsh[nums[i-k]]-1,fenwick_tree);
                upd(rev_hsh[nums[i-k]],-1,c,fenwick_tree);
            }

            curr_gt=query(c,fenwick_tree)-query(rev_hsh[nums[i]],fenwick_tree);
            curr=curr-curr_ls*1ll+curr_gt*1ll;
            upd(rev_hsh[nums[i]],1,c,fenwick_tree);

            if(i>=k-1){
                ret=min(ret,curr);
            }
        }
        return ret;

    }
};