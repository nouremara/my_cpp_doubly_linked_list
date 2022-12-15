// Nour Ahmed
// Matrikal-Nr.: 5200991
// Assignment 1 – Doubly Linked List

/**============================================================================
 * @file        : main.cpp
 * @brief       : test of own implementation of list class
 * @author      : Nour Ahmed
 * @email       : nahmed@stud.hs-bremen.de, nour
 * @repo        : https://github.com/nouremara/cpp_my_Doubly_Linked_List
 * @repo        :
 * @createdOn   : 08.12.2022
 * @version     : 1.0.0
 * @description :
 *
 * Defines the entry point for the NourUtilList application
 * In this application the class util::list is used and tested.
 * Each method and operator is tested with all possible uasges (e.g.,
 * pushing and poping elements etc.)
 * Note: For this task some error handling is implemented.
 * An exception-based error handling for various error cases.
 * Example: Calling pop_front on an empty list shall result
 * in an appropriate exception.
 *==========================================================================**/

#include <iostream>
#include <string>

#include "my_extras.h"
#include "utillist.cpp"  // to avoid link errors we may get while creating an object of list class
#include "utillist.h"

// mockup class used in testing
class Person {
    std::string m_name;
    int m_age;

   public:
    Person(std::string name = "", int age = -1) : m_name(name), m_age(age){};
    std::string getName() const { return m_name; }
    int getAge() const { return m_age; }

    friend std::ostream& operator<<(std::ostream& iostream, const Person& person) {
        return (iostream << person.getName() << "\t" << person.getAge() << std::endl);
    }
};

int main() {
    util::printHeader("NourUtilList (Doubly Linked Lists) Application");

    util::printSubHeader("Variable used for testing and their values");
    util::list<int> myList;
    std::cout << "myList: " << myList << "\n";
    std::cout << "-------------------------------------------------------------------------------\n\n";

    util::printSubHeader("Test Member Methods");
    util::printTestCase("push_front() and push_back()");
    myList.push_front(3);
    myList.push_back(5);
    myList.push_back(12);
    myList.push_back(9);
    myList.push_back(12);
    myList.push_front(6);
    myList.push_back(88);
    std::cout << "\tmyList: " << myList << "\n";

    util::printTestCase("front()");
    std::cout << "front(): " << myList.front() << "\n";

    myList.front() = 100;
    std::cout << "\tset front(): " << myList.front() << "\n";
    std::cout << "\tmyList: " << myList << "\n";

    util::printTestCase("back()");
    std::cout << "\tback() : " << myList.back() << "\n";

    myList.back() = 200;
    std::cout << "\tset back(): " << myList.back() << "\n";
    std::cout << "\tmyList: " << myList << "\n";
    std::cout << "-------------------------------------------------------------------------------\n\n";

    util::printTestCase("pop_front()");

    myList.pop_front();
    std::cout << "\tmyList: " << myList << "\n";

    util::printTestCase("pop_back()");
    myList.pop_back();
    std::cout << "\tmyList: " << myList << "\n";

    std::cout << "-------------------------------------------------------------------------------\n\n";
   
    util::printSubHeader("Test Iterators");

    // Finally, print your list as shown:
    util::list<int>::iterator myItB = myList.begin();
    util::list<int>::iterator myItE = myList.end();
    while (myItB != myItE) {
        std::cout << "\t" << (*myItB) << std::endl;
        ++myItB;
    }

    util::printTestCase("Test erase()");

    // set the iterator to the begin of the list again
    myItB = myList.begin();
    ++myItB;  // advance the iterator one element ahead

    myList.erase(myItB);
    std::cout << "\tmyList: " << myList << "\n";
    std::cout << "-------------------------------------------------------------------------------\n\n";

    util::printSubHeader("Test Other Methods");
    util::printTestCase("Test clear()");
    myList.clear();
    std::cout << "\tmyList: " << myList << "\n";
    std::cout << "-------------------------------------------------------------------------------\n\n";

    util::list<Person> l;  // Store a type of your choice

    // Call push_back a few times to add elements
    l.push_back(Person("AB", 10));
    l.push_back(Person("CD", 20));
    l.push_back(Person("EF", 30));
    l.push_back(Person("GH", 40));

    util::printSubHeader("Variable used for testing and their values");
    std::cout << "List l: " << l;
    std::cout << "-------------------------------------------------------------------------------\n\n";

    util::printSubHeader("Test Iterators");
    // Finally, print your list as shown:
    util::list<Person>::iterator itB = l.begin();
    util::list<Person>::iterator itE = l.end();
    while (itB != itE) {
        std::cout << "\t" << (*itB).getName() << "\t" << itB->getAge() << std::endl;
        ++itB;
    }
    std::cout << "-------------------------------------------------------------------------------\n\n";

    util::printSubHeader("Test erase()");
    util::printTestCase("Test erase()");

    // set the iterator to the begin of the list again
    itB = l.begin();
    ++itB;  // advance the iterator one element ahead

    l.erase(itB);
    std::cout << " List l: " << l << "\n";

    util::printTestCase("Test erase() the end() element");
    itE = l.end();
    l.erase(itE);
    std::cout << " List l: " << l << "\n";
    std::cout << "-------------------------------------------------------------------------------\n\n";

    util::printSubHeader("Test insert()");
    util::printTestCase("Test insert()");

    // set the iterator to the begin of the list again
    itB = l.begin();
    ++itB;  // advance the iterator one element ahead
    l.insert(itB, Person("XY", 100));
    std::cout << " List l: " << l << "\n";

    util::printTestCase("Test insert() at end()");
    l.insert(l.end(), Person("ZZ", 200));
    std::cout << " List l: " << l << "\n";

    return 0;
}