// Nour Ahmed
// Matrikal-Nr.: 5200991

/**========================================================================
 * @file      my_extras.h
 * @brief     some extra functions and utilities.
 * @author    Nour Ahmed
 * @email     nahmed@stud.hs-bremen.de, nour
 * @repo      https://github.com/nouremara/cpp_mystring
 * @createdOn 23.11.2022
 * @version   1.0.0
 * @description
 *
 * This file presents an implementation of some extra functions and utilities.
 *========================================================================**/

#ifndef MY_EXTRAS_H
#define MY_EXTRAS_H

#include <iostream>

namespace util {

/*=========================================================================*
	 *      Some Utility functions for printing nice text output               *
	 *=========================================================================*/

	 /**
	* utility functions for printing nice text output
	*
	* ANSI Escape Sequences are used to color the console text,
	* it works for windows and Linux.
	* For Windows, you need to run the program in the new terminal as the old one
	* does not support these codes.
	* see: https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797
	*/
void printHeader(const char* text) {
	size_t spaces_needed = (80 - std::strlen(text)) / 2 - 2;

	std::cout << "\033[1;30;106m"; // set text and background colors
	std::cout << "-------------------------------------------------------------------------------\n-";
	for (int i = 0; i < spaces_needed; ++i) {
		std::cout << " ";
	}
	std::cout << text;
	for (int i = 0; i < spaces_needed; ++i) {
		std::cout << " ";
	}
	std::cout << " -\n";
	std::cout << "-------------------------------------------------------------------------------\n";
	std::cout << "\033[0m\n"; // reset text and background colors
}

void printSubHeader(const char* text) {
	std::cout << "\033[32m"; // set text and background colors
	std::cout << text;
	std::cout << "\033[0m\n"; // reset text and background colors
}

void printTestCase(const char* text) {
	std::cout << "\033[93m  > ["; // set text and background colors
	std::cout << text;
	std::cout << "]\033[0m \n"; // reset text and background colors
}



} // namespace util

#endif /* MY_EXTRAS_H */
