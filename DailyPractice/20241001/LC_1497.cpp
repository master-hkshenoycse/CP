#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> cnt(k);
        for(auto e:arr){
            int val=e%k;
            if(val<0){
                val+=k;
            }
            cnt[val]++;
        }

        for(int i=1;i<(k+1)/2;i++){
            //cout<<i<<" "<<k-i<<" "<<cnt[i]<<" "<<cnt[k-i]<<endl;
            if(cnt[i] != cnt[k-i]){
                
                return 0;
            }
        }
        
        if(k%2){
            return 1;
        }
        return (cnt[k/2]%2)==0;
    }
};