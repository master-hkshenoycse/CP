#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(),items.end());
        int n=items.size();
        vector<int> prices(n,0),max_beauty(n,INT_MIN);
        
        for(int i=0;i<n;i++){
            prices[i]=items[i][0];
            if(i>0){
                max_beauty[i]=max(max_beauty[i-1],items[i][1]);
            }else{
                max_beauty[i]=items[i][1];;
            }
        }
        
        vector<int> sol;
        vector<int>::iterator it;
        for(auto q:queries){
            it=upper_bound(prices.begin(),prices.end(),q);
            if(it==prices.begin()){
                sol.push_back(0);
            }else{
                it--;
                int ind=it-prices.begin();
                sol.push_back(max_beauty[ind]);
            }
        }
        return sol;
        
    }
};