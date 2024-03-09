class MinStack {
public:
    vector<long long int> st ;
    vector<int> helper ; 
    int stop = -1 ;
    int min = -1 ;
    int htop = -1 ; 

    MinStack() {

    }
    
    void push(long long int val) {

        st.push_back(val) ;

        if( min == -1){
            min = 0 ;
            stop = 0 ;
            helper.push_back(0) ;
            htop = 0 ;
        }

        else{

            if(st[min] >= val){
                stop++ ;
                min = stop ;
                helper.push_back(min) ;
                htop++ ;
            }

            else{
                stop++ ;
            }
        }
        
    }
    
    void pop() {

        if(stop == min){

            if(stop == 0){
                st.pop_back();
                helper.pop_back();
                int stop = -1 ;
                int min = -1 ;
                int htop = -1 ; 
            }
            else{
                st.pop_back();
                stop--;

                helper.pop_back();
                htop-- ;
                min = helper[htop] ;

            }
        }
        else{
            st.pop_back() ;
            stop-- ;

        }
    }
    
    long long int top() {
        return st[stop] ;
    }
    
    
    long long int getMin() {
        return st[min] ;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */