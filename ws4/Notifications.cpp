#include "Notifications.h"

namespace sict
{
	Notifications::Notifications() : m_messages(nullptr), m_max(0), m_size(0)
	{
	}

	Notifications::Notifications(int max)
	{
		if(max < 0)
		{
			*this = Notifications();
			return;
		}
		m_max = max;
		m_messages = new const Message*[m_max];
		m_size = 0;
	}

	Notifications::Notifications(const Notifications& rhs)
	{
		*this = rhs;
	}

	Notifications& Notifications::operator=(const Notifications& rhs)
	{
		if (this != &rhs) {
			for (size_t i = 0; i < m_size; i++)
			{
				delete[] m_messages[i];
				m_messages[i] = nullptr;
			}
			delete[] m_messages;
			m_size = rhs.m_size;
			for (size_t i = 0; i < m_size; i++) {
				m_messages[i] = rhs.m_messages[i];
			}
		}
		return *this;
	}

	Notifications::Notifications(Notifications&& rhs)
	{
		*this = std::move(rhs);
	}

	Notifications&& Notifications::operator=(Notifications&& rhs)
	{
		if (this != &rhs) {
			for (size_t i = 0; i < m_size; i++)
			{
				delete[] m_messages[i];
				m_messages[i] = nullptr;
			}
			delete[] m_messages;
			m_size = rhs.m_size;
			m_messages = rhs.m_messages;
			rhs.m_messages = nullptr;
			rhs.m_size = 0;
		}
		return move(*this);
	}

	Notifications::~Notifications()
	{
		for (size_t i = 0; i < m_size; i++)
		{
			delete[] m_messages[i];
			m_messages[i] = nullptr;
		}
		delete[] m_messages;
		m_messages = nullptr;
	}

	Notifications& Notifications::operator+=(const Message& msg)
	{
		if (!msg.empty())
		{
			if (m_size < m_max)
			{
				m_messages[m_size++] = &msg;
			}
		}
		return *this;
	}

	Notifications& Notifications::operator-=(const Message& msg)
	{
		if (!msg.empty())
		{
			for(size_t i = 0; i < m_size; i++)
			{
				if(m_messages[i] == &msg)
				{
					m_messages[i] = nullptr;
					for (size_t j = i; j < m_size - 1; j++)
						m_messages[j] = m_messages[j + 1];

					m_messages[m_size - 1] = nullptr;
				}
			}
			m_size--;
		}
		return *this;
	}

	void Notifications::display(std::ostream& os) const
	{
		for (size_t i = 0; i < m_size; i++) {
			m_messages[i]->display(os);
		}
	}

	size_t Notifications::size()
	{
		return m_size;
	}

	std::ostream& operator<<(std::ostream& os, Notifications& notifications)
	{
		notifications.display(os);
		return os;
	}
}
