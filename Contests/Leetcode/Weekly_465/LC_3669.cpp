#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> best;
    int bestDiff = INT_MAX;
    void check(vector<int> &curr){
        int mn = *min_element(curr.begin(), curr.end());
        int mx = *max_element(curr.begin(), curr.end());

        if(mx - mx < bestDiff){
            bestDiff = mx-mn;
            best = curr;
        }

    }

    void backtrack(int n,int k, int start, vector<int> &curr){
        if(k==1){
            if(n>=start){
                curr.push_back(n);
                check(curr);
                curr.pop_back();
            }
            return;
        }

        for(int i=start;i<=n;i++){
            if(n%i==0){
                curr.push_back(i);
                backtrack(n/i, k-1, i, curr);
                curr.pop_back();
            }
        }
    }
    vector<int> minDifference(int n, int k) {
        vector<int> curr;
        backtrack(n, k, 1, curr);
        return best;
    }
};