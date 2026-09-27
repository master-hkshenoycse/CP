#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int get_score(vector<int> &a){
        int n=a.size();
        vector<int> suff_gc(n);
        for(int i=n-1;i>=0;i--){
            suff_gc[i]=a[i];
            if(i+1<n)
                suff_gc[i]=__gcd(suff_gc[i+1],a[i]);
        }
        int pref_gc=0,ans=0;
        for(int i=0;i+1<n;i++){
            pref_gc=__gcd(pref_gc,a[i]);
            if(pref_gc == suff_gc[i+1])
                ans++;
        }
        return ans;
    }
    int maxValidSplits(vector<int>& nums) {
        int ret=get_score(nums);
        int n=nums.size();
        for(int i=0;i<n;i++){
            vector<int> tmp;
            for(int j=0;j<n;j++){
                if(j==i)
                    continue;
                tmp.push_back(nums[j]);
            }
            ret=max(ret,get_score(tmp));
        }
        return ret;
    }
};