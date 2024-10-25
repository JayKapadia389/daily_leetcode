class TrieNode {

    public : 

    vector
    <pair<string , TrieNode *>> v ;
    bool eow ;

};

class Trie{

    public:

    TrieNode * root ;

    Trie(){
        root = new TrieNode() ;
    }

    TrieNode * exists(TrieNode * curr , string x){

        for(auto i : (curr->v)){

            if(i.first == x ){
                return i.second ;
            }

        }

        return NULL ;

    }

    string getStr(string folder , int &idx){

        int c = 0 ;
        int i = idx +1; 
        int j = idx +1;

        while(folder[i] != '/' && i != folder.length()){

                ++c ;
                ++i ;

        }

        idx = i ;

        return folder.substr(j,c) ;

    }

    void insert(string folder){

        TrieNode * curr = root ;
        int idx = 0 ;

        string x = getStr(folder , idx) ;

        while(true){

            TrieNode * next = exists(curr , x) ;

            if(next == NULL){
                next = new TrieNode() ;
                (curr->v).push_back({x , next}) ;
            }

            if(idx == folder.length()){
                next->eow = true ;
                return ;
            }
            else{

                if(next->eow == true){
                    return ;
                }
                curr = next ;
                x = getStr(folder , idx);
            }

        }

    }

    void dfscore(vector<string> &ans , string pref , TrieNode * curr){

        if(curr->eow){
            ans.push_back(pref) ;
            return ;
        }

        for(auto i : (curr->v)){
            dfscore(ans , pref+"/"+i.first , i.second) ;
        }

    }

    void dfs(vector<string> &ans){

        for(auto i : (root->v)){
            dfscore(ans , "/"+i.first , i.second ) ;
        }

    }

};

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {

        Trie myTrie ;

        for(auto i : folder){
            myTrie.insert(i) ;
        }

        vector<string> ans ;

        myTrie.dfs(ans) ;

        return ans ;
        
    }
};