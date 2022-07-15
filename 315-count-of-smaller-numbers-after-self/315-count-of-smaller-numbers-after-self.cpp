class Solution {
public:
    class MergeSort{
      public:
        vector<pair<int,int>> nums;
        vector<pair<int,int>> temp;
        vector<int> ans;
        MergeSort(vector<pair<int,int>> &tmp){
            nums = tmp;
            temp.resize(nums.size());
            ans.resize(nums.size(),0);
            
        }
        
        void _merge(int left,int mid,int right){
            int i=left;
            int j= mid+1;
            int cnt = 0;
            int r = mid+1;
            int k = left;
            while(i <= mid){
                while(r <= right && nums[i].first > nums[r].first){
                    cnt++;
                    r++;
                }
                ans[nums[i].second] += cnt;
                while(j<=right && nums[j]< nums[i]){
                    temp[k++] = nums[j++];
                }
                temp[k++] = nums[i++];
            }
            while(j<=right){
                temp[k++] = nums[j++];
            }
            for(i=left;i<=right;++i){
                nums[i] = temp[i];
            }
        }
        
        void merge_sort(int i,int j){
            if(i>=j) return;
            int mid = i + (j-i)/2;
            merge_sort(i,mid);
            merge_sort(mid+1,j);
            _merge(i,mid,j);
        }
        
        
    };
    vector<int> countSmaller(vector<int>& nums) {
        vector<pair<int,int>> tmp;
        for(int i=0;i<nums.size();++i){
            tmp.push_back({nums[i],i});
        }
        MergeSort* ms = new MergeSort(tmp);
        ms->merge_sort(0,nums.size()-1);
        return ms->ans;
    }
};