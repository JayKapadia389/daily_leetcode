class MovieRentingSystem {
map<int, set<pair<int, int>>> movie_to_price_shop; // mostly doesn't need comp
map<pair<int,int> , int> shop_movie_to_price;
set<vector<int>> report_set; // mostly doesn't need comp

public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(auto entry : entries){
            int s = entry[0];
            int m = entry[1];
            int p = entry[2];

            movie_to_price_shop[m].insert({p,s});
            shop_movie_to_price[{s,m}] = p;
        }
    }
    
    vector<int> search(int movie) {
        auto it = movie_to_price_shop[movie].begin();
        vector<int> temp;
        int size = movie_to_price_shop[movie].size();
        for(int i = 0; i < 5 && i < size; ++i){
            temp.push_back(std::next(it, i)->second);
        }
        return temp;
    }
    
    void rent(int shop, int movie) {
        int price = shop_movie_to_price[{shop, movie}];
        movie_to_price_shop[movie].erase({price, shop});
        report_set.insert({price, shop, movie});
    }
    
    void drop(int shop, int movie) {
        int price = shop_movie_to_price[{shop, movie}];
        movie_to_price_shop[movie].insert({price, shop});
        report_set.erase({price, shop, movie});
    }
    
    vector<vector<int>> report() {
        auto it = report_set.begin();
        vector<vector<int>> temp;
        int size = report_set.size();
        for(int i = 0; i < 5 && i < size ; ++i){
            temp.push_back({ 
                (*std::next(it, i))[1] , 
                (*std::next(it, i))[2] 
            });
        }
        return temp;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */