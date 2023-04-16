#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<long long int> &arr,long long int key,long long int temp){
    long long int sum = 0 ;
    for(long long int i = 0 ; i < arr.size() ; i++){
        if(arr[i] > temp){
            long long int tempSum = arr[i] - temp;
            sum += tempSum;
        }
    }
    if(sum >= key){
        return true;
    }
    return false;
}
int main()
{
    // vector<int> arr{4 ,42 ,40 ,26 ,46};
    
    long long int n,key;
    cin  >> n >> key; 
    vector<long long int> arr(n);

    // sort(arr.begin(),arr.end());
    for(long long int j = 0 ; j < n ; j++){
        cin >> arr[j];
    }
    int maxi = *max_element(arr.begin(),arr.end());

    // for(long long int i = 0 ;  i < n ; i++){
        // maxi = max(arr[i],maxi);
    // }
   
    long long int s = 0 , e = maxi;
    long long int mid = s + (e - s)/2;
    long long int ans = -1;
    while(s <= e){
        if(isPossible(arr,key,mid)){
            ans = mid;
            s = mid + 1;
        }
        else{
            e = mid -1;
        }
        mid = s + (e - s)/2;
    }
    cout << ans << endl ;

}