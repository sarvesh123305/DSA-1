#include<bits/stdc++.h>
using namespace std;
    //Leetcode 2661 First Completely Painted Row or Column

    //Approach : 
    
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
     
        int n = mat.size() ;
        int m = mat[0].size() ;
        vector<int> rows(n,0);
        vector<int> cols(m,0);
        
        vector<pair<int,int>> position(m*n + 1);
        for(int i = 0 ; i < n ; ++i){
            for(int j = 0 ; j < m ;++j){
                position[mat[i][j]] = {i,j};
            }
        }
        for(int i = 0 ; i < m*n; ++i){
            int element = arr[i];
            int x = position[element].first ;
            int y = position[element].second ;
            
            if(++rows[x] == m || ++cols[y] == n){
                return i;
            }
            
        }
        return -1;

            
    }

    int main(){
        vector<int> arr = {1,3,4,2};
        vector<vector<int>> mat = {{1,4},{2,3}};
        cout << firstCompleteIndex(arr,mat) << endl ; 
        return 0;
    }