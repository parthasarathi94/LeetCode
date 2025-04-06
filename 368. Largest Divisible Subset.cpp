// Question Link: https://leetcode.com/problems/largest-divisible-subset/description/ 

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<int>t(n, 1);
        vector<int>prevIndex(n, -1);

        int maxL = 1;
        int lastChosenIndex = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i] % nums[j] == 0){
                    if(t[i] < t[j] + 1){
                        t[i] = t[j] + 1;
                        prevIndex[i] = j;
                    }
                    if(t[i] > maxL){
                        maxL = t[i];
                        lastChosenIndex = i;
                    }
                }
            }
        }

        vector<int>result;
        while(lastChosenIndex != -1){
            result.push_back(nums[lastChosenIndex]);
            lastChosenIndex = prevIndex[lastChosenIndex];
        }

        return result;
    }
};
