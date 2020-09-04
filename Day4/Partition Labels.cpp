class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> ans;
        int n = S.length();
        int j = 0 ; 
        int temp = 0;
        int last[26];
        
        for(int i = 0;i< n;i++){
            last[S[i]-'a'] = i;
        }
        
        for(int i = 0;i< n;i++){
             j  =  max(j , last[S[i]-'a']);
            if(i==j){
                ans.push_back(j-temp+1);
                temp = i+1;
            }
        }
        return ans;
    }
};
