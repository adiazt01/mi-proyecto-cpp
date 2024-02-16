#include <vector>
#include "product.hpp"

class ProductList
{
public:
    ProductList();
    void addProduct(Product product);
    void removeProduct(int id);
    void updateProduct(int id, Product product);
    Product getProduct(int id);
    std::vector<Product> getProducts();

private:
    std::vector<Product> products;
};
