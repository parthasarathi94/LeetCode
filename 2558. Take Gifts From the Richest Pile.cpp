//Question Link: https://leetcode.com/problems/take-gifts-from-the-richest-pile/description/

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        int n = gifts.size();
        long long initialSum = 0;
        for(int &gift : gifts){
            initialSum += gift;
        }

        priority_queue<int>pq(begin(gifts), end(gifts));
        long long currSum = 0;
        while(k--){
            int maxEle = pq.top();
            pq.pop();
            int remaining = sqrt(maxEle);
            currSum += maxEle - remaining;
            pq.push(remaining);
        }
        return initialSum - currSum;
    }
};
