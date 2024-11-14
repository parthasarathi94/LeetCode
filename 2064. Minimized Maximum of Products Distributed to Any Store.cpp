// Question Link : https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/description/

class Solution {
public:

    bool possibleToDistribute(int x, int stores, vector<int>& quantities){
        for(int &product : quantities){
            stores -= ceil(static_cast<double>(product) / x);

            if(stores < 0) return false;
        }
        return true;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {
        int m = quantities.size();
        int l = 1;
        int r = *max_element(quantities.begin(), quantities.end());
        int result = 0;

        while(l <= r){
            int mid = l + (r-l)/2;
            if(possibleToDistribute(mid, n, quantities)){
                result = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        return result;
    }
};
