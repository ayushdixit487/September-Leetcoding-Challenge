class Solution {
public:
    int compareVersion(string v1, string v2) {
      int n1=  v1.length();
        int n2 = v2.length();
        int i=0;
        int j=0;
        while(i<n1|| j<n2){
            int num1=0;
            int num2=0;
            while(i<n1 && v1[i]!='.'){
                int num =0;
                num=v1[i]-'0';
                num1 = num1*10+num;
                i++;
            }
            
            while(j<n2 && v2[j]!='.'){
                int num =0;
                num=v2[j]-'0';
                num2 = num2*10+num;
                j++;
            }
            if(num1<num2)
                return -1;
            if(num2<num1)
                return 1;
            if(num1==num2)
            {
                i++;
                j++;
            }
        }
        return 0;
    }
    
};
