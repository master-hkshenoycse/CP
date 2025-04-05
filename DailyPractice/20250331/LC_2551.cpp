#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long putMarbles(vector<int>& Arr, int k) {
        priority_queue<ll> p1,p2;
        int N=Arr.size();
        ll ma=Arr[0]+Arr[N-1],mi=Arr[0]+Arr[N-1];
        
        for(int i=0;i<N-1;i++){
            p1.push(Arr[i]+Arr[i+1]);
            p2.push(-(Arr[i]+Arr[i+1]));
        }
        
        for(int i=0;i<k-1;i++){
            ma=ma+p1.top();
            p1.pop();
            
            mi=mi-p2.top();
            p2.pop();
        }
        
        return ma-mi;
    }
};