// Question Link: https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/description/

class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n=s.size();
        if(n&1) return false;

        int opening = 0, closing = 0;
        int wild_card = 0;
        for(int i=0;i<n;++i){
            if(locked[i]=='0')  wild_card++;
            else if(s[i]=='(')  opening++;
            else                closing++;

            if(wild_card < (closing - opening))
                return false;
        }

        opening = closing = wild_card = 0;
        for(int i=n-1;i>0;--i){
            if(locked[i]=='0')  wild_card++;
            else if(s[i]=='(')  opening++;
            else                closing++;

            if(wild_card < (opening - closing))
                return false;
        }
        return true;
    }
};
