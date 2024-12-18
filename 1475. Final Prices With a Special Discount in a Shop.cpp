//Question Link: https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/description/

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        stack<int>st;
        vector<int>answer(begin(prices), end(prices));
        for(int i=0; i<n; i++){
            while(!st.empty() && prices[i] <= prices[st.top()]){
                answer[st.top()] -= prices[i];
                st.pop();
            }
            st.push(i);
        }
        return answer;
    }
};
