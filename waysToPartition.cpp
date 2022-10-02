#define ll long long int
class Solution {
public:
    int waysToPartition(vector<int>& nums, int k) {
        int n=nums.size();
        vector<ll> pre(n,0);
        vector<ll> suf(n,0);
        pre[0]=nums[0];
        for(int i=1;i<n;i++)
            pre[i]=pre[i-1]+nums[i];
        suf[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            suf[i]=suf[i+1]+nums[i];
        }
        ll ans=0;
        for(int i=1;i<n;i++)
        {
            if(pre[i-1]==suf[i])
                ans++;
        }
        unordered_map<ll,ll> left,right;
        for(int i=0;i<n-1;i++)
            right[pre[i]-suf[i+1]]++;
        for(int i=0;i<n;i++)
        {
            ll tmp=0;
            int diff=k-nums[i];
            if(left.count(diff))
                tmp+=left[diff];
            if(right.count(-diff))
                tmp+=right[-diff];
            if(i<n-1)
            {
                int f=pre[i]-suf[i+1];
                left[f]++;
                right[f]--;
                if(right[f]==0)
                    right.erase(f);
            }
            ans=max(ans,tmp);
        }
        return ans;
        
        
    }
};
