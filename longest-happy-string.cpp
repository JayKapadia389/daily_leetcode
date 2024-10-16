class Solution {
public:
    string longestDiverseString(int a, int b, int c) {

        priority_queue<pair<int, char>> q ;
        q.push({a , 'a'});
        q.push({b , 'b'});
        q.push({c , 'c'});

        string s = "" ;
        char alpha;

        while(true){

            pair<int , char> fp = q.top() ;
            q.pop() ;

            if(fp.first == 0){
                return s ;
            }

            else if(s.length() >= 2 && fp.second == s[s.length() - 1] && fp.second == s[s.length() - 2]){

                pair<int, char> sp = q.top() ;
                q.pop() ;

                if(sp.first == 0){
                    return s ;
                }
                else{
                    alpha = sp.second ;
                    q.push(fp);
                    sp.first-- ;
                    q.push(sp) ;
                }

            }
            else{

                alpha = fp.second ;
                fp.first-- ;
                q.push(fp); 

            }

            s+=alpha ;
            cout << s << endl;

        }

    }
};