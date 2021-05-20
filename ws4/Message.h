//hongback son (133181164)
#pragma once

#include <string>

using namespace std;

namespace sict
{
	const char DELIMETER = ' ';

	class Message
	{
		string m_user;
		string m_reply;
		string m_tweet;
	public:
		Message();
		Message(const std::string& str);
		bool empty() const;
		void display(std::ostream& os) const;
		~Message();
	};
} // sict
