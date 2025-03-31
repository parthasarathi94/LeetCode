//Question Link: https://leetcode.com/problems/put-marbles-in-bags/description/

class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        int pairSize = n-1;

        vector<int>pairSum(n-1, 0);
        for(int i=0; i<pairSize; i++){
            pairSum[i] = weights[i] + weights[i+1];
        }

        sort(begin(pairSum), end(pairSum));
        long long minPairSum = 0;
        long long maxPairSum = 0;
        for(int j=0; j<k-1; j++){
            minPairSum += pairSum[j];
            maxPairSum += pairSum[pairSize - 1 - j];
        }

        return maxPairSum - minPairSum;
    }
};
