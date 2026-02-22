#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prev=-1;
        while(n>0){
            if(prev == (n%2)){
                return 0;
            }

            prev=(n%2);
            n/=2;
        }

        return 1;
    }
};