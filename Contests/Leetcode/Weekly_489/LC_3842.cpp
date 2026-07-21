#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        sort(bulbs.begin(),bulbs.end());
        int i=0,n=bulbs.size();
        vector<int> ret;

        while(i<n){
            int j=i,cnt=0;
            while(j<n && bulbs[i]==bulbs[j]){
                cnt++;
                j++;
            }

            if(cnt%2)
                ret.push_back(bulbs[i]);
            i=j;
        }


        return ret;
    }
};