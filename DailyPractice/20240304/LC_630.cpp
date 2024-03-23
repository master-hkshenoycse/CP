#include<bits/stdc++.h>
using namespace std;


/*inlucude courses and greedily remove the courses with most duration if deadline is not satistfied*/


class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int n=courses.size();
        for(int i=0;i<n;i++){
            swap(courses[i][0],courses[i][1]);
        }

        sort(courses.begin(),courses.end());

        priority_queue<int> pq;
        int ans=0,csum=0;
        for(int i=0;i<n;i++){
            ans++;
            csum+=courses[i][1];
            pq.push(courses[i][1]);
            if(csum>courses[i][0]){
                ans--;
                csum-=pq.top();
                pq.pop();
            }

        }

        return ans;
    }
};