#include <iostream>

using namespace std ;

class Node{

  public :

  Node* children[26];
  bool endOfWord ;  

  Node(){
    for(int i = 0 ; i < 26 ; i++){
        children[i] = NULL ;
    }
    endOfWord = false ;
  }
};

class Trie{

    public :

    Node * root ;

    Trie(){
        root = new Node() ;
    }

    void insert(string str){

      Node * temp = root ;
      int idx ;

      for(int i = 0 ; i < str.length() ; i++){

        idx = str[i] - 'a';

        if((temp->children)[idx] == NULL){
          (temp->children)[idx] = new Node() ;
        }

        if(i == (str.length() - 1)){
          (temp->children)[idx]->endOfWord = true ;
        }

        temp = (temp->children)[idx] ;

      }

    }

    bool exist(string str){

      Node * temp = root ;
      int idx ;

      for(int i = 0 ; i < str.length() ; i++){

        idx = str[i] - 'a' ;

        if((temp->children)[idx] == NULL){
          return false ;
        }

        if(i == (str.length() - 1)){
          if((temp->children)[idx]->endOfWord) {
            return true ;
          }
          else{
            return false ;
          }
        }

        temp = (temp->children)[idx] ;

      }

    }
};

int main(){

Trie myTrie ;

myTrie.insert("the") ;
cout << myTrie.exist("the") ;

}


