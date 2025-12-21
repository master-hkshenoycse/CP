#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        int n=order.size();
        vector<int> rank_(n);

        for(int i=0;i<n;i++){
            rank_[order[i]-1]=i;
        }

        sort(friends.begin(), friends.end(), [&](const int &x, const int &y) {
            return rank_[x-1] < rank_[y-1];
        });

        return friends;
    }
};