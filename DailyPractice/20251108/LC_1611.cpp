#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumOneBitOperations(int n) {
        if(n==0){
            return 0;
        }
        int k=0;
        int curr=1;
        while(curr*2<=n){
            curr=curr*2;
            k++;
        }

          return (1 << (k + 1)) - 1 - minimumOneBitOperations(n ^ curr);

       
    }
};