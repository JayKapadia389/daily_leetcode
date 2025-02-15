class ProductOfNumbers {
public:
    vector<int> products;
    int lastZeroIndex;

    ProductOfNumbers() {
        products.push_back(1);
        lastZeroIndex = -1;
    }

    void add(int num) {
        if (num == 0) {
            products.clear();
            products.push_back(1);
            lastZeroIndex = products.size() - 1;
        }
        else {
            products.push_back(products.back() * num);
        }
    }

    int getProduct(int k) {
        int n = products.size();
        if (n - k - 1 < lastZeroIndex) {
            return 0;
        }
        return products.back() / products[n - k - 1];
    }
};
