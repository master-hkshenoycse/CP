#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int getSet(int n){
        int c=0;
        while(n>0){
            c++;
            n=(n & (n-1));
        }
        return c;
    }
    int minimizeXor(int num1, int num2) {
        int x=0,b=getSet(num2);
        for(int i=30;i>=0;i--){
            if(num1 & (1<<i)){
                if(b>0){
                    x=x+(1<<i);
                    b--;
                }
            }
        }
        
        for(int i=0;i<=30;i++){
            if(x & (1<<i)){
                continue;
            }
            if(b>0){
                x=x+(1<<i);
                b--;
            }
        }
        
        return x;
    }
};