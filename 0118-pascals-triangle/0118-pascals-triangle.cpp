class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans ;
        for(int i = 0; i < numRows; i++){
            vector<int>temp;
            int val = 1;
            for(int j = 0 ; j <= i ; j++){
                temp.push_back(val);
                val = val*(i-j)/(j+1);
            }
            ans.push_back(temp);
        }
        return ans ;
    }
};