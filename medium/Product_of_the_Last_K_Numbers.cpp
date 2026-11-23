/*
LC 1352 - Product of the Last K Numbers
Time: O(N), Space: O(N)
*/

class ProductOfNumbers {
public:
    vector<int> v;
    ProductOfNumbers() {}

    void add(int num) { v.push_back(num); }

    int getProduct(int k) {
        int ret = 1;
        for (int i = v.size() - 1; k > 0;) {
            ret = ret * v[i];
            i--;
            k--;
        }
        return ret;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */