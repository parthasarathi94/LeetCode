//Question Link: https://leetcode.com/problems/maximum-beauty-of-an-array-after-applying-operation/description/

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int, int>>intervals(n);

        for(int i=0; i<n; i++){
            intervals[i] = {nums[i] - k, nums[i] + k};
        }
        
        sort(intervals.begin(), intervals.end());

        deque<pair<int, int>>deq;
        int maxBeauty = 0;
        for(pair<int, int>&interval : intervals){
            while(!deq.empty() && deq.front().second < interval.first){
                deq.pop_front();
            }
            deq.push_back(interval);
            maxBeauty = max(maxBeauty, (int)deq.size());
        }
        return maxBeauty;
    }
};
