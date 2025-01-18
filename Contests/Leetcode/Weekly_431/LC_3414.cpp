#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    void update(ll node,ll l,ll r,ll ind,pair<ll,ll> tup,vector<pair<ll,ll> >&tree){
        if(l>r){
            return;
        }

        if(l==r){
            tree[node]=max(tree[node],tup);
            return;
        }

        ll mid=(l+r)/2ll;

        if(ind<=mid){
            update(node*2,l,mid,ind,tup,tree);
        }else{
            update(node*2+1,mid+1,r,ind,tup,tree);
        }

        tree[node]=max(tree[node*2],tree[node*2+1]);
    }
    pair<ll,ll> query(ll node,ll st,ll en,ll l,ll r,vector<pair<ll,ll> >&tree){
        if(l>r || en<l || st>r){
            return {-1e18,-1e18};
        }

        if(st>=l and en<=r){
            return tree[node];
        }

        ll mid=(st+en)/2ll;
        return max(query(node*2,st,mid,l,r,tree),query(node*2+1,mid+1,en,l,r,tree));
    }
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        
        ll n=intervals.size();

        for(ll i=0;i<n;i++){
            intervals[i].push_back(i);
        }

        sort(intervals.begin(),intervals.end());
        map<ll,ll> help;

        for(auto it:intervals){
            help[it[0]]++;
            help[it[1]]++;
        }

        int c=0;
        for(auto &it:help){
            c++;
            it.second=c;
        }

        

        vector<pair<ll,ll> > tree(4*c+5,make_pair(-1e18,-1e18));
        vector<ll> prefix_max(n,0),suffix_max(n,0);
        vector<vector<ll> > suffix_inds(n),prefix_inds(n);

        for(int i=0;i<n;i++){
            
            ll l=help[intervals[i][0]];
            ll r=help[intervals[i][1]];
            ll ind=intervals[i][3];
            ll val=intervals[i][2];
            
            pair<ll,ll> ret;
            ret=query(1,1,c,1,l-1,tree);

                        
            if(ret.second == -1e18){
                prefix_max[i]=val;
                prefix_inds[i]={ind};
            }else{
                prefix_max[i]=val+ret.first;
                prefix_inds[i]={min(ind,-ret.second),max(ind,-ret.second)};
            }

            //cout<<i<<" "<<ind<<" "<<l<<" "<<r<<" "<<ret.second<<endl;

            update(1,1,c,r,make_pair(val,-ind),tree);

        }

       // cout<<endl;


        for(int i=0;i<4*c+5;i++){
            tree[i]={-1e18,-1e18};
        }

        for(int i=n-1;i>=0;i--){
            ll l=help[intervals[i][0]];
            ll r=help[intervals[i][1]];
            ll ind=intervals[i][3];
            ll val=intervals[i][2];

            pair<ll,ll> ret;
            ret=query(1,1,c,r+1,c,tree);

            if(ret.second==-1e18){
                suffix_max[i]=val;
                suffix_inds[i]={ind};
            }else{
                suffix_max[i]=val+ret.first;
                suffix_inds[i]={min(ind,-ret.second),max(ind,-ret.second)};
            }

            //cout<<i<<" "<<ind<<" "<<suffix_max[i]<<endl;
            update(1,1,c,l,make_pair(val,-ind),tree);  
        }

        for(int i=n-2;i>=0;i--){
            if(suffix_max[i]<suffix_max[i+1]){
                suffix_max[i]=suffix_max[i+1];
                suffix_inds[i]=suffix_inds[i+1];
            }else if(suffix_max[i]==suffix_max[i+1]){
                suffix_inds[i]=min(suffix_inds[i],suffix_inds[i+1]);
            }
        }

        ll max_value=0;
        vector<int> max_inds;

        for(int i=0;i<n;i++){
            vector<int> curr_ind;
            ll curr_val=prefix_max[i];
            for(auto ind:prefix_inds[i]){
                curr_ind.push_back(ind);
            }

            ll suff_poss=n,lo=i+1,hi=n-1;

            while(hi>=lo){
                ll mid=(hi+lo)/2ll;
                if(intervals[mid][0]>intervals[i][1]){
                    suff_poss=min(suff_poss,mid);
                    hi=mid-1;
                }else{
                    lo=mid+1;
                }
            }

            if(suff_poss<n){
                curr_val+=suffix_max[suff_poss];
                for(auto ind:suffix_inds[suff_poss]){
                    curr_ind.push_back(ind);
                }
            }

            sort(curr_ind.begin(),curr_ind.end());
            if(curr_val>max_value){
                max_value=curr_val;
                max_inds=curr_ind;
            }else if(curr_val==max_value){
                max_inds=min(max_inds,curr_ind);
            }

            //cout<<curr_val<<" ";
        }
        //cout<<endl;

        //cout<<max_value<<endl;

        return max_inds;
    }
};