class Solution {
public:

    int findCommonPrefix(string& a , string& b){
        int c = 0 ;
        int len = min(a.length() , b.length()) ; 
    
        for(int i = 0 ; i < len ; ++i){
            if(a[i] != b[i]){
                cout << c ;  
                return c ; 
            }
            else{
                ++c ;  
            }
        }
        cout << c;
        return c;  
    }

    
    vector<int> longestCommonPrefix(vector<string>& words) {

        vector<int> first ;
        int n = words.size() ; 
        if(n == 1){
            return {0} ; 
        }
        else if(n == 2){
            return {0,0} ; 
        }
        vector<int> second(n , 0) ;
        vector<int> third(n , 0) ;
        priority_queue<int> heap ; 
        map<int,int> m; 
        
        for(int i = 0 ; i < n-1 ; ++i){
            int k = findCommonPrefix(words[i] , words[i+1]) ; 

            ++m[k] ; 
            heap.push(k) ; 
            
            first.push_back(k) ;
        }

        for(int i = 0 ; i < n-2 ; ++i){
            second[i+1] = findCommonPrefix(words[i] , words[i+2]) ; 
        }

        vector<int> tt;
        for(int i = 0 ; i < 3 ; ++i){
            tt.push_back(heap.top());
            heap.pop() ; 
        }
        
        for(int i = 0 ; i < n ; ++i){
            int f = 0 ; 
            int s = 0 ; 
        
            if(i != 0){
                f = first[i-1] ; 
            }
            if(i != n-1){
                s = first[i] ; 
            }
        
            int x = second[i];

            --m[f] ; 
            --m[s] ; 
        
            int mx = 0 ; 
        
            if(m[tt[0]] != 0){
                mx = max(x , tt[0]) ; 
            }
            if(m[tt[1]] != 0){
                mx = max(mx , tt[1]) ; 
            }
            if(m[tt[2]] != 0){
                mx = max(mx , tt[2]) ; 
            }
        
            third[i] = mx ; 
        
            ++m[f] ; 
            ++m[s] ; 
        }
        
        return third ; 
        
    }
};