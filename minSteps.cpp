class Solution {
public:
    int minSteps(int n) {
        int dp[n+1];
        dp[1]=0;
        for(int i=2;i<=n;i++)
            dp[i]=i;
        for(int i=2;i<=n;i++)
        {
            for(int j=2*i;j<=n;j+=i)
                dp[j]=min(dp[j],dp[i]+j/i);
        }
        return dp[n];
    }
};
