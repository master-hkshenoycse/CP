#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int par[36];
        int get_par(int v){
            if(v==par[v])return v;
            return get_par(par[v]);
        }
    
        void dsu(int x,int y){
            int px=get_par(x);
            int py=get_par(y);
    
            if(px==py)return ;
            par[px]=py;
        }
        string smallestEquivalentString(string s1, string s2, string baseStr) {
            for(int i=0;i<26;i++){
                par[i]=i;
            }
    
            int n=s1.size();
    
            for(int i=0;i<n;i++){
                dsu(s1[i]-'a',s2[i]-'a');
            }
            
            n=baseStr.size();
            for(int i=0;i<n;i++){
                int px=get_par(baseStr[i]-'a');
                int res=baseStr[i]-'a';
                for(int j=26;j>=0;j--){
                    if(px==get_par(j)){
                        res=j;
                    }
                }
    
                baseStr[i]=char('a'+res);
            }
    
            return baseStr;
        }
    };