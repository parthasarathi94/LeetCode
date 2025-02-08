//Question Link: https://leetcode.com/problems/design-a-number-container-system/description/

class NumberContainers {
public:

    unordered_map<int, int>idxToNum;
    unordered_map<int, set<int>>numToIndices;

    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(idxToNum.count(index)){
            int prevNum = idxToNum[index];
            numToIndices[prevNum].erase(index);
            if(numToIndices[prevNum].empty()){
                numToIndices.erase(prevNum);
            }
        }
        idxToNum[index] = number;
        numToIndices[number].insert(index);
    }
    
    int find(int number) {
        if(numToIndices.count(number)){
            return *numToIndices[number].begin();
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
