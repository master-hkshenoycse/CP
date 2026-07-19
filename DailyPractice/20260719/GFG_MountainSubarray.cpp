#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<bool> processQueries(vector<int> &arr, vector<vector<int>> &queries) {
        // code here
        int n=arr.size();
        vector<int> suff_inc(n),pref_dec(n,0);

        for(int i=n-1;i>=0;i--){
            if(i+1<n && arr[i]<=arr[i+1]){
                suff_inc[i]=suff_inc[i+1];
            }else{
                suff_inc[i]=i;
            }
        }
        
        for(int i=0;i<n;i++){
            if(i-1>=0 && arr[i-1]>=arr[i]){
                pref_dec[i]=pref_dec[i-1];
            }else{
                pref_dec[i]=i;
            }
        }
        
        vector<bool> ret;
        for(auto q:queries){
            ret.push_back(suff_inc[q[0]]>=pref_dec[q[1]]);
        }

        return ret;
    }
};