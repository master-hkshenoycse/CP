#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProduct(int n) {
        string num=to_string(n);
        int sz=num.size();

        int ans=0;
        for(int i=0;i<sz;i++){
            for(int j=i+1;j<sz;j++){
                ans=max(ans,(num[i]-'0')*(num[j]-'0'));
            }
        }
        return ans;
    }
};