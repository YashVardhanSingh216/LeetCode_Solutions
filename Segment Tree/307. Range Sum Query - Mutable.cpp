// 307. Range Sum Query - Mutable

void BuildSegTree(int i, int l , int r, vector<int>&nums, vector<int>&segTree){

    if(l == r){
        segTree[i] = nums[l];
        return;
    }
    int mid = l - (l - r)/2;
    BuildSegTree(2*i+1, l , mid, nums, segTree);
    BuildSegTree(2*i+2, mid+1 , r, nums, segTree);

    segTree[i] = segTree[2*i+1] + segTree[2*i+2];
}

void segUpdate(int index, int val, int i, int l, int r, vector<int>&segTree){

    if(l == r){
        segTree[i] = val;
        return;
    }

    int mid = l - (l - r)/2;

    if(index <= mid){
        segUpdate(index, val, 2*i+1, l, mid, segTree);
    }
    else{
        segUpdate(index, val, 2*i+2, mid+1, r, segTree);
    }
    segTree[i] = segTree[2*i+1] + segTree[2*i+2];
}

int rangeSum(int left, int right, int i, int l, int r, vector<int>&segTree){

    if(l > right || r < left) return 0;

    if(l >= left && r <= right){
        return segTree[i];
    }

    int mid = l - (l - r)/2;
    return rangeSum(left, right, 2*i+1, l, mid,segTree)
    + rangeSum(left, right, 2*i+2, mid+1, r,segTree);

}
class NumArray {
public:

    vector<int>segTree;
    int n;
    NumArray(vector<int>& nums) {
        
        n = nums.size();
        segTree.resize(4*n,0);

        BuildSegTree(0, 0 , n-1, nums, segTree);
    }
    
    void update(int index, int val) {
        segUpdate(index, val, 0, 0, n-1, segTree);
    }
    
    int sumRange(int left, int right) {
        
        return rangeSum(left, right, 0, 0, n-1,segTree);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
