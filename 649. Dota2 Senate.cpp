// Question Link : https://leetcode.com/problems/dota2-senate/description/

class Solution {
public:
    int n;

    void removeSenator(string& senate, vector<bool>& isRemoved, char ch, int idx) {
        while (true) {
            if (senate[idx] == ch && isRemoved[idx] == false) {
                isRemoved[idx] = true;
                break;
            }
            idx = (idx + 1) % n;
        }
    }

    string predictPartyVictory(string senate) {
        n = senate.size();

        vector<bool> isRemoved(n, false);

        int R_count = count(senate.begin(), senate.end(), 'R');
        int D_count = count(senate.begin(), senate.end(), 'D');

        int idx = 0;

        while (R_count > 0 && D_count > 0) {

            if (isRemoved[idx] == false) {
                if (senate[idx] == 'R') {
                    removeSenator(
                        senate, isRemoved, 'D', (idx + 1) % (senate.length()));
                    D_count--;
                } else {
                    removeSenator(
                        senate, isRemoved, 'R', (idx + 1) % (senate.length()));
                    R_count--;
                }
            }

            idx = (idx + 1) % n;
        }

        return R_count == 0 ? "Dire" : "Radiant";
    }
};
