#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int get_value(string &s){
        int ret=0;
        for(auto ch:s){
            ret=ret*10+(ch-'0');
        }
        return ret;
    }
    int maximumSwap(int num) {
        string curr=to_string(num);
        int sz=curr.size();
        int ans=num;
        for(int i=0;i<sz;i++){
            for(int j=i+1;j<sz;j++){
                swap(curr[i],curr[j]);
                ans=max(ans,get_value(curr));
                swap(curr[i],curr[j]);
            }
        }
        return ans;
    }
};