class Solution {
public:
    long long reverse(int x) {
        int d=0;long long s=0;
        long long min= -pow(2,31);
        long long max= -1*min;
        while (x!=0)
        {
            d=x%10;
            s=s*10+d;
            x=x/10;
        }
        if(s>=min&& s<=max)
            return s;
        else
            return 0;
        
    }
};
