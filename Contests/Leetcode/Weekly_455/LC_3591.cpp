#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check_prime(int n){
        if(n==1) return 0;

        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                return 0;
            }
        }

        return 1;
    }
    bool checkPrimeFrequency(vector<int>& nums) {
        map<int,int> freq;
        for(auto e:nums){
            freq[e]++;
        }

        for(auto it:freq){
            if(check_prime(it.second)){
                return 1;
            }
        }

        return 0;
    }
};