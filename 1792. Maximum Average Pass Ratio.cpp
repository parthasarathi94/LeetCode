//Question Link: https://leetcode.com/problems/maximum-average-pass-ratio/description/

class Solution {
public:

    #define P pair<double, int>

    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        priority_queue<P>pq;
        for(int i=0; i<n; i++){
            double currPR = (double)classes[i][0]/classes[i][1];
            double newPR = (double)(classes[i][0]+1)/(classes[i][1]+1);
            double delta = newPR - currPR;
            pq.push({delta, i});
        }

        while(extraStudents--){
            auto temp = pq.top();
            pq.pop();
            double delta = temp.first;
            int index = temp.second;
            classes[index][0]++;
            classes[index][1]++;

            double currPR = (double)classes[index][0]/classes[index][1];
            double newPR = (double)(classes[index][0]+1)/(classes[index][1]+1);
            delta = newPR - currPR;
            pq.push({delta, index});
        }

        double result = 0.0;
        for(int i=0; i<n; i++){
            result += (double)classes[i][0]/classes[i][1];
        }

        return result/n;
    }
};
