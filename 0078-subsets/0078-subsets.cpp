class Solution {
public:

   void findSubsets(vector<int>nums, int index , int n, vector<int> temp, vector<vector<int>>&ans  ){

    if (index == n){
        ans.push_back (temp);
        return ;
    }


    // Ek baar value le lo 

    temp.push_back(nums[index]);
    findSubsets (nums,index+1,n,temp,ans);

    // Ek baar value ko mat lo 

     temp.pop_back ();
      findSubsets (nums,index+1,n,temp,ans);

   }


    vector<vector<int>> subsets(vector<int>& nums) {

        vector <vector<int>>ans;
        vector <int>temp;

        findSubsets(nums,0,nums.size(),temp, ans);


        return ans;

        
    }
};