#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    int get_popcount(ll n){
        if(n==1){
            return 0;
        }

        int c=0;
        while(n>0){
            c++;
            n=(n & (n-1));
        }

        return 1+get_popcount(c);
    }

    void upd(vector<vector<int> >&bit, int b,int ind, int n,int val){
        while(ind<=n){
            bit[b][ind]+=val;
            ind+=(ind & (-ind));
        }
    }

    int query(vector<vector<int> >&bit, int b,int ind){
        int ret=0;
        while(ind>0){
            ret=ret+bit[b][ind];
            ind-=(ind & (-ind));
        }
        return ret;
    }

    vector<int> popcountDepth(vector<long long>& nums, vector<vector<long long>>& queries) {
        int n=nums.size();
        vector<vector<int> > fenwick_tree(64,vector<int> (n+1,0));
        vector<int> ret;

        for(int i=1;i<=n;i++){
            int pd=get_popcount(nums[i-1]);
            upd(fenwick_tree,pd,i,n,1);
        }

        for(auto q:queries){
            if(q[0]==1){
                int l=q[1]+1;
                int r=q[2]+1;
                int k=q[3];
                ret.push_back(query(fenwick_tree,k,r)-query(fenwick_tree,k,l-1));
            }else{
                int c_pd=get_popcount(nums[q[1]]);
                upd(fenwick_tree,c_pd,q[1]+1,n,-1);

                nums[q[1]]=q[2];

                c_pd=get_popcount(nums[q[1]]);
                upd(fenwick_tree,c_pd,q[1]+1,n,1);
            }
        }

        return ret;

    }
};