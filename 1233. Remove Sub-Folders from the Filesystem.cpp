// Question Link: https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/description/

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_set<string>st(folder.begin(), folder.end());
        vector<string>result;

        for(string currFolder : folder){
            bool isSubFolder = false;
            string tempFolder = currFolder;

            while(!currFolder.empty()){
                size_t lastSlashPosition = currFolder.find_last_of('/');
                currFolder = currFolder.substr(0, lastSlashPosition);

                if(st.find(currFolder) != st.end()){
                    isSubFolder = true;
                    break;
                }
            }

            if(!isSubFolder){
                result.push_back(tempFolder);
            }
        }
        return result;
    }
};
