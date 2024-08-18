#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    vector<vector<ll> > merge_sort_tree;
    vector<vector<ll> > merge_sort_tree_sum;
    
    void merge_tree_node(ll l,ll r,ll target){
        ll n=merge_sort_tree[l].size(),m=merge_sort_tree[r].size();
        vector<ll> ret;
        ll i=0,j=0;
        
        while(i<n and j<m){
            if(merge_sort_tree[l][i]<=merge_sort_tree[r][j]){
                merge_sort_tree[target].emplace_back(merge_sort_tree[l][i++]);
            }else{
                merge_sort_tree[target].emplace_back(merge_sort_tree[r][j++]);
            }
        }
        
        while(i<n){
           merge_sort_tree[target].emplace_back(merge_sort_tree[l][i++]);
        }
        
        while(j<m){
            merge_sort_tree[target].emplace_back(merge_sort_tree[r][j++]);
        }
        
     
        
    }
    void build(ll node,ll l,ll r,vector<ll> &a){
        if(l>r){
            return ;
        }
        
        if(l==r){
            merge_sort_tree[node].push_back(a[l]);
            merge_sort_tree_sum[node].push_back(a[l]);
            return;
        }
        
        ll mid=(l+r)/2;
        build(node*2,l,mid,a);
        build(node*2+1,mid+1,r,a);
        
        merge_tree_node(node*2,node*2+1,node);
        merge_sort_tree_sum[node]=merge_sort_tree[node];
        int sz=merge_sort_tree[node].size();
        for(int i=1;i<sz;i++){
            merge_sort_tree_sum[node][i]+=merge_sort_tree_sum[node][i-1];
        }
        
        
    }
    ll get_sum(ll l,ll r){
        return ((r-l+1)*(r+l))/2ll;
    }
    
    ll get_cnt_query(ll node,ll l,ll r,ll st,ll en,ll q,ll &sum){
        
        
        if(l>r or r<st or l>en){
            return 0;
        }
        
        if(l>=st and r<=en){
            
            // cnt of indexes less than r;
            auto it=lower_bound(merge_sort_tree[node].begin(),merge_sort_tree[node].end(),q);
            
            if(it==merge_sort_tree[node].begin()){
                return 0;
            }
            
            it--;
            ll ind=it-merge_sort_tree[node].begin();
 

            sum+=merge_sort_tree_sum[node][ind];
            return ind+1;
    
        }
        
        
        
        ll mid=(l+r)/2;
        
        return get_cnt_query(node*2,l,mid,st,en,q,sum)+get_cnt_query(node*2+1,mid+1,r,st,en,q,sum);
    }
    
    
    vector<long long> countKConstraintSubstrings(string s, int k, vector<vector<int>>& queries) {
        ll n=s.size();
        vector<ll> max_poss_end(n);
        vector<ll> count_one(n,0),count_zero(n,0);
        
        merge_sort_tree.resize(4*n+5);
        merge_sort_tree_sum.resize(4*n+5);
        
        for(ll i=0;i<n;i++){
            count_one[i]=(s[i]=='1');
            count_zero[i]=(s[i]=='0');
            
            if(i-1>=0){
                count_one[i]+=count_one[i-1];
                count_zero[i]+=count_zero[i-1];
            }
        }
        
        for(int i=0;i<n;i++){
            
            int lo=i,hi=n-1,r=i;
            
            while(hi>=lo){
                int mid=(hi+lo)/2;
                int c0=count_zero[mid];
                int c1=count_one[mid];
                
                if(i-1>=0){
                    c0-=count_zero[i-1];
                    c1-=count_one[i-1];
                }
                
                if(c0<=k or c1<=k){
                    r=max(r,mid);
                    lo=mid+1;
                }else{
                    hi=mid-1;
                }
            }
            
            max_poss_end[i]=r;

        }
        
        
        
        build(1,0,n-1,max_poss_end);
        
        
        vector<ll> sol;
        
       for(auto q:queries){
            ll l=q[0];
            ll r=q[1];
            
            ll len=r-l+1;
            
            ll ans=len-get_sum(l,r);
            ll sum_ls_r=0;
                
            ll cnt_ls_r=get_cnt_query(1,0,n-1,l,r,r,sum_ls_r);
            ll cnt_gt_r=len-cnt_ls_r;
            
            ans=ans+cnt_gt_r*r;
            ans=ans+sum_ls_r;
            
            sol.push_back(ans);
            
        
        }
        
       
        return sol;
    }
};