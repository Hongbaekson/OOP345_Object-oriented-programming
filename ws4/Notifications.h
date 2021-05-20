#pragma once
#include <iostream>
#include <string>
#include "Message.h"
#include "MessagePack.h"

namespace sict {

	class Notifications {
		const Message** m_messages;
		size_t m_max;
		size_t m_size;
	public:
		Notifications();
		Notifications(int max);
		Notifications(const Notifications& rhs);
		Notifications& operator=(const Notifications& rhs);
		Notifications(Notifications&& rhs);
		Notifications&& operator=(Notifications&& rhs);
		~Notifications();
		Notifications& operator+=(const Message& msg);
		Notifications& operator-=(const Message& msg);
		void display(std::ostream& os) const;
		size_t size();
	};
	std::ostream& operator<<(std::ostream& os, Notifications& notifications);
	
}