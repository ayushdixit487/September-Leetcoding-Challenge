class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
	int res=0;
	for(int i=0; i<A.size(); i++)
		for(int j=0; j<A[0].size(); j++)
			res = max({res, getOverlap(A, B, i, j), getOverlap(B, A, i, j)});

	return res;
 }

int getOverlap(vector<vector<int>>& A, vector<vector<int>>& B, int offi, int offj){
	int res=0;
	for(int i=offi; i<A.size(); i++)
		for(int j=offj; j<A[0].size(); j++)
			res+=A[i][j]*B[i-offi][j-offj];

	return res;
 }
    
  
};
