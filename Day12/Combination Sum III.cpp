class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> res;
        vector<int> temp;
        subsets(1,n,temp,res,k);
        
        return res;
    }
        
    void subsets(int in ,int n ,vector<int> op,         vector<vector<int>> & res, int k){
           if(op.size()==k && n==0){
             res.push_back(op);
               return;
           }
        if(op.size()>k)
            return ;
        if(n<0)
            return;
        
            for(int i= in;i<=9;i++){
                op.push_back(i);
                subsets(i+1 , n-i,op,res,k);
                op.pop_back();
            } 
    }
};
