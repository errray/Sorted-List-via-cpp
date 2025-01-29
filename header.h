#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <cstddef>  // For size_t
#include <stdexcept>
#define SORTEDLIST_MAX_SIZE 20  // Defining the macro with a size of 20

class SortedList {
private:
    float elements[SORTEDLIST_MAX_SIZE];  // Array to hold elements
    size_t size;  // Variable to hold the current size of the list

public:
    SortedList() {size = 0;};
    void copy(const SortedList& other); 
    float index(size_t index);
    size_t insert(float number);
    float remove(size_t index);
    size_t find(float number);
    void print();
};

#endif // HEADER_H_INCLUDED
