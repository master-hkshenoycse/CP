#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumWidth(vector<int>& rods) {
        unordered_map<int, int> freq;
        
        for (int x : rods)
            freq[x]++;

        vector<int> heights;
        for (auto &[h, f] : freq)
            heights.push_back(h);

        unordered_map<int, int> pairs;

        int k = heights.size();

        // Count how many disjoint pairs can produce each height.
        for (int i = 0; i < k; i++) {
            for (int j = i; j < k; j++) {
                int a = heights[i];
                int b = heights[j];

                int cnt;

                if (a == b)
                    cnt = freq[a] / 2;
                else
                    cnt = min(freq[a], freq[b]);

                pairs[a + b] += cnt;
            }
        }

        int ans = 0;

        // Existing rods + rods formed by combining two rods.
        for (auto &[height, cnt] : pairs) {
            int existing = freq.count(height) ? freq[height] : 0;
            ans = max(ans, existing + cnt);
        }

        // In case the best fence uses only existing rods.
        for (auto &[height, cnt] : freq)
            ans = max(ans, cnt);

        return ans;
    }
};