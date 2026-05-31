#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        ll m=mass;
        for(auto a:asteroids){
            if(m>=a){
                m+=(ll)a;
            }else{
                return 0;
            }
        }
        return 1;
    }
};