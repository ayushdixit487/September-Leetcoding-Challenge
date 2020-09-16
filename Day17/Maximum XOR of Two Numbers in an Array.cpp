class Solution {
public:
    struct Trie{
        Trie* children[2];
        Trie(){
        for(int i=0;i<2;i++)
            this->children[i]=NULL;
        }
    };
    
    Trie* Node=new Trie();
    void Insert(string &s){
        int i,n=s.length();
        Trie* temp=Node;
        for(i=0;i<n;i++){
            if(temp->children[s[i]-'0']==NULL){
                Trie* temp2=new Trie();
                temp->children[s[i]-'0']=temp2;
            }
            temp=temp->children[s[i]-'0'];
        }
    }
    int Search(string &s){
        int i,n=s.length();
        Trie* temp=Node;
        int ans=0;
        for(i=0;i<n;i++){
            if(temp->children[abs(s[i]-'0'-1)]!=NULL){
                ans=2*ans+1;
                temp=temp->children[abs(s[i]-'0'-1)];
            }
            else{
                ans=2*ans;
                temp=temp->children[s[i]-'0'];
            }
        }
        
        return ans;
    }
    
    int findMaximumXOR(vector<int>& nums) {
        int n=nums.size(),i;
        string S[n];
        for(i=0;i<n;i++){
            int a=nums[i];
            while(a!=0 || S[i].length()<31){
                S[i]+=('0'+a%2);
                a/=2;
            }
        }
        
        for(i=0;i<n;i++){
            reverse(S[i].begin(),S[i].end());
        }
        Insert(S[0]);
        int m=0;
        for(i=1;i<n;i++){
            m=max(m,Search(S[i]));
            Insert(S[i]);
        }
        return m;
    }
};
