#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int ans=0,n=target.size();

        for(int i=0;i+1<n;i++){
            if(target[i+1]>target[i]){
                ans=ans+target[i+1]-target[i];
            }
        }
        return ans+target[0];
    }
};