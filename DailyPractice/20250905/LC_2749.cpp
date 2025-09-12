#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    ll cnt_ones(ll val){
        ll c=0;
        while(val){
            c++;
            val=(val & (val-1));
        }
        return c;
    }
    int makeTheIntegerZero(int num1, int num2) {
        
        
        for(ll i=1;i<=100;i++){
            ll value=num1-i*num2;
            
            cout<<i<<" "<<value<<endl;
            if(value>=i and cnt_ones(value)<=i){
                return i;
            }
        }
        
        return -1;
        
    }
};