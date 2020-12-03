
// Name   Hongback Son           Date  19/09/22               student number 133181164
/////////////////////////////////////////////////////////////////

#include "Good.h"
#include "Date.h"
#ifndef AID_PERISHABLE_H
#define AID_PERISHABLE_H
#include <iostream>
#include <fstream>

namespace aid {
	class Perishable : public Good {
	private:
		Date expiry_date;
	public:
		Perishable();
		std::fstream& store(std::fstream& file, bool newLine = true) const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear) const;
		std::istream& read(std::istream& is);
		const Date& expiry() const;
	};
}

#endif // !PERISHABLE_H
