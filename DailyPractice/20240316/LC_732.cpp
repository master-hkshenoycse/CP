#include<bits/stdc++.h>
#define ll long
using namespace std;

class MyCalendarThree {
public:
    map<int,int>events;
    
    MyCalendarThree() {
        events.clear();
    }
    
    
    int book(int start, int end) {
        int cs=0,ans=0;        
        events[start]++;
        events[end]--;
        
        for(auto it:events){
            cs=cs+(it.second);
            ans=max(ans,cs);
        }
        
        return ans;
    }
};
