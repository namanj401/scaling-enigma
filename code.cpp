class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int a=0;map<char,int>strmap;
        int b=0;
        for(int i=0;i<s.length();i++)
        {
            
           
                if(strmap.find(s[i])==strmap.end())
                    strmap[s[i]]=i;
                else
                {   
                    for(int j=b;j<strmap[s[i]];j++)
                    {
                        strmap.erase(s[j]);
                    }
                    b=strmap[s[i]]+1;
                     strmap[s[i]]=i;
                }
                   
            
            if(strmap.size()>a)
                a=strmap.size();
        }
            
        return a;
    }
};
