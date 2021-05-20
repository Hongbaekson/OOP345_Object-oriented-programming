//hongback son / 133181164 / SAA / hbson1@myseneca.ca 


#ifndef _SICT_IPRODUCT_H
#define _SICT_IPRODUCT_H

#include <iostream>
#include <fstream>

namespace sict
{
	class iProduct
	{
	public:
		virtual double price() const = 0;
		virtual void display(std::ostream& os) const = 0;
	};

	iProduct* readRecord(std::ifstream& file);
	std::ostream& operator<<(std::ostream& os, const iProduct& p);
}

#endif 

