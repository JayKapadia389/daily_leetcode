class Solution {
public:
    int distinctPoints(string s, int k) {
        map<pair<int,int> , int> m;
        pair p = {0,0};

        for(int i = 0; i < k; ++i){
            if(s[i] == 'U'){
        		p.second += 1;
        	}
        	else if(s[i] == 'D'){
        		p.second -= 1;
        	}
        	else if(s[i] == 'L'){
        		p.first -= 1;
        	}
        	else{
        	    p.first += 1;
        	}
        }

        ++m[p];

        for(int i = k; i < s.length(); ++i){
            if(s[i-k] == 'U'){
        		p.second -= 1;
        	}
        	else if(s[i-k] == 'D'){
        		p.second += 1;
        	}
        	else if(s[i-k] == 'L'){
        		p.first += 1;
        	}
        	else{
        	    p.first -= 1;
        	}

            if(s[i] == 'U'){
        		p.second += 1;
        	}
        	else if(s[i] == 'D'){
        		p.second -= 1;
        	}
        	else if(s[i] == 'L'){
        		p.first -= 1;
        	}
        	else{
        	    p.first += 1;
        	}

            ++m[p];
        }

        int ans = m.size();

        return ans;
    }
};