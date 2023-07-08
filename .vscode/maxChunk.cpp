class Solution {
public:
    int maxChunksToSorted(vector<int>& arr)
    {
       int count = 0 ;
       int max_ = 0;
       int n = arr.size();
       for(int i = 0 ; i< n ; i++)
       {
           max_ =max(max_ , arr[i]);
           if(i == max_)
           {
               count++;
           }    
       }   
        return count; 
    }
};