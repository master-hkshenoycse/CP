#include<bits/stdc++.h>
using namespace std;
bool comp(vector<int> &a, vector<int> &b){
        return a[1] != b[1] ? a[1] < b[1] : a[0] > b[0];
}
class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
         sort(intervals.begin(), intervals.end(), comp);
        int a,b=INT_MIN,ans=0;
        for(auto interval:intervals){
            if(b<interval[0]){
                a = interval[1]-1;
                b = interval[1];
                ans += 2;
            }
            else if(a<interval[0]){
                a = b;
                b = interval[1];
                ans += 1;
            }
        }
        return ans;
    }
};