#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int get_set(int n){
        int c=0;
        while(n>0){
            c++;
            n=(n & (n-1));
        }
        return c;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),[&](int a,int b){
            int sa=get_set(a);
            int sb=get_set(b);
            if(sa==sb)return a<b;
            if(sa<sb)return true;
            return false;
        });
        return arr;
    }
};