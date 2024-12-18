#include<bits/stdc++.h>
using namespace std;
#define ll long long
int tree[2000005];
class Solution {
public:
    void upd(int node,int l,int r,int index,int value){
        if(l>r){
            return;
        }

        if(l==r){
            tree[node]=value;
            return;
        }

        int mid=(l+r)/2;

        if(index<=mid){
            upd(node*2,l,mid,index,value);
        }else{
            upd(node*2+1,mid+1,r,index,value);
        }

        tree[node]=max(tree[node*2],tree[node*2+1]);
    }

    int query(int node,int st,int en,int l,int r){
        if(st>en or en<l or st>r){
            return -1e9;
        }

        if(st>=l and en<=r){
            return tree[node];
        }

        int mid=(st+en)/2ll;
        return max(query(node*2,st,mid,l,r),query(node*2+1,mid+1,en,l,r));

    }

    vector<int> set_to_vector(set<int> &x){
        vector<int> ret;
        for(auto it:x){
            ret.push_back(it);
        }
        return ret;
    }

    long long maxRectangleArea(vector<int>& xCoord, vector<int>& yCoord) {
        set<int> xUniq,yUniq;
        unordered_map<int,int> hsh_x,rev_hsh_x;
        unordered_map<int,set<int> > groupX_by_y,y_for_x;
        int n=xCoord.size();

        for(int i=0;i<n;i++){
            xUniq.insert(xCoord[i]);
            yUniq.insert(yCoord[i]);
            groupX_by_y[yCoord[i]].insert(xCoord[i]);
            y_for_x[xCoord[i]].insert(yCoord[i]);
        }

        int tot_x=0;
        for(auto it:xUniq){
            tot_x++;
            hsh_x[it]=tot_x;
            rev_hsh_x[tot_x]=it;
        }


        for(auto it:y_for_x){
            int index=hsh_x[it.first];
            int value=*(--it.second.end());
            upd(1,1,tot_x,index,value);
        }
        ll ans=-1;
        vector<int> y_vec=set_to_vector(yUniq);
        
        for(int i=y_vec.size()-1;i>=0;i--){
            int y_cord=y_vec[i];
            
            for(auto it:groupX_by_y[y_cord]){
                y_for_x[it].erase(y_cord);
                ll ind_hsh=hsh_x[it];
                ll value=-1;
                if(y_for_x[it].size()>0){
                    value=*(--y_for_x[it].end());
                }
                upd(1,1,tot_x,ind_hsh,value);
            }

            int prev=-1;
            for(auto curr:groupX_by_y[y_cord]){
                if(prev==-1){
                    prev=curr;
                    continue;
                }

                int l=hsh_x[prev];
                int r=hsh_x[curr];

                int nx_y=query(1,1,tot_x,l,r);
                //cout<<l<<" "<<r<<" "<<nx_y<<endl;
                if(groupX_by_y.find(nx_y)==groupX_by_y.end()){
                    continue;
                }
                if(groupX_by_y[nx_y].find(prev) != groupX_by_y[nx_y].end() and groupX_by_y[nx_y].find(curr) != groupX_by_y[nx_y].end()){
                    if(r==l+1){
                        ans=max(ans,(curr*1ll-prev*1ll)*(y_vec[i]*1ll-nx_y*1ll));
                    }else{
                        int nx_y_=query(1,1,tot_x,l+1,r-1);
                        if(nx_y_<nx_y){
                            ans=max(ans,(curr*1ll-prev*1ll)*(y_vec[i]*1ll-nx_y*1ll));
                        }
                    }
                }
                prev=curr;
            }
        }
        
        return ans;

    }
};