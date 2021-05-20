//Hongback son / 133181164 / SAA / hbson1@myseneca.ca
#ifndef _SICT_PRODUCT_H
#define _SICT_PRODUCT_H

#include "iProduct.h"

namespace sict
{
	class Product : public iProduct
	{
		int m_productNumber;
		double m_cost;
	public:
		Product();
		Product(int, double);
		double price() const ;
		void display(std::ostream& os) const ;
	};

	iProduct* readRecord(std::ifstream& file);
	std::ostream& operator<<(std::ostream& os, const iProduct& p);	
}
#endif 