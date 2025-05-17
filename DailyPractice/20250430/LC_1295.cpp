#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int findNumbers(vector<int>& nums) {
            int ans=0;
            for(auto e:nums){
                int cnt=0;
                while(e>0){
                    cnt++;
                    e/=10;
                }
                if(cnt%2==0){
                    ans++;
                }
            }
    
            return ans;
        }
    };