//Hongback Son / 1331281164 / SAA / Mar 16


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

		T median() const {
			std::vector<T> tempVector = m_Ys;
			sort(tempVector.begin(), tempVector.end());
			return tempVector.at(tempVector.size() / 2);
		}

		T slope() const {
			T totalOfXX = inner_product(m_Xs.begin(), m_Xs.end(), m_Xs.begin(), static_cast<T>(0));
			T totalOfXY = inner_product(m_Xs.begin(), m_Xs.end(), m_Ys.begin(), static_cast<T>(0));
			T totalOfX = accumulate(m_Xs.begin(), m_Xs.end(), static_cast<T>(0));
			T totalOfY = accumulate(m_Ys.begin(), m_Ys.end(), static_cast<T>(0));
			return (m_Ys.size() * totalOfXY - totalOfX * totalOfY) / (m_Ys.size() * totalOfXX - pow(totalOfX, 2));
		}

		T intercept() const {
			T totalOfX = accumulate(m_Xs.begin(), m_Xs.end(), static_cast<T>(0));
			T totalOfY = accumulate(m_Ys.begin(), m_Ys.end(), static_cast<T>(0));
			return (totalOfY - slope() * totalOfX) / m_Ys.size();
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
			os << "  " << std::left << std::setw(10) << "y median" << "="
				<< std::right << std::setw(9) << std::setprecision(ND) << std::fixed << median() << std::endl;
			os << "  " << std::left << std::setw(10) << "slope" << "="
				<< std::right << std::setw(9) << std::setprecision(ND) << std::fixed << slope() << std::endl;
			os << "  " << std::left << std::setw(10) << "intercept" << "="
				<< std::right << std::setw(9) << std::setprecision(ND) << std::fixed << intercept() << std::endl;
		}

	};

}

#endif