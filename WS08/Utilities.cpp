/*
 * Purpose: Workshop 8
 * Name Of Student: Hien Dao The Nguyen
 * Student Number: 103 152 195
 * Email: hnguyen110@myseneca.ca
 * Date: Mar/26/2021
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 */

// Workshop 8 - Smart Pointers
// 2019/11 - Cornel


#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
    List<Product> mergeRaw(const List<Description> &desc, const List<Price> &price) {
        List<Product> priceList;
        // TODO: Add your code here to build a list of products
        //         using raw pointers
        for (auto _desc = 0u; _desc < desc.size(); ++_desc)
            for (auto _price = 0u; _price < price.size(); ++_price)
                if (desc[_desc].code == price[_price].code) {
                    auto *product = new Product(desc[_desc].desc, price[_price].price);
                    product->validate();
                    priceList.operator+=(*product);
                    delete product;
                }
        return priceList;
    }

    List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price) {
        List<Product> priceList;
        // TODO: Add your code here to build a list of products
        //         using smart pointers
        for (auto _desc = 0u; _desc < desc.size(); ++_desc)
            for (auto _price = 0u; _price < price.size(); ++_price)
                if (desc[_desc].code == price[_price].code) {
                    std::unique_ptr<Product> product(new Product(desc[_desc].desc, price[_price].price));
                    product->validate();
                    priceList.operator+=(*product);
                }
        return priceList;
    }
}