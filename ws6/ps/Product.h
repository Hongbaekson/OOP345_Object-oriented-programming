//hongback son / 133181164 / SAA / hbson1@myseneca.ca 


#ifndef _SICT_PRODUCT_H
#define _SICT_PRODUCT_H

#include <iostream>
#include <fstream>
#include "iProduct.h"

namespace sict
{
	class Product : 
		public iProduct
	{
		int m_productNumber;
		double m_cost;
	public:
		Product();
		Product(int productNumber, double cost);
		double price() const ;
		void display(std::ostream& os) const ;
	};

	class TaxableProduct :
		public Product
	{
		double m_taxRate;
		enum class Tax { HST, PST };
	public:
		TaxableProduct(int productNumber, double price, char status);
		double price() const ;
		void display(std::ostream&) const ;
	};

	iProduct* readRecord(std::ifstream& file);
	std::ostream& operator<<(std::ostream& os, const iProduct& p);	
}
#endif 