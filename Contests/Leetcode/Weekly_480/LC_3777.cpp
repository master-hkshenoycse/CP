#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void upd(int ind,int val,int n,vector<int> &tree){
        while(ind<=n){
            tree[ind]+=val;
            ind+=(ind & (-ind));
        }
    }

    int query(int ind,vector<int> &tree){
        int ret=0;
        while(ind>0){
            ret=ret+tree[ind];
            ind-=(ind & (-ind));
        }   
        return ret;
    }
    vector<int> minDeletions(string s, vector<vector<int>>& queries) {
        int n=s.size();
        vector<int> fenwick_tree(n+2,0);

        for(int i=1;i<=n;i++){
            if(s[i-1]==s[i]){
                upd(i,1,n,fenwick_tree);
            }
        }
        vector<int> ret;

        for(auto q:queries){
            if(q[0]==1){
                int ind=q[1];
                if(ind-1>=0){
                    if(s[ind-1]==s[ind]){
                        upd(ind,-1,n,fenwick_tree);                
                    }else{
                        upd(ind,1,n,fenwick_tree);
                    }
                }

                if(ind+1<n){
                    if(s[ind]==s[ind+1]){
                        upd(ind+1,-1,n,fenwick_tree);
                    }else{
                        upd(ind+1,1,n,fenwick_tree);
                    }
                }


                if(s[ind]=='A'){
                    s[ind]='B';
                }else{
                    s[ind]='A';
                }

            }else{
                int l=q[1]+1;
                int r=q[2]+1;

                ret.push_back(query(r-1,fenwick_tree)-query(l-1,fenwick_tree));
            }
        }

        return ret;




    }
};