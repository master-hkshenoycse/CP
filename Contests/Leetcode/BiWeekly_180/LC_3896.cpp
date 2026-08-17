#include<bits/stdc++.h>
using namespace std;
vector<int> primes,non_primes;
int pre_done=0;
void pre_cum(){

    if(pre_done)
        return;
    
    pre_done=1;
    vector<int> mark(500005,0);
    non_primes.push_back(1);

    for(int i=2;i<=500000;i++){
        if(mark[i]==0){
            primes.push_back(i);
            for(int j=2*i;j<=500000;j+=i)
                mark[j]=1;
        }else{
            non_primes.push_back(i);
        }
    }
}   
class Solution {
public:
    int minOperations(vector<int>& nums) {
        pre_cum();
        int n=nums.size(),ret=0;
        for(int i=0;i<n;i++){
            if(i%2==0){
                ret=ret+(*lower_bound(primes.begin(),primes.end(),nums[i]))-nums[i];
            }else{
                ret=ret+(*lower_bound(non_primes.begin(),non_primes.end(),nums[i]))-nums[i];
            }
        }
        return ret;
    }
};