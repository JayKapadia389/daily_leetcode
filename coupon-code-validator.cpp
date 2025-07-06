class Solution {
public:

    bool isCodeValid(string& code){

        if(code == ""){
            return false ;
        }
        
        for(auto ch : code){
            
            if(!((ch >= 65 && ch <= 90) ||
                  (ch >= 97 && ch <= 122) ||
                  (ch >= 48 && ch <= 57)||
                   (ch == '_'))){
                return false ; 
            }
            
        }
        
        return true ; 
        
    }
    
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {

        vector<string> electronics; 
        vector<string> grocery; 
        vector<string> pharmacy; 
        vector<string> restaurant; 

        for(int i = 0 ; i < code.size() ; ++i){
            if(!isActive[i]){
                continue ; 
            }
            if(!isCodeValid(code[i])){
                continue ; 
            }

            if(businessLine[i] == "electronics"){
                electronics.push_back(code[i]) ; 
            }
            if(businessLine[i] == "grocery"){
                grocery.push_back(code[i]) ; 
            }
            if(businessLine[i] == "pharmacy"){
                pharmacy.push_back(code[i]) ; 
            }
            if(businessLine[i] == "restaurant"){
                restaurant.push_back(code[i]) ; 
            }
        }

        sort(electronics.begin() , electronics.end()) ; 
        sort(grocery.begin() , grocery.end()) ; 
        sort(pharmacy.begin() , pharmacy.end()) ; 
        sort(restaurant.begin() , restaurant.end()) ; 
        
        vector<string> ans ;

        for(auto i : electronics){
            ans.push_back(i) ; 
        }
        for(auto i : grocery){
            ans.push_back(i) ; 
        }
        for(auto i : pharmacy){
            ans.push_back(i) ; 
        }
        for(auto i : restaurant){
            ans.push_back(i) ; 
        }

        return ans ; 
        
    }
};