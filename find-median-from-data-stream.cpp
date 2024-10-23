class MedianFinder {
public:

    priority_queue<int> lh ; 
    priority_queue<int ,vector<int>, greater<int>> rh ; 

    MedianFinder() {
        
    }
    
    void addNum(int num) {

        if(lh.size() == 0 && rh.size() == 0){
            lh.push(num) ;
            return ;
        }

        int lhTop ;
        int rhTop ;

        if(lh.size() == rh.size()){

            int lhTop = lh.top() ;
            int rhTop = rh.top() ;

            if(num < lhTop || num == lhTop || (num > lhTop && num < rhTop)){
                lh.push(num) ;
            }
            else{

                lh.push(rhTop) ;
                rh.pop() ;

                rh.push(num) ;
            }

        }
        else{

            lhTop = lh.top();

            if(num < lhTop){
                lh.pop() ;
                lh.push(num) ;
                rh.push(lhTop);
            }
            else{

                rh.push(num) ;

            }

        }
        
    }
    
    double findMedian() {

        if(lh.size() == rh.size()){
            return ((lh.top() + rh.top())/2.00) ;
        }
        else{
            return lh.top() ;
        }
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */