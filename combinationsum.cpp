class Solution {
public:
    void helper(vector<int>&temp, vector<vector<int>> & ans, int index,int & sum,int &target,vector<int> &candidate)
    {
        if(index == candidate.size() or sum > target)
            return;
        if(sum == target)
        {
            ans.push_back(temp);
            return;
        }
        //two choice either pick or leave
        //at first we pick
        sum += candidate[index];
        temp.push_back(candidate[index]);
        helper(temp,ans,index,sum,target,candidate);
        temp.pop_back();
        sum -= candidate[index];
        helper(temp,ans,index+1,sum,target,candidate) ;   

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<vector<int>>ans ;
        vector<int> temp;
        int sum = 0;
        int index = 0;
        helper(temp, ans, index, sum , target, candidates);
        return ans;
        
        
             
    }
};