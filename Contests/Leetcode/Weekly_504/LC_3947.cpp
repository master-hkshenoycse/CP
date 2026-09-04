#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        map<int,int> freq_cnt;
        int min_price=INT_MAX;
        int n=items.size();

        for(int i=0;i<n;i++){
            int f=items[i][0];
            min_price=min(min_price,items[i][1]);

            for(int j=1;j*j<=f;j++){
                if(f%j==0){
                freq_cnt[j]++;
                if(j!=f/j)
                    freq_cnt[f/j]++;      
                }
            }
        }

        vector<vector<int> > cons;
        for(int i=0;i<n;i++){
            int extra=freq_cnt[items[i][0]]-1;
            if(extra>0 && items[i][1]<2*min_price)
                cons.push_back({items[i][1],extra});
        }
        sort(cons.begin(),cons.end(),[&](vector<int> &a,vector<int> &b){
            return a[0]<b[0]; 
        });

        int ans=0;

        for(int i=0;i<cons.size();i++){
            int mx_poss=budget/cons[i][0];
            mx_poss=min(mx_poss,cons[i][1]);
            ans=ans+2*mx_poss;
            budget-=cons[i][0]*mx_poss;
        }
        
        ans=ans+budget/min_price;
        return ans;
    }
};