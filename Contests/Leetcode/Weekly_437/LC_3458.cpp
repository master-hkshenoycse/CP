#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int get_max(int ind,int max_lim,vector<vector<int> >&a,vector<vector<int> >&dp){
            if(ind==a.size()){
                return 0;
            }
            
            if(dp[ind][max_lim] != -1){
                return dp[ind][max_lim];
            }
            
            int ret=0;
            
            if(a[ind][0]<max_lim){
                ret=max(ret,get_max(ind+1,max(a[ind][1],max_lim),a,dp));
            }else{
                ret=get_max(ind+1,max_lim,a,dp);
                ret=max(ret,1+get_max(ind+1,a[ind][1],a,dp));
            }
    
            return dp[ind][max_lim]=ret;
        }
        
        bool check_one(vector<int> &st,vector<int> &en,string &s){
            int n=s.size();
            
            for(int iter=0;iter<52;iter++){
                 for(int i=0;i<26;i++){
                    if(st[i] != -1){
    
                        int l=st[i];
                        int r=en[i];
    
                        for(int j=l;j<=r;j++){
                            if(st[s[j]-'a'] != -1){
                                l=min(l,st[s[j]-'a']);
                                r=max(r,en[s[j]-'a']);
                            }
                        }
    
                        st[i]=l;
                        en[i]=r;
                    }
                }
            }
            
            return 1;
        }
        bool maxSubstringLength(string s, int k) {
            int n=s.size();
            vector<int> st(26,-1),en(26,-1);
            
            if(k==0){
                return true;
            }
            for(int i=0;i<n;i++){
                if(st[s[i]-'a']==-1){
                    st[s[i]-'a']=i;
                }
                en[s[i]-'a']=i;
            }
            
            
            vector<vector<int> > a;
            int r=0;
            check_one(st,en,s);
            for(int i=0;i<26;i++){
                if(st[i] != -1){
                    //cout<<i<<" "<<st[i]<<" "<<en[i]<<endl;
                    a.push_back({st[i]+1,en[i]+1});
                }
            }
            
            if(k==1){
                for(int i=0;i<a.size();i++){
                    if(a[i][0] !=1 ||  a[i][1] != n){
                        return 1;
                    }
                }
                
                return 0;
            }
            cout<<endl;
            
            sort(a.begin(),a.end());
            
            int sz=a.size();
            vector<vector<int> > dp(sz,vector<int> (n+2,-1));
            
            return get_max(0,0,a,dp)>=k;
                
        }
    };