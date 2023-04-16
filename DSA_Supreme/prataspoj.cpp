#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool isPossible(vector<int> arr,int ans,int noOfParathas){
    int currP = 0;
    for(int i = 0 ; i < arr.size() ; i++){
        int R = arr[i] , j = 1;
        int timeTaken = 0;
        while(true){
            if(timeTaken + j * R <= ans)
                {
                    ++currP;
                    timeTaken += j * R; 
                    ++j;
                } 
                else
                break;
        }
    }
    if(currP >= noOfParathas)
    return true;
    return false;
}

int main(){
    int t;
    cin >> t;
    while(t--){

        int parathas,cooks;
        cin >> parathas >> cooks;

        vector<int> arr(cooks);

        for(int i = 0 ;  i < arr.size() ; i++){
            cin >> arr[i];
        }

        int laziestCook = *max_element(arr.begin(),arr.end());
        
        int laziestCookTime = laziestCook*(parathas*(parathas + 1))/2;
        int start = 0 , end = laziestCookTime ;
        int ans = -1;
        while(start <= end){
            int mid = start + (end - start) /2;
            if(isPossible(arr,mid,parathas)){
                ans = mid;
                end = mid - 1;
            }
            else{
                start = start + 1;
            }
        }
        cout << ans << endl;
    }
}