// Link: https://leetcode.com/problems/find-the-k-th-character-in-string-game-ii/description/

class Solution {
public:
    char findKthBit(int n, int k) {
        int length = pow(2,n) - 1;

        if(n == 1) return '0';

        if(k < ceil(length/2.0)){
            return findKthBit(n-1, k);
        }else if(k == ceil(length/2.0)){
            return '1';
        }else{
            char ch = findKthBit(n-1, length-(k-1));
            return (ch == '0') ? '1' : '0';
        }
    }
};


// Time Complexity: O(n)
// Space Complexity: O(n) (due to system stack)
