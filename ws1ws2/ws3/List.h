#pragma once

namespace sict
{
	template<typename T, size_t N>
	class List
	{
		T m_data[N];
		size_t m_size = 0;
	public:
		size_t size() const
		{
			return m_size;
		}
		const T&  operator[] (size_t i) const
		{
			return m_data[i];
		}
		void operator +=(const T& t)
		{
			if(m_size <= N)
			{
				m_data[m_size++] = t;
			}
		}
	};

	template<typename T, typename L, typename V, size_t N>
	class LVList : public List<T, N>
	{
	public:
		V accumulate(const L& label) const
		{
			List<T, N>& temp = (List<T, N>&)*this;
			V result = SummableLVPair<L, V>::getInitialValue();
			for(size_t i = 0; i < temp.size(); i++)
			{
				if (label == temp[i].m_label)
				{
					result = temp[i].sum(label, result);
				}
			}
			return result;
		}
	};
}