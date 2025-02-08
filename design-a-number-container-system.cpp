class NumberContainers {
public:

    map<int, int> nums;
    map<int, set<int>> m;

    NumberContainers() {

    }

    void change(int index, int number) {
        if (nums[index] != 0) {
            m[nums[index]].erase(index);
        }

        nums[index] = number;

        m[number].insert(index);
    }

    int find(int number) {

        auto i = m[number].begin();

        if (i == m[number].end()) {
            return -1;
        }
        else {
            return *i;
        }
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */