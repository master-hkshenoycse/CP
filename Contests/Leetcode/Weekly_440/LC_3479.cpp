#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        void update(int node,int l,int r,int ind,int value,vector<int> &tree){
            if(l>r){
                return;
            }
            
            if(l==r){
                tree[node]=value;
                return;
            }
            
            int mid=(l+r)/2;
            
            if(ind<=mid){
                update(node*2,l,mid,ind,value,tree);
            }else{
                update(node*2+1,mid+1,r,ind,value,tree);
            }
            
            tree[node]=max(tree[node*2],tree[node*2+1]);
        }
        
        int get_first(int node,int l,int r,int st,int en,int value,vector<int> &tree){
            if(l>r or st>en or r<st or l>en){
                return -1;
            }
            
            if(tree[node] < value){
                return -1;
            }
            
            //cout<<node<<" "<<l<<" "<<r<<" "<<value<<endl;
            if(l==r){
                return l;
            }
            
            int mid=(l+r)/2;
            int lf=get_first(node*2,l,mid,st,en,value,tree);
            if(lf != -1){
                return lf;
            }
            
            return get_first(node*2+1,mid+1,r,st,en,value,tree);
        }
        int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
            int m=baskets.size(),n=fruits.size();
            vector<int> tree(4*m+10,-1);
            
            for(int i=0;i<m;i++){
                update(1,0,m-1,i,baskets[i],tree);
            }
            
            int ans=0;
            
            for(int i=0;i<n;i++){
                int r=get_first(1,0,m-1,0,m-1,fruits[i],tree);
                //cout<<r<<endl;
                if(r != -1){
                      update(1,0,m-1,r,-1,tree); 
                }else{
                    ans++;
                }
                
            }
            
            return ans;
        }
    };