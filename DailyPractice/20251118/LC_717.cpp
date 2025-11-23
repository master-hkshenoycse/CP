#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();

        for(int i=0;i<n;){
            if(i==n-1){
                return 1;
            }

            if(bits[i]==0){
                i++;
            }else{
                i+=2;
            }
        }

        return 0;
    }
};