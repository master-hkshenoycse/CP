#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countMonobit(int n) {
        int st=1,ans=1;
        while(st<=n){
            ans++;
            st=st*2+1;
        }
        return ans;
    }
};