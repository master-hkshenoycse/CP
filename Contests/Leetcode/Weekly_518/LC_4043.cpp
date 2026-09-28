#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countRotations(string s, int k) {
        int ans=0,n=s.size();
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j+1<n;j++)
                cnt=cnt+(s[(i+j)%n]==s[(i+j+1)%n]);
            ans=ans+(cnt==k);
        }
        return ans;
    }
};