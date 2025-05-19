//Question Link: https://leetcode.com/problems/type-of-triangle/description/

class Solution {
public:
    string triangleType(vector<int>& nums) {
        bool isTriangle = false;
        if(nums[0] + nums[1] > nums[2] && nums[1] + nums[2] > nums[0] && nums[0] + nums[2] > nums[1]){
            isTriangle = true;
        }

        if(isTriangle){
            sort(begin(nums), end(nums));
            int count = 1;
            for(int i=0; i<nums.size(); i++){
                if(nums[i] == nums[i+1]){
                    count++;
                }
            }
            if(count == 3) return "equilateral";
            else if(count == 2) return "isosceles";
            else return "scalene";
        }

        return "none";
    }
};
