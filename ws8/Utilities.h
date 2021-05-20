#ifndef SICT_UTILITIES_H
#define SICT_UTILITIES_H
// Workshop 8 - Smart Pointers
// Utilities.h
// Chris Szalwinski from Cornel Barna
// 2019/03/17
//  Hongback Son / 133181164 / SAA /Mar 19 / hbson1@myseneca.ca

#include "List.h"
#include "Element.h"

namespace sict {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price);
}

#endif