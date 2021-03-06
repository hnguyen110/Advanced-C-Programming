/*
 * Purpose: Workshop 8
 * Name Of Student: Hien Dao The Nguyen
 * Student Number: 103 152 195
 * Email: hnguyen110@myseneca.ca
 * Date: Mar/26/2021
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 */

#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H
// Workshop 8 - Smart Pointers
// 2019/11 - Cornel


#include "List.h"
#include "Element.h"

namespace sdds {
    List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price);
    List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price);
}

#endif