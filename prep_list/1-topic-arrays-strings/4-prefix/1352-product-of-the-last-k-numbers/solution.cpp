// https://leetcode.com/problems/product-of-the-last-k-numbers/description/

class ProductOfNumbers {
public:
    ProductOfNumbers() {}
    
    void add(int num) {
        if (num == 0) {
            product = vector<int>();
        }
        else {
            int x = (product.size() > 0) ? product.back() * num : num;
            product.push_back(x);
        }
    }
    
    int getProduct(int k) {
        int n = product.size();
        if (n >= k) { 
            return (n - k - 1 >= 0) ? product.back() / product[n - k - 1] : product.back();
        }
        return 0;
    }

private:
    vector<int> product;
};
