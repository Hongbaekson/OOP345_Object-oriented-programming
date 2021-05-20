//Honback Son (133181164)

#pragma once
#include <iostream>
#include <iomanip>

namespace sict
{
	template <typename L, typename V>
	class LVPair
	{
	public:
		L m_label;
		V m_value;

		LVPair(){}
		LVPair(const L& label, const V& value)
		{
			m_label = label;
			m_value = value;
		}
		virtual void display(std::ostream& os) const
		{
			os << m_label << " : " << m_value << std::endl;
		}
	};
	template<typename L, typename V>
	std::ostream& operator<<(std::ostream& os, const LVPair<L, V>& pair)
	{
		pair.display(os);
		return os;
	}

	template<typename L, typename V>
	class SummableLVPair : public LVPair<L, V>
	{
		static V s_initial_value;
		static size_t s_field_width;
		
	public:
		SummableLVPair()
		{
		}
		SummableLVPair(const L& label, const V& value) : LVPair<L, V>(label, value)
		{
			if(s_field_width < label.size())
			{
				s_field_width = label.size();
			}
			
		}
		static const V& getInitialValue()
		{
			return s_initial_value;
		}
		V sum(const L& label, const V& sum) const
		{
			return LVPair<L, V>::m_value + sum;
		}
		virtual void display(std::ostream& os) const
		{
			os << std::left << std::setw(s_field_width);
			LVPair<L, V>::display(os);
		}
	};
	template<>
	std::string SummableLVPair<std::string, std::string>::sum(const std::string& label, const std::string& value) const {
		std::string result = value + " " + LVPair<std::string, std::string>::m_value;
		return result;
	}
}