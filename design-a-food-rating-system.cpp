class FoodRatings {
private:
struct cmp{
    bool operator()(pair<int, string> p1, pair<int, string> p2) const {
        if(p1.first != p2.first){
            return p1.first > p2.first;
        }
        return p1.second < p2.second;
    }
};

unordered_map<string, pair<string, int>> food_to_cuisine;
unordered_map<string, set<pair<int, string>, cmp>> cuisine_to_set;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        
        for(int i = 0; i < n; ++i){
            string food = foods[i];
            string cuisine = cuisines[i];
            int rating = ratings[i];

            food_to_cuisine[food] = {cuisine, rating};
            cuisine_to_set[cuisine].insert({rating, food});
        }
    }
    
    void changeRating(string food, int newRating) {
        pair p = food_to_cuisine[food];

        string cuisine = p.first;
        int rating = p.second;

        food_to_cuisine[food] = {cuisine, newRating};
        cuisine_to_set[cuisine].erase({rating, food});
        cuisine_to_set[cuisine].insert({newRating, food});
    }
    
    string highestRated(string cuisine) {
        return (cuisine_to_set[cuisine].begin())->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */