#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isp(int n){
        if(n==1)
            return 0;
        for(int i=2;i*i<=n;i++){
            if(n%i==0)
                return 0;
        }
        return 1;
    }
    int get_rev(int n){
        int rev=0;
        while(n>0){
            rev=rev*10+(n%10);
            n/=10;
        }
        return rev;
    }
    int sumOfPrimesInRange(int n) {
        int ans=0,lo=n,hi=get_rev(n);
        if(lo>hi)
            swap(lo,hi);
        
        for(int i=lo;i<=hi;i++){
            ans=ans+isp(i)*i;
        }

        return ans;
    }
};