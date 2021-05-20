//(133181164 hongback Son)

#include "Text.h"
#include <fstream>
#include <string>
using namespace std;

namespace sict {

	Text::Text() {
		contents = nullptr;
		numberOfRecords = 0;
	}


	Text::Text(const char* filename) {
		ifstream ifs(filename);
		if (ifs.is_open()) {
			numberOfRecords = 0;
			string line;
			while (getline(ifs, line)) {
				numberOfRecords++;
			}

			contents = new string[numberOfRecords];
			ifs.seekg(0);

			for (size_t i = 0; i < numberOfRecords; i++) {
				getline(ifs, contents[i]);
			}
			ifs.close();
		}
		else {
			*this = Text();
		}
	}

	Text::Text(const Text & rhs) {
		*this = rhs;
	}

	Text & Text::operator=(const Text & rhs) {
		if (this != &rhs) {
			if (contents != nullptr) {
				delete[] contents;
				contents = nullptr;
			}

			this->numberOfRecords = rhs.numberOfRecords;
			if (numberOfRecords != 0)
			{
				this->contents = new string[this->numberOfRecords];
			}

			for (size_t i = 0; i < this->numberOfRecords; i++) {
				this->contents[i] = rhs.contents[i];
			}
		}
		return *this;
	}

	Text::Text(Text && rhs) {
		*this = move(rhs);
	}

	Text & Text::operator=(Text && rhs) {
		if (this != &rhs) {
			if (contents != nullptr) {
				delete[] contents;
				contents = nullptr;
			}

			this->numberOfRecords = rhs.numberOfRecords;
			if (numberOfRecords != 0)
			{
				this->contents = rhs.contents;
				rhs.contents = nullptr;
			}
		}
		return *this;
	}

	Text::~Text() {
		delete[] contents;
	}

	size_t Text::size() const {
		return numberOfRecords;
	}
}
