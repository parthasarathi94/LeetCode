//Question Link: https://leetcode.com/problems/maximum-candies-allocated-to-k-children/description/

class Solution {
public:

    int n;
    bool canDistribute(vector<int>& candies, long long k, int mid){
        for(int i=0; i<n; i++){
            k -= candies[i]/mid;
            if(k <= 0) return true;
        }
        return k <= 0;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        n = candies.size();
        long long totalPiles = 0;
        int maxPile = 0;
        for(int i=0; i<n; i++){
            maxPile = max(maxPile, candies[i]);
            totalPiles += candies[i];
        }
        if(totalPiles < k) return 0;

        int l = 1;
        int r = maxPile;
        int result = 0;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(canDistribute(candies, k, mid)){
                result = mid;
                l = mid+1;
            }else r = mid-1;
        }

        return result;
    }
};
