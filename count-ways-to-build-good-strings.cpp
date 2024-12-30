//TLE

class Solution {
public:

    map<int, long long > m_;
    int low_, high_, zero_, one_;

    void recc(int x) {

        if (x > high_) {
            m_[x] = 0;
        }
        else {

            if (!m_[x + zero_]) {
                recc(x + zero_);
            }
            if (!m_[x + one_]) {
                recc(x + one_);
            }

            m_[x] = (m_[x + zero_] + m_[x + one_]) % (1000000000 + 7);

            if (low_ <= x && x <= high_) {
                ++m_[x];
            }

            cout << x << endl;

            return;

        }

        return;

    }

    int countGoodStrings(int low, int high, int zero, int one) {

        m_.clear();
        low_ = low;
        high_ = high;
        zero_ = zero;
        one_ = one;

        recc(0);

        return m_[0];

    }
};