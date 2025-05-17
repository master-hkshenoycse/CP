#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int uniqueXorTriplets(vector<int>& nums) {
            int n=nums.size();
            int p=1;
            while(p<=n){
                p=p*2;
            }
    
            if(n==2)return 2;
            if(n==1)return 1;
            return p;
        }
    };