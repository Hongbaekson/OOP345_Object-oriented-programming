//Hongback Son / 133181164 / SAA / Mar 13

#ifndef SICT_DATA_TABLE_H
#define SICT_DATA_TABLE_H



#include <fstream>
#include <vector>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <algorithm>

//this is from w7.cpp
extern int ND;
extern int FW;

namespace sict
{
	template<typename T>
	class DataTable
	{
		std::vector<T> m_Xs;
		std::vector<T> m_Ys;

		T mean() const {
			return accumulate(m_Ys.begin(), m_Ys.end(), static_cast<T>(0)) / m_Ys.size();
		}
		T sigma() const {
			std::vector<T> ysTransform;
			ysTransform.resize(m_Ys.size());
			transform(m_Ys.begin(), m_Ys.end(), ysTransform.begin(), [&](T y) {
				return pow(y - mean(), 2);
			});
			T sum = accumulate(ysTransform.begin(), ysTransform.end(), static_cast<T>(0));
			return sqrt(sum / static_cast<T>(m_Ys.size() - 1));
		}
	public:
		DataTable(std::ifstream& is)
		{
			T temp;
			if (is.is_open()) { // is_open() : if file is normal, true
				while (!is.eof()) { // until end of file
					//2.1 8 // float whitespace float due to sict::DataTable<float> data(dataFile) in w7
					is >> temp;
					if (!is.fail()) // if input is normal, true
						m_Xs.push_back(temp);
					is >> temp; // whitespace will be ignored
					if (!is.fail())
						m_Ys.push_back(temp);
				}
			}
		}

		void displayData(std::ostream& os) const {
			os << "Data Values" << std::endl;
			os << "------------" << std::endl;
			os << std::setw(FW) << std::setprecision(ND) << std::fixed << 'x';
			os << std::setw(FW) << 'y' << std::endl;
			for (size_t i = 0; i < m_Xs.size(); i++) {
				os << std::setw(FW) << m_Xs[i] << std::setw(FW) << m_Ys[i] << std::endl;
			}
			os << std::endl;
		}

		void displayStatistics(std::ostream& os) const {
			os << "Statistics" << std::endl;
			os << "----------" << std::endl;
			os << "  " << std::left << std::setw(10) << "y mean" << "=" 
					<< std::right << std::setw(9) << std::setprecision(ND) << std::fixed << mean() << std::endl;
			os << "  " << std::left << std::setw(10) << "y sigma" << "=" 
				<< std::right << std::setw(9) << std::setprecision(ND) << std::fixed << sigma() << std::endl;
		}

		

		
	};

}

#endif
