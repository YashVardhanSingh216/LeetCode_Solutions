// 238. Product of Array Except Self

// very manipulated code :)
// instead use prefix sum and suffix sum :)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        // if whole nums is 0
        unordered_map<int,int>m;
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum = sum+nums[i];
            m[nums[i]]++;
        }
        if(sum == 0 && m[0] == nums.size()) return nums;

        if(m[0] > 1){
            vector<int>temp(nums.size(),0);
            return temp;
        }


        int prod = 1;
        int index = 0;
        bool pre = 0;
        // int sum = 1;
        vector<int>ans;

        for(int  i=0; i<nums.size(); i++){

            if(nums[i] == 0){
            index = i;
            pre = 1;
            continue;
            } 
            prod = prod*nums[i];
        }


        if(pre == 1){
            for(int i=0;i<nums.size();i++){
                if(i == index) ans.push_back(prod);

                else ans.push_back(0);
            }
        }
        else{
            for(int i=0; i<nums.size(); i++){
                ans.push_back(prod/nums[i]);
            }
        }

        return ans;
        
    }
};

// More cllear approach using prefix annd suffix sum

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

    vector<int>prefix(nums.size(),1);   
    vector<int>suffix(nums.size(),1);
    vector<int>ans;

    for(int i=1;i<nums.size(); i++){
        prefix[i] = prefix[i-1]*nums[i-1];
    }

    for(int i=nums.size()-2;i>=0;i--){
        suffix[i] = suffix[i+1]*nums[i+1];
    }
    
    for(int i=0;i<nums.size();i++){
        ans.push_back(prefix[i]*suffix[i]);
    }

    return ans;
    }
};
