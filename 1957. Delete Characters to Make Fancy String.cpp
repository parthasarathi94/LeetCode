// Question Link : https://leetcode.com/problems/delete-characters-to-make-fancy-string/description/

class Solution {
public:
    string makeFancyString(string s) {
        int n = s.length();

        string output = "";
        output.push_back(s[0]);
        int freq = 1;

        for(int i=1; i<n; i++){
            if(s[i] == output.back()){
                freq++;
                if(freq < 3) output.push_back(s[i]);
            }else{
                output.push_back(s[i]);
                freq = 1;
            }
        }

        return output;
    }
};
