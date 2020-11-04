
long long merge(long long* arr, int left, int mid, int right) {
    int i=left,j=mid,k=0;

	int temp[right-left+1];
	long long count = 0;
	while(i<mid && j<=right){
		if(arr[i] <= arr[j]){
			temp[k++] = arr[i++];
		}else{
			temp[k++] = arr[j++];
			count += mid - i;
		}
	}
	while(i<mid){
		temp[k++] = arr[i++];
	}
	while(j<=right){
		temp[k++] = arr[j++];
	}

	for(int i=left,k=0;i<=right;i++,k++){
		arr[i] = temp[k];
	}
	return count;

}



long long help1(long long* arr, int start, int end) {
    long long ans {0};
    if(start < end) {
        int mid = (start+end)/2;
        long long leftSubPartAns {help1(arr, start, mid)};
        long long rightSubPartAns {help1(arr,mid+1,end)};
        long long mergeAns {merge(arr,start,mid+1,end)};
        return mergeAns + leftSubPartAns + rightSubPartAns;
    }
    return ans;
}

long long getInversions(long long *arr, int n)
{
    //Write your code here
    
        return help1(arr,0,n-1);

}