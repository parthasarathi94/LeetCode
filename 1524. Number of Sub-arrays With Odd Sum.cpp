//Question Link: https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/description/

class Solution {
public:
   
    int MOD = 1e9 + 7;

    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        vector<int>prefixSum(n, 0);
        int oddCount = 0;
        int evenCount = 1;
        int count = 0;
        prefixSum[0] = arr[0];
        if(prefixSum[0]%2 != 0){
            count = (count + evenCount) % MOD;
            oddCount++;
        }else{
            count = (count + oddCount) % MOD;
            evenCount++;
        }
        for(int i=1; i<n; i++){
            prefixSum[i] = prefixSum[i-1] + arr[i];
            if(prefixSum[i]%2 != 0){
                count = (count + evenCount) % MOD;
                oddCount++;
            }else{
                count = (count + oddCount) % MOD;
                evenCount++;
            }
        }

        return count;
    }
};
