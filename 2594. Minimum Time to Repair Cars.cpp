//Question Link: https://leetcode.com/problems/minimum-time-to-repair-cars/description/

class Solution {
public:

    typedef long long ll;

    bool isPossible(vector<int>& ranks, int cars, ll time){
        ll carsCount = 0;
        for(int &rank : ranks){
            carsCount += sqrt(time/rank);
        }
        
        return carsCount >= cars;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        int maxRank = *max_element(begin(ranks), end(ranks));
        ll l = 1;
        ll r = 1LL*maxRank*cars*cars;
        ll result = -1;

        while(l <= r){
            ll mid = l + (r-l)/2;
            if(isPossible(ranks, cars, mid)){
                result = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }

        return result;
    }
};
