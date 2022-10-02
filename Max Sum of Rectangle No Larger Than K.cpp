int dp[102][102];
class Solution {
public:
    /*
    dp[i][j]==sum of submatrix from (0,0) to (i,j)
    we then consider every pair of columns and part between two colums will be considered as a array
    and the problem becomes similar to that for an array
    REFER---https://www.quora.com/Given-an-array-of-integers-A-and-an-integer-k-find-a-subarray-that-contains-the-largest-sum-subject-to-a-constraint-that-the-sum-is-less-than-k
    */
    int fun(int r1,int c1,int r2,int c2)
    {
        if(c1==0)
            return dp[r2][c2];
        return dp[r2][c2]-dp[r2][c1-1];
    }
    int maxSumSubmatrix(vector<vector<int>>& matrix, int K) {
        memset(dp,-1,sizeof(dp));
        int n=matrix.size();
        int m=matrix[0].size();
        dp[0][0]=matrix[0][0];
        for(int i=1;i<n;i++)
            dp[i][0]=dp[i-1][0]+matrix[i][0];
        for(int i=1;i<m;i++)
            dp[0][i]=dp[0][i-1]+matrix[0][i];
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
                dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+matrix[i][j];
        }
        int ans=INT_MIN;
        for(int i=0;i<m;i++)
        {
            for(int j=i;j<m;j++)
            {
                set<int> st;
                st.insert(0);
                for(int k=0;k<n;k++)
                {
                    int s=fun(0,i,k,j);
                   // cout<<0<<" "<<i<<" "<<k<<" "<<j<<" "<<s<<endl;
                    auto it=st.lower_bound(s-K);
                    if(it!=st.end())
                    {
                        ans=max(ans,s-*(it));
                    }
                    st.insert(s);
                }
            }
        }
        return ans;
    }
};
