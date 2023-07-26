class Solution {
public:

    void helper(int index , unordered_map<char,string> & mp , string &digits , string &temp, vector<string> & ans)
    {
        if(index == digits.size())
        {
            ans.push_back(temp);
        }
        for(int i= 0 ; i< mp[digits[index]].size(); i++)
        {
            string str = mp[digits[index]];
            temp.push_back(str[i]);
            helper(index+1,mp,digits,temp,ans);
            temp.pop_back();            
        }
    }
    vector<string> letterCombinations(string digits)
    {
        vector<string> ans;
        string temp;
        unordered_map<char,string>mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        if(digits.size()>0)
            helper(0,mp,digits,temp,ans);
        
        return ans;


        
        
        
                         
    }
};