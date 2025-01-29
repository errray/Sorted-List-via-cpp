#include "header.h"
using namespace std;
#include <cstdlib>  // For std::abs
#include <iostream>
#include <cmath>  // For std::fabs

void SortedList::copy(const SortedList& other) {
    // Copy elements from 'other' to 'this' list
    for (size_t i = 0; i < other.size; i++) {
        elements[i] = other.elements[i];
    }

    // Copy the size from 'other' to 'this' list
    size = other.size;
}

float SortedList::index(size_t index) {
    // Ensure the given index is within the bounds of the list
    if (index < size) {
        return elements[index];
    } else {
        throw std::out_of_range("Index is out of range");
    }
}

size_t SortedList::insert(float number) {
    // Check if the list has reached its maximum capacity
    if (size == SORTEDLIST_MAX_SIZE) {
        throw std::length_error("The list is full");
    }

    int sign;               // Determines the sign of the difference
    size_t index_point;     // The position where the new element should be inserted
    int index_of_number;    // Final index of the inserted number

    if (size == 0) {
        // If the list is empty, add the element to the first position
        elements[0] = number;
        size++;
        return 0;
    } else if (size == 1) {
        // If the list contains only one element, compare with the new number
        if (number < elements[0]) {
            // If the new number is smaller, insert it at the beginning
            elements[1] = elements[0];
            elements[0] = number;
            size++;
            return 0;
        } else {
            // Otherwise, insert it at the end
            elements[1] = number;
            size++;
            return 1;
        }
    } else {
        // General case for lists with more than one element
        float min_difference = number - elements[0];
        index_point = 0;

        // Find the closest position to insert the new number
        for (size_t i = 0; i < size; i++) {
            float absolute_difference = std::fabs(number - elements[i]);
            float real_difference = number - elements[i];
            if (absolute_difference < std::fabs(min_difference)) {
                min_difference = real_difference;
                index_point = i;
            }
        }

        // Determine the insertion direction based on the difference sign
        sign = (min_difference >= 0) ? 1 : 0;

        if (sign == 1) {
            // Shift elements to the right and insert the number
            for (size_t i = size; i > index_point; i--) {
                elements[i] = elements[i - 1];
            }
            elements[index_point + 1] = number;
            index_of_number = index_point + 1;
        } else {
            // Shift elements to the right and insert the number
            for (size_t i = size; i > index_point; i--) {
                elements[i] = elements[i - 1];
            }
            elements[index_point] = number;
            index_of_number = index_point;
        }

        size++;
        return index_of_number;
    }
}

float SortedList::remove(size_t index) {
    // Ensure the given index is valid
    if (index >= size) {
        throw std::out_of_range("Index is out of range");
    }

    float value_at_given_index = elements[index];

    // Shift elements to the left to fill the removed position
    for (size_t i = index; i < size - 1; i++) {
        elements[i] = elements[i + 1];
    }

    size--; // Reduce the size of the list
    return value_at_given_index;
}

size_t SortedList::find(float number) {
    // Binary search for the given number in the sorted list
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (elements[mid] == number) {
            return mid;  // Found the element, return its index
        } else if (elements[mid] < number) {
            low = mid + 1;  // Search in the right half
        } else {
            high = mid - 1;  // Search in the left half
        }
    }

    // If the number is not found
    throw std::domain_error("Number is not in the list");
}

void SortedList::print() {
    // Check if the list is empty
    if (size == 0) {
        throw std::runtime_error("Error: The list is empty.");
    }

    // Print all elements in the list
    for (size_t i = 0; i < size; ++i) {
        cout << elements[i] << " ";
    }
    cout << endl;
}
