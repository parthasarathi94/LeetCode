//Question Link: https://leetcode.com/problems/max-chunks-to-make-sorted/description/

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int>prevMax(n);
        prevMax[0] = arr[0];
        for(int i=1; i<n; i++){
            prevMax[i] = max(arr[i], prevMax[i-1]);
        }

        vector<int>nextMin(n);
        nextMin[n-1] = arr[n-1];
        for(int i=n-2; i>=0; i--){
            nextMin[i] = min(arr[i], nextMin[i+1]);
        }

        int chunks = 0;

        for(int i=0; i<n; i++){
            int prevmax = i>0 ? prevMax[i-1] : -1;
            int nextmin = nextMin[i];
            if(prevmax < nextmin) chunks++;
        }

        return chunks;
    }
};
