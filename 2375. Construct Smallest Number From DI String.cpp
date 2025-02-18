//Question Link: https://leetcode.com/problems/construct-smallest-number-from-di-string/description/

class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.length();

        string num = ""; 

        int counter = 1;
        stack<char> st;

        for(int i = 0; i <= n; i++) {
            st.push(counter + '0');
            counter++;

            if(i == n || pattern[i] == 'I') {
                while(!st.empty()) {
                    num += st.top();
                    st.pop();
                }
            }
        }

        return num;
    }
};
