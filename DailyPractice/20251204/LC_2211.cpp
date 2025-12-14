#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        int l = 0, r = n - 1;

        while (l < n && directions[l] == 'L') {
            l++;
        }

        while (r >= l && directions[r] == 'R') {
            r--;
        }

        int res = 0;
        for (int i = l; i <= r; i++) {
            if (directions[i] != 'S') {
                res++;
            }
        }
        return res;
    }
};

/*
We define a vehicle that continuously moves outward (either left or right) without being blocked by a reversing or stationary vehicle in between as an "outward-moving vehicle."

Left-moving outward vehicles and right-moving outward vehicles will not collide with each other. All other vehicles will collide exactly once.*/