#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int distinctPoints(string s, int k) {
        int n=s.size();
        vector<int> csum_x(n+1,0),csum_y(n+1,0);

        for(int i=1;i<=n;i++){
            csum_x[i]=csum_x[i-1];
            csum_y[i]=csum_y[i-1];
            char ch=s[i-1];
            if(ch=='U'){
                csum_y[i]++;
            }else if(ch=='D'){
                csum_y[i]--;
            }else if(ch=='L'){
                csum_x[i]--;
            }else if(ch=='R'){
                csum_x[i]++;
            }
        }

        set<pair<int,int> > c;

        for(int i=1;i+k-1<=n;i++){
            c.insert({csum_x[n]-(csum_x[i+k-1]-csum_x[i-1]),csum_y[n]-(csum_y[i+k-1]-csum_y[i-1])});
        }

        return c.size();




    }
};