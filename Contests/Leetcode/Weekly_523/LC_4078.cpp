#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    bool threeFibonacciSum(int n) {
        vector<ll> fib(52,0);
        fib[0]=0;
        fib[1]=1;
        for(int i=2;i<=50;i++)
            fib[i]=fib[i-1]+fib[i-2];

        for(int i=0;i+2<=50;i++)
            if(fib[i]+fib[i+1]+fib[i+2]==n)
                return 1;
        return 0;
    }
};