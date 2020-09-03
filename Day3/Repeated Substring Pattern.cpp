class Solution {
public:
    bool repeatedSubstringPattern(string s) {
          string str="";
        int n=s.length();
        for(int i=0 ; i<n/2 ; i++){
            str += s[i];                           
            if(n%str.length()==0){
                string temp = str;
                int m = n/str.length(); temp="";
                while(m--) 
                temp+=str;  
                if(temp==s) 
                    return true;
            } 
        }
        
        return false;
    }
};
