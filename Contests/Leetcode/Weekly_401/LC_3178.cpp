#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numberOfChild(int n, int k) {
        k%=(2*n-2);
        if(k<=n-1){
            return k;
        }else{
            return 2*(n-1)-k;
        }

    }
};