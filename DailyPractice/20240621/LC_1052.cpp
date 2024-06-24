#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int j=0,max_gain=0,gain=0,cs=0,n=customers.size();

        for(int i=0;i<n;i++){
            cs=cs+(1-grumpy[i])*customers[i];

            gain=gain+grumpy[i]*customers[i];

            if(i-j>=minutes){
                gain=gain-grumpy[j]*customers[j];
                j++;
            }

            max_gain=max(max_gain,gain);

        }
        return cs+max_gain;

        return cs+max_gain;
    }
};