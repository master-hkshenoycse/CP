#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k, int m) {
        ll n=nums.size();
        map<int,int> freq;

        int l=0,distinct=0,valid=0;
        ll ans=0,extra=0;

        for(ll r=0;r<n;r++){
            if(freq[nums[r]]==0)distinct++;
            freq[nums[r]]++;
            if(freq[nums[r]]==m)valid++;

            while(distinct>k){
                if(freq[nums[l]]==m)valid--;
                freq[nums[l]]--;
                if(freq[nums[l]]==0)distinct--;
                l++;
                extra=0;
            }

            if(distinct==k && valid==k){
                while(freq[nums[l]]>m){
                    freq[nums[l]]--;
                    l++;
                    extra++;
                }
                ans+=(extra+1);
            }
        }

        return ans;

    }
};