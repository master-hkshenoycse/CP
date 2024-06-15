#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=profits.size();
        vector<vector<int> > a(n,vector<int> (2));

        for(int i=0;i<n;i++){
            a[i][0]=capital[i];
            a[i][1]=profits[i];
        }

        sort(a.begin(),a.end());
        priority_queue<int> pq;
        int i=0;
        while(k--){
            while(i<n and a[i][0]<=w){
                pq.push(a[i][1]);
                i++;
            }

            if(pq.size()>0){
                w=w+pq.top();
                pq.pop();
            }
        }

        return w;


        return w;
    }
};