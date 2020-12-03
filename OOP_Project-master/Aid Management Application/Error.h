// Name   Hongback Son           Date  19/09/22               student number 133181164
/////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>

#ifndef AID_ERROR
#define AID_ERROR
namespace aid {
	class Error {
		char *addMessage;
	public:
		//	Error();
		explicit Error(const char* errorMessage = nullptr);
		Error(const Error& em) = delete;
		Error& operator=(const Error& em) = delete;
		virtual ~Error();
		void clear();
		bool isClear() const;
		void message(const char* str);
		const char* message()const;
	};
	std::ostream& operator<<(std::ostream&, const Error&);
}
#endif
