class Solution {
    class MergeSort {

    public:
	    vector<int> arr;
	    vector<int> temp;
        int ans;
	MergeSort(vector<int> tmp) {
		arr = tmp;
		temp.resize(arr.size());
        ans = 0;
		
	}
	void printArr() {
		for (auto &x : arr) {
			cout << x << " ";
		}
		cout << "\n";
	}
	void merge(int left, int mid, int right) {
        int i = left;
        int j= mid+1;
        int tempptr = mid+1;
        int k = left;
        int cnt = 0;
		while(i <= mid){
            while(tempptr <= right && (arr[i] > (long)2*arr[tempptr])){
                cnt++;
                tempptr++;
            }
            ans += cnt;
            
            while(j<=right && arr[j] <= arr[i]){
                temp[k++] = arr[j++];
            }
            temp[k++] = arr[i++];
           
        }
        while(j<=right){
                temp[k++] = arr[j++];
        }
        for(int i=left;i<=right;++i){
            arr[i] = temp[i];
        }
	}
	void merge_sort(int i, int j) {
		if (i < j) {
			int mid = (i+j)/2;
            
			merge_sort(i, mid);
			merge_sort(mid + 1, j);
			merge(i, mid, j);
           
		}
        
	}
};
public:
    int reversePairs(vector<int>& nums) {
        MergeSort* ms = new MergeSort(nums);
        ms->merge_sort(0,nums.size()-1);
        return ms->ans;
       
    }
};
