#include "MessagePack.h"

namespace sict
{
	MessagePack::MessagePack() : m_messages(nullptr), m_size(0)
	{

	}

	MessagePack::MessagePack(Message** messages, int size)
	{
		if (size < 0 || messages == nullptr)
		{
			*this = MessagePack();
			return;
		}
		m_size = 0;
		m_messages = new Message*[size];
		for(int i = 0; i < size; i++)
		{
			if (!messages[i]->empty())
			{
				m_messages[m_size++] = messages[i];
			}
		}
	}

	MessagePack::MessagePack(const MessagePack& rhs)
	{
		*this = rhs;
	}

	MessagePack& MessagePack::operator=(const MessagePack& rhs)
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

	MessagePack::MessagePack(MessagePack&& rhs)
	{
		*this = move(rhs);
	}

	MessagePack&& MessagePack::operator=(MessagePack&& rhs)
	{
		if (this != &rhs) {
			for(size_t i = 0; i < m_size; i++)
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

	MessagePack::~MessagePack()
	{
		for (size_t i = 0; i < m_size; i++)
		{
			delete[] m_messages[i];
			m_messages[i] = nullptr;
		}
		delete[] m_messages;
		m_messages = nullptr;
	}

	void MessagePack::display(std::ostream& os) const
	{
		for (size_t i = 0; i < m_size; i++) {
			m_messages[i]->display(os);
		}
	}

	size_t MessagePack::size() const
	{
		return m_size;
	}

	std::ostream& operator<<(std::ostream& os, MessagePack& messagePack)
	{
		messagePack.display(os);
		return os;
	}
}
