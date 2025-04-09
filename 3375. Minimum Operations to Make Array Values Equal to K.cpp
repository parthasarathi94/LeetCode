//Question Link: https://leetcode.com/problems/minimum-operations-to-make-array-values-equal-to-k/description/

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int minEle = *min_element(begin(nums), end(nums));
        if(minEle < k) return -1;
        
        unordered_set<int>st(begin(nums), end(nums));
        if(st.count(k)) return st.size()-1;
        else return st.size();
    }
};
