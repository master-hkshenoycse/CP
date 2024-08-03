#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        vector<int> cnt(1001,0);
        for(auto t:target){
            cnt[t]++;
        }

        for(auto t:arr){
            cnt[t]--;
        }

        for(int i=1;i<=1000;i++){
            if(cnt[i] != 0){
                return 0;
            }
        }

        return 1;
    
    }
};