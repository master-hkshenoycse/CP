#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n=arr.size();
        for(int i=0;i+2<n;i++){
            if(arr[i]%2 and arr[i+1]%2 and arr[i+2]%2){
                return 1;
            }
        }
        return 0;
    }
};