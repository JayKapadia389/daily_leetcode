class Solution {
public:

    bool binarySearch(vector<int> v , int target ){

        int l = 0  , r = v.size() - 1 ;

        int mid ;

        while(l <= r){
            mid = (l+r)/2 ;

            if(v[mid] == target){
                return true ;
            }
            else if(v[mid] > target){
                r = mid -1 ;
            }
            else{
                l = mid +1 ;
            }
        }

        return false ;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int m = matrix.size() ; // no of rows
        int n = matrix[0].size() ; // no of cols

        for(int i = 0 ; i < m  ; i++){

            if(target < matrix[i][0]){
                return false ;
            }
            else if(target > matrix[i][n-1]){
                continue ;
            }   
            else{
                return binarySearch(matrix[i] , target) ;
            }

        }

        return false ;


        
    }
};