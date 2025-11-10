/*
In a Cyclic array arr[0] in neighbour of arr[n-1] and arr[n-1] is neighbour of arr[0].

IN MOST CASES WE NEED TO CONVERT IT TO A NORMAL ARRAY
*/

//OPTS-1 cyclic_arr=arr+arr

vector<int> make_cyclic(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans=nums;
    for (int i = 0; i <  n; i++)
        ans.push_back(nums[i]);
    return cyclic_arr;
}

/*
OPTS-2 Break the cycle at an index
usefull when we need to partiong the cyclic array into subarrays,
The idea is to find an index that will always be either a start point or end point of a its subarray

for example:https://leetcode.com/problems/maximize-cyclic-partition-score/description/

here the max_ind which has the max value) will always be either the start or end of its subarray thus we can break the cycle at max_ind
i.e 
shift the array till max_ind is at the start and solve the problem as you will for a normal array
*/

vector<int> get_shift(vector<int>&nums,int shift){
    vector<int> ans;
    for(int i=shift;i<n;i++)
        ans.push_back(nums[i]);
    for(int i=0;i<shift;i++)
        ans.push_back(nums[i]);
    return ans;
}

vector<int> nums1=get_shift(nums,mx_ind);  //mx_ind is at start of its partition
vector<int> nums2=get_shift(nums,mx_ind+1);//mx_ind is at end of its partition so mx_ind+1 is at start of its partion
ll ans1=get_ans(nums1,k);
ll ans2=get_ans(nums2,k);
return max(ans1,ans2);


/*
This removes a factor of n from the TC as if we dont break the cycle our tc will be n*get_ans() as need to call answer for each shift
Now our TC: 2*get_ans() by finding the optimal shifts.
*/