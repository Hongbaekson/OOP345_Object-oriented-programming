//(133181164 hongback Son)


#pragma once
#include <string>

namespace sict
{
	class Text
	{
		std::string* contents;
		size_t numberOfRecords;
	public:
		Text();
		Text(const char* filename);

		Text(const Text& rhs);
		Text& operator=(const Text& rhs);

		Text(Text&& rhs);
		Text& operator=(Text&& rhs);
		~Text();

		size_t size() const;
	};
}