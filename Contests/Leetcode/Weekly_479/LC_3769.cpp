#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int get_ref(int n){
        string rev;
        while(n>0){
            rev+=char('0'+(n%2));
            n/=2;
        }

        int ret=0;
        for(auto ch:rev)
            ret=ret*2+(ch-'0');
        
        return ret;
    }

    vector<int> sortByReflection(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int> > a;
        for(auto e:nums){
            a.push_back({get_ref(e),e});
            //cout<<e<<" "<<get_ref(e)<<endl;
        }
        sort(a.begin(),a.end());
        vector<int> ret;
        for(auto e:a)
            ret.push_back(e.second);
        return ret;  
    }
};