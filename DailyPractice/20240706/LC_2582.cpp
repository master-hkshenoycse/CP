#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int passThePillow(int n, int time) {
        
        int curr=1,ad=1;
        while(time--){
            if(curr==n){
                ad=-1;
            }if(curr==1){
                ad=1;
            }
            curr=curr+ad;
        }
        
        return curr;
        
        
    }
};