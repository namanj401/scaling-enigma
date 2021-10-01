class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        if(nums.size()<3)
            return ans;
        
        sort(nums.begin(),nums.end());
        
        
        for(int i=0;i<nums.size()-2;i++)
        {
            vector<int> temp;int a=0-nums[i];
            int j=i+1;int k=nums.size()-1;
            if(i>0&&nums[i]==nums[i-1])
                continue;
            while(j<k)
            {
                if(nums[j]+nums[k]==a)
                {
                    vector<int> temp;
                    temp.push_back(nums[i]);temp.push_back(nums[j]);temp.push_back(nums[k]);
                   // if(find(ans.begin(),ans.end(),temp)== ans.end())
                    ans.push_back(temp);
                    j++;k--;
                    while(nums[j]==nums[j-1]&&j<k)
                        j++;
                    while(nums[k]==nums[k+1]&&j<k)
                        k--;
                }
                else if(nums[j]+nums[k]<a)
                {
                    j++;
                }
                else
                    k--;
            }
        }
        return ans;
        
    }
    
};
