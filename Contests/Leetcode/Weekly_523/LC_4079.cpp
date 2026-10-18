#include<bits/stdc++.h>
using namespace std;
bool isp=0;
vector<int> primes;

void pre_cum(){
    if(isp)
        return;
    isp=1;
    vector<int> is_prime(1000001,0);
    is_prime[1]=1;

    for(int i=2;i<=1000000;i++){
        if(is_prime[i]==0){
            primes.push_back(i);
            for(int j=2*i;j<=1000000;j+=i)
                is_prime[j]=1;
        }
    }
}
class Solution {
public:
    
    vector<int> maxPrimes(int n, int s) {
        pre_cum();
        vector<int> ret;
        
        for(auto p:primes){
            if(p>n)
                break;
                
            if(s>=p){
                ret.push_back(p);
                s-=p;
            }else{
                break;
            }
        }

        return ret;

        
    }
};