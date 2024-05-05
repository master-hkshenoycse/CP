#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n=people.size(),ans=n;
        sort(people.begin(),people.end());

        int lo=0,hi=n-1;

        while(hi>lo){
            if(people[lo]+people[hi]<=limit){
                ans--;
                lo++;
                hi--;
            }else{
                hi--;
            }
        }

        return ans;
    }
};