#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int smallestNumber(int n) {
        for(int i=0;i<=30;i++){
            if((1<<i)-1>=n){
                return (1<<i)-1;
            }
        }
        return -1;
    }
};