# my_cpp_doubly_linked_list
> Implementation of Own String Class
 
 In this presents an implementation of a class named `util::list`. This class behavior is a simplified implementation of the `std::list`.

Full and detailed examples of uses and tests of the class `util::list` are given in the `main.cpp` file. Each method and operator is very carefully tested (e.g., concatenating different strings, ..., etc).

An example test run is shown in the following screenshot:

<img src="doc/figures/screenshot.png" alt="fishy" width="400px">

Note that the **terminal output is colored** (using [ANSI escape codes](https://en.wikipedia.org/wiki/ANSI_escape_code)) for better visibility.


**Doxygen** generated documentation (in html and LaTeX formats) can be found at [`doc/html/index.html`](doc/html/index.html) and [`doc/latex/refman.pdf`](doc/latex/refman.pdf), respectively. The configuration file `Doxyfile` is used with the Doxygen generation tool.


The following design and implementation criteria are followed:
* **No C/C++ standard functions or classes are used** to realize `util::list` class. This include, e.g., `strcmp`, `strlen` and of course using `std::string` as an internal representation of `util::list`.
  * This means own functions/methods are developed and implemented to calculate the length of a `char*`, to compare character sequences or to copy them full or partially.
* For now, **no error handling** (e.g., accessing an invalid index by using operator []) is implemented. This may be done later.
  * **Use this class at your own risk** :).
* The code follows [LLVM Coding Standards](https://llvm.org/docs/CodingStandards.html).
* The *[sanke_case](https://en.wikipedia.org/wiki/Snake_case)* naming convention is used for variable and function names (with few exceptions).

* **Use this class at your own risk** :).

 ## General Functionality
* The class `util::list` is implemented inside the two files `utillist.cpp` and `utillist.h`
* Class list is within the namespace `util`
* The memory management is done by using a pointer (`internal_buffer`) pointing to the data type char. `char*` are (normally) null terminated. This means, that the last character is always a `\0` (NULL character) which marks the end of a char sequence. This character is never printed as it just allows for detecting whether the end of a char sequence has been reached. The string is always null-terminate (internally!)
* Initially, the class provides memory for 10 printable characters. Note that this default value is provided by the constant `INITIAL_SIZE` (defined at the top of `utillist.h`). It can be changed if another value is desired. 
* A relatively simple concept is designed and implemented to extend the internal memory if `util::list` has to store more than 10 characters.


## Constructors
The following constructors are implemented:
* `string()` : Default constructor with empty initialization
* `string(size_t intialSize)` : constructor with parameter for the initial memory size to initialization with.
* `string(const string&)` : Copy constructor: Creates a deep copy of a passed string.
* `string(const char*)` : Constructor with parameter `const char*`.
* `string(const std::string&)` : Constructor with parameter std::string.

## Operators
The following operators are implemented:
* Operator + and += such that string, std::string and (const) char* can be added
* Assignment operator = such that string, std::string and (const) char* can be assigned
* Comparison operators == and != such that comparisons with `util::list`, `std::string` and `(const) char*` are possible. With respect to the last two cases, `std::string` and `const char*` may both be LHS as well as RHS arguments.
* operator [] to access individual characters of `util::list` object.
* Streaming operator << to print `util::list` to `std::cout`.

## Methods
The following methods are implemented:
* `clear()`: Clears your string object.

  It erases the contents of the string, which becomes an empty string (with a length of 0 characters).

* `substr(pos, length)`: Returns a substring object of type util::list which starts at pos. Parameter length specifies the amount of characters of the new `util::list` to be returned.

  The substring is the portion of the object that starts at character position start_position and spans len characters (or until the end of the string, whichever comes first).
  
* `length()`: Returns the amount of characters of your string excluding `\0`. Might be smaller than the actual reserved memory.

* `size()`: (synonyme to `length()`) Returns the amount of characters of your string excluding `\0`. Might be smaller than the actual reserved memory.

* `capacity()`: Returns the size of the storage space currently allocated for the string, expressed in terms of bytes.

* `rawSize(const char* rawChar)` : Get the amount of characters of a raw char* string excluding the terminating `\0`.

* `c_str()`: Allows raw access to the internal C-string respectively the `char*` pointer.

  Returns a pointer to an array that contains a null-terminated sequence of characters (i.e., a C-string) representing the current value of the string object.

* `intialize_string(size_t length = 0)` Ensure a string is initialized before using it. It initialize an empty string with buffer size of the given length.

* `deepCopy(const char* rawChar, size_t startPosition = 0)`: Deep copy of primitive C-string into the string internal buffer. 
  
  This function realizes a design and implementation of a concept to extend the internal memory if util::list has to store more than its current allocated buffer size. 

  Note that the function copy the passed char array starting from the startPosition (i.e. it can write starting from any position in the internal
string buffer) startPosition default is 0

* `compare(const char* s1, const char* s2)`: Compares two char * strings lexicographically.
  
  This function is my own implementation of the std::strcmp() function. Note this function performs a binary comparison of the ASCII code of the characters.

## Non-member Functions
Some non-member utility functions are implemented that help for better functionality and output. These functions are:
* `deepCopy(char* rawCharTarget, const char* rawCharSource, size_t destStartPosition, size_t srcEndPosition)` : Deep copy of primitive C-string into another primitive C-string.
  This function realizes a design and implementation of a concept to low-level copy and fill a primitive C-string with another primitive C-string starting from a given start position and with a desired number of character from the sourrce string.

  Note that the function copy the passed char array starting from the startPosition (i.e. it can write starting from any position in the destination string buffer) startPosition default is 0

* `printHeader(const char* text)`,\
  `printSubHeader(const char* text)`,\
  `printTestCase(const char* text)` : \
  To print a nicely formatted and colored text header, sub header, title header, respectively to the terminal


## References
* Standard Strings library : https://en.cppreference.com/w/cpp/string
* C++ ISO Standard https://isocpp.org/std/the-standard
* C++ documentation - DevDocs : https://devdocs.io/cpp/
* LLVM Coding Standards: https://llvm.org/docs/CodingStandards.html
* sanke_case convention : https://en.wikipedia.org/wiki/Snake_case
* Markdown Basic Syntax : https://www.markdownguide.org/basic-syntax
* Doxygen : https://www.doxygen.nl/index.html
