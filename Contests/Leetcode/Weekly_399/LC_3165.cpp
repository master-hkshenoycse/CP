#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node{

    ll first_last_both;
    ll first_only;
    ll last_only;
    ll first_last_both_not;
};


class Solution {
public:
    node tree[200005];
    void update(ll index){
        ll left=index*2;
        ll right=index*2+1;

        tree[index].first_last_both=max({tree[left].first_last_both+tree[right].last_only,
                                        tree[left].first_only+tree[right].last_only,
                                        tree[left].first_only+tree[right].first_last_both
                                        });

        tree[index].first_only=max({tree[left].first_only+tree[right].first_only,
                                    tree[left].first_only+tree[right].first_last_both_not,
                                    tree[left].first_last_both+tree[right].first_last_both_not});

        tree[index].last_only=max({tree[left].last_only+tree[right].last_only,
                                  tree[left].first_last_both_not+tree[right].first_last_both,
                                  tree[left].first_last_both_not+tree[right].last_only});

        tree[index].first_last_both_not=max({tree[left].first_last_both_not+tree[right].first_last_both_not,
                                            tree[left].last_only+tree[right].first_last_both_not,
                                            tree[left].first_last_both_not+tree[right].first_only});                        
    }
    void build(ll index,ll l,ll r,vector<int> &nums){
        if(l>r){
            return;
        }

        if(l==r){
            tree[index].first_last_both=nums[l];
            tree[index].first_only=0;
            tree[index].last_only=0;
            tree[index].first_last_both_not=0;
            return;
        }

        ll mid=(l+r)/2ll;
        build(index*2,l,mid,nums);
        build(index*2+1,mid+1,r,nums);
        update(index);
    }

    void upd(ll index,ll l,ll r,ll ind,ll val){
        if(l>r){
            return;
        }

        if(l==r){
            tree[index].first_last_both=val;
            tree[index].first_only=0;
            tree[index].last_only=0;
            tree[index].first_last_both_not=0;
            return;

        }
        
        ll mid=(l+r)/2ll;
        if(ind<=mid){
            upd(index*2,l,mid,ind,val);
        }else{
            upd(index*2+1,mid+1,r,ind,val);
        }

        update(index);
    }



    int maximumSumSubsequence(vector<int>& nums, vector<vector<int>>& queries) {
        
        int n=nums.size();
        build(1,0,n-1,nums);

        ll ans=0;
        ll mod=1e9+7;

        for(auto q:queries){
            upd(1,0,n-1,q[0],q[1]);
            ans=ans+max({tree[1].first_last_both,tree[1].first_only,tree[1].last_only,tree[1].first_last_both_not});
            ans%=mod;
        }

        return ans;





    }
};