#include <bits/stdc++.h>
using namespace std;
#include <vector>
#include <set>
#include <queue>
#include <algorithm>

class Solution {
public:
    std::vector<int> busiestServers(int k, std::vector<int>& arrival, std::vector<int>& load) {
        std::vector<int> request_count(k, 0);
        
        std::set<int> available;
        for (int i = 0; i < k; ++i) {
            available.insert(i);
        }
        
        std::priority_queue<std::pair<int, int>, 
                            std::vector<std::pair<int, int>>, 
                            std::greater<std::pair<int, int>>> busy;
        
        int max_requests = 0;
        int n = arrival.size();
        
        for (int i = 0; i < n; ++i) {
            int curr_time = arrival[i];
            int curr_load = load[i];
            
            while (!busy.empty() && busy.top().first <= curr_time) {
                available.insert(busy.top().second);
                busy.pop();
            }
            
            if (available.empty()) {
                continue;
            }
            
            int target = i % k;
            auto it = available.lower_bound(target);
            
            
            if (it == available.end()) {
                it = available.begin();
            }
            
            int assigned_server = *it;
            
            request_count[assigned_server]++;
            max_requests = std::max(max_requests, request_count[assigned_server]);
            
            busy.push({curr_time + curr_load, assigned_server});
            
            available.erase(it);
        }
        
        std::vector<int> result;
        for (int i = 0; i < k; ++i) {
            if (request_count[i] == max_requests) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};