class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& A, vector<int>& B) {
        int n = A.size();
        
        A.push_back(B);
        sort(A.begin(),A.end());
        
        vector<vector<int>> res;
        
        for(int i=0; i<n+1; i++)
        {
            if(i == 0)
                res.push_back(A[i]);
            else
            {
                if(res[res.size()-1][1] >= A[i][0])
                    res[res.size()-1][1] = max(res[res.size()-1][1] , A[i][1]);
                else
                    res.push_back(A[i]);
            }
                
        }
        return res;
    }
};
