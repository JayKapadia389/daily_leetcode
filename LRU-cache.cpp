class Node{

    public :

    int key , value ;
    Node * prev ;
    Node * next ;

    Node(int key , int value){
        this->key = key ;
        this->value = value ; 
        prev = NULL ;
        next = NULL ;
    }
};

class LRUCache {
public:

    int capacity ;
    int sz ;
    map<int , Node * > m ;
    Node * left ;
    Node * right ;
    Node * temp  ;

    void remove(Node * temp){
        temp->prev->next = temp->next ;
        temp->next->prev = temp->prev ;

        return ;

    }

    void insert(Node * temp){

        temp->prev = right->prev;
        temp->next = right;

        right->prev->next = temp;
        right->prev = temp;

        return ;


    }

    LRUCache(int capacity) {

        this->capacity = capacity ;
        sz = 0 ;
        left = new Node(0 , 0) ;
        right = new Node(0 , 0) ;

        left->next = right ;
        right->prev = left ;
        
    }
    
    int get(int key) {

        if(m.find(key) == m.end()){
            return -1 ;
        }
        else{

            temp = m[key] ;

            remove(temp) ;
            insert(temp) ;

            return temp->value ;

        }
        
    }
    
    void put(int key, int value) {

        if(m.find(key) != m.end()){

             temp = m[key] ;

             temp->value = value ;

             remove(temp) ;
             insert(temp) ;

        }

        else{

            temp = new Node(key , value) ;

            insert(temp) ;
            m[key] = temp ;

            if(sz == capacity){

                temp = left->next;
                m.erase(temp->key) ;
                remove(temp) ;
                delete(temp) ;

            }
            else{
                sz++ ;
            }

        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */