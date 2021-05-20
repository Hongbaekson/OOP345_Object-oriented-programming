// Workshop 8 - Smart Pointers
// Utilities.cpp
// Chris Szalwinski from Cornel Barna
// 2019/03/17
//  Hongback Son / 133181164 / SAA /Mar 19 / hbson1@myseneca.ca

#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sict {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using raw pointers
		for (size_t i = 0; i < desc.size(); i++) {
			for (size_t j = 0; j < price.size(); j++) {
				if (desc[i].code == price[j].code) {
					sict::Product* product = new sict::Product(desc[i].desc, price[j].price);
					product->validate();
					priceList += std::move(product);
					delete product;
				}
			}
		}
		return priceList;
	}
}