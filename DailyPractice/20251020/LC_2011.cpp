#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans=0;
        for(auto ch:operations){
            if(ch[0]=='-' or ch[2]=='-')ans--;
            else ans++;
        }
        return ans;
    }
};