
class Solution
{
    public:
    void merge(int arr[], int low, int mid, int high)
    {
         // Your code here
         // 1st = [0...mid]
         // 2nd = [mid+1..]
         
         int left = low;
         int right = mid+1;
         
         // to store sorted array
         vector<int> temp;
         
         while(left <= mid && right <= high){
             if(arr[left] <= arr[right])
                temp.push_back(arr[left++]);
             else
                temp.push_back(arr[right++]);
         }
         
         while(left <= mid)
            temp.push_back(arr[left++]);
         while(right <= high)
            temp.push_back(arr[right++]);
            
        for(int i=low;i<=high;i++)        
            arr[i] = temp[i-low];
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        if(l == r)
          return;
        int mid = (l+r)/2;
        
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
};


