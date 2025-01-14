// Question Link: https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/description/

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<bool>isPresentInA(n+1, false);
        vector<bool>isPresentInB(n+1, false);
        vector<int>result(n, 0);
        for(int i=0; i<n; i++){
            int count = 0;
            isPresentInA[A[i]] = true;
            isPresentInB[B[i]] = true;
            for(int i=1; i<=n; i++){
                if(isPresentInA[i] && isPresentInB[i]){
                    count++;
                }
            }
            result[i] = count;
        }
        return result;
    }
};
