//hongback son (133181164)

#include <iostream>
#include "Message.h"

namespace sict
{
	Message::Message()
	{
		m_user.clear();
		m_reply.clear();
		m_tweet.clear();
	}

	Message::Message(const std::string& str)
	{
		//jim Workshop 4 is cool 
		if (!str.empty())
		{
			size_t startPosition = 0;
			size_t next_space = str.find(DELIMETER);
			if (next_space == string::npos)
			{
				*this = Message();
				return;
			}
			m_user = str.substr(startPosition, next_space);
			startPosition = next_space + 1;
			if(str.at(startPosition) == '@')
			{
				startPosition++;
				next_space = str.find(DELIMETER, startPosition);
				m_reply = str.substr(startPosition, next_space - startPosition);
				startPosition = next_space + 1;
			}
			m_tweet = str.substr(startPosition);
		}
	}

	  bool Message::empty() const
	  {
		  return m_user.empty();
	  }

	  void Message::display(std::ostream& os) const
	  {
		  if (!empty())
		  {
			  os << ">User  : " << m_user << std::endl;
			  if (!m_reply.empty())
				  os << " Reply : " << m_reply << std::endl;
			  os << " Tweet : " << m_tweet << std::endl;
		  }
	  }
  
	  Message::~Message()
	  {
	  }
}