#pragma once
#include <iostream>
#include <string>
#include "Message.h"

namespace sict {

	class MessagePack {
		Message** m_messages;
		size_t m_size;
	
	public:
		MessagePack();
		MessagePack(Message** messages, int size);
		MessagePack(const MessagePack& rhs);
		MessagePack& operator=(const MessagePack& rhs);
		MessagePack(MessagePack&& rhs);
		MessagePack&& operator=(MessagePack&& rhs);
		~MessagePack();
		void display(std::ostream&os)const;
		size_t size()const;
	};
	std::ostream& operator<<(std::ostream& os, MessagePack& messagePack);

}