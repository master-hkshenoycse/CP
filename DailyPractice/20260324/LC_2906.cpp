#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int> > sol(n,vector<int> (m,0));
        int mod=12345;
        
        vector<vector<int> > pref_product(n,vector<int> (m,1));
        vector<vector<int> > suff_product(n,vector<int> (m,1));
        
        vector<int> row_prod_pref(n,1),row_prod_suff(n,1);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                pref_product[i][j]=grid[i][j]%mod;
                if(j-1>=0){
                    pref_product[i][j]=(pref_product[i][j] * pref_product[i][j-1])%mod;
                }
            }
            
            row_prod_pref[i]=pref_product[i][m-1];
            row_prod_suff[i]=pref_product[i][m-1];
            
            for(int j=m-1;j>=0;j--){
                suff_product[i][j]=grid[i][j]%mod;
                if(j+1<m){
                    suff_product[i][j]=(suff_product[i][j] * suff_product[i][j+1])%mod;
                }
            }
        }
        
        for(int i=1;i<n;i++){
            row_prod_pref[i]=(row_prod_pref[i] * row_prod_pref[i-1])%mod;
        }
        
        for(int i=n-2;i>=0;i--){
            row_prod_suff[i]=(row_prod_suff[i] * row_prod_suff[i+1])%mod;
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                sol[i][j]=1;
                if(i-1>=0){
                    sol[i][j]=(sol[i][j] * row_prod_pref[i-1])%mod;
                }
                
                if(i+1<n){
                    sol[i][j]=(sol[i][j] * row_prod_suff[i+1])%mod;
                }
                
                if(j-1>=0){
                    sol[i][j]=(sol[i][j] * pref_product[i][j-1])%mod;
                }
                
                if(j+1<m){
                    sol[i][j]=(sol[i][j] *suff_product[i][j+1])%mod;
                }
            }
        }
        
        return sol;
    }
};