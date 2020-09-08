class Solution {
public:
    bool wordPattern(string pattern, string str) {
        int k=0;
        string temp="";
        map<char,string> mp;
        map<string,char> mp1;
        for(int i=0;i<str.size();i++)
        {
            if(str[i]==' '){
                if(mp.find(pattern[k])!=mp.end())
                {
                   if(mp[pattern[k]]!=temp) return 0;
                }
                else
                if(mp1.find(temp)!=mp1.end())
                {
                   if(mp1[temp]!=pattern[k]) return 0;
                }
                else
                { 
                    mp[pattern[k]]=temp;
                    mp1[temp]=pattern[k];
                }
                temp="";
                k++;
                    
            }
            else
                temp+=str[i];
        }
         if(mp.find(pattern[k])!=mp.end())
                {
                   if(mp[pattern[k]]!=temp) return 0;
                }
                else
                if(mp1.find(temp)!=mp1.end())
                {
                   if(mp1[temp]!=pattern[k]) return 0;
                }
        
        if(k<pattern.size()-1) return 0;
        return 1;
    }
};
