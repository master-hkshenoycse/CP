#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public: 
    struct seg_node{
        vector<ll> prefix_sum;
        vector<int> sorted_values;
        seg_node(){
            prefix_sum.clear();
            sorted_values.clear();
        }
    };

    void merge_node(vector<int> &a,vector<int> &b,seg_node &node){
        ll n=a.size(),m=b.size(),i=0,j=0;
        
        while(i<n && j<m){
            if(a[i]<b[j]){
                node.sorted_values.push_back(a[i]);
                node.prefix_sum.push_back(a[i]);
                i++;
            }else{
                node.sorted_values.push_back(b[j]);
                node.prefix_sum.push_back(b[j]);
                j++;
            }

            if(node.prefix_sum.size()>1)
                    node.prefix_sum.back()+=node.prefix_sum[node.prefix_sum.size()-2];
        }

        while(i<n){
            node.sorted_values.push_back(a[i]);
            node.prefix_sum.push_back(a[i]);
            if(node.prefix_sum.size()>1)
                    node.prefix_sum.back()+=node.prefix_sum[node.prefix_sum.size()-2];
            i++;
        }

        while(j<m){
            node.sorted_values.push_back(b[j]);
            node.prefix_sum.push_back(b[j]);
            if(node.prefix_sum.size()>1)
                    node.prefix_sum.back()+=node.prefix_sum[node.prefix_sum.size()-2];
            j++;
        }

    }
    void build(int ind,int l,int r,vector<int> &nums,vector<seg_node> &tree){
        if(l>r)
            return;
        
        if(l==r){
            tree[ind].sorted_values.push_back(nums[l]);
            tree[ind].prefix_sum.push_back(nums[l]);
            return;
        }

        int mid=(l+r)/2;
        build(ind*2,l,mid,nums,tree);
        build(ind*2+1,mid+1,r,nums,tree);
        merge_node(tree[ind*2].sorted_values, tree[ind*2+1].sorted_values, tree[ind]);
    }

    pair<ll,ll> query(int node,int st,int en,int l,int r,int val,vector<seg_node> &tree){
        if(st>en or en<l or st>r)
            return {0,0};

        if(st>=l && en<=r){
            ll ind=upper_bound(tree[node].sorted_values.begin(),tree[node].sorted_values.end(), val)-tree[node].sorted_values.begin();
            
            if(ind==0)return {0,0};
            return {ind,tree[node].prefix_sum[ind-1]};

        }

        int mid=(st+en)/2;
        pair<ll,ll> r1=query(node*2,st,mid,l,r,val,tree);  
        pair<ll,ll> r2=query(node*2+1,mid+1,en,l,r,val,tree);
        return {r1.first+r2.first,r1.second+r2.second};  
    }
    vector<long long> minOperations(vector<int>& nums, int k, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int> rem_n(n);
        vector<ll> nx_neq(n+1,n),prefix_sum(n+1,0);
        vector<seg_node> segtree(4*n+4);
        build(1,0,n-1,nums,segtree);
        int lim=0;
        for(int i=n-1;i>=0;i--){
            rem_n[i]=(nums[i]%k);
            lim=max(lim,nums[i]);
            if(i+1<n && rem_n[i] == rem_n[i+1]){
                nx_neq[i]=nx_neq[i+1];
            }else{
                nx_neq[i]=i+1;
            }
        }

        for(ll i=0;i<n;i++){
            prefix_sum[i]=nums[i];
            if(i-1>=0)
                prefix_sum[i]+=prefix_sum[i-1];
        }

        int q=queries.size();
        vector<ll> ret(q,-1);

        for(int i=0;i<q;i++){
            ll l=queries[i][0];
            ll r=queries[i][1];
        
            if(nx_neq[l]>r){
                ll req=(r-l)/2+1,lo=0,hi=lim,med=lim,cnt_ls_med=0,sum_ls_med=0;
                while(hi>=lo){
                    ll mid=(hi+lo)/2ll;
                    pair<ll,ll> que_res=query(1,0,n-1,l,r,mid,segtree);
                    if(que_res.first>=req){
                        med=min(med,mid);
                        cnt_ls_med=que_res.first;
                        sum_ls_med=que_res.second;
                        hi=mid-1;
                    }else{
                        lo=mid+1;
                    }
                }

                ll tot_sum=prefix_sum[r];
                if(l-1>=0)
                    tot_sum-=prefix_sum[l-1];
                ret[i]=((med*cnt_ls_med-sum_ls_med)+(tot_sum-sum_ls_med)-((r-l+1)-cnt_ls_med)*med)/k;
            }
        }

        return ret;
    }
};