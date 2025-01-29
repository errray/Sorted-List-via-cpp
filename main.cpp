#include <iostream>
#include <stdexcept>
#include "header.h"
using namespace std;


int main() {


    // Test: Copy method functionality
    try {
        // Orijinal listeyi oluþtur ve bazý elemanlar ekle
        SortedList originalList;
        originalList.insert(1.0);
        originalList.insert(2.0);
        originalList.insert(3.0);
        originalList.insert(4.5);
        originalList.insert(5.5);

        // Kopyalanacak listeyi oluþtur ve copy fonksiyonunu çaðýr
        SortedList copiedList;
        copiedList.copy(originalList);  // originalList'i copiedList'e kopyala

        // Orijinal ve kopya listenin elemanlarýný yazdýr
        cout << "Original List: ";
        originalList.print();
        cout << "Copied List: ";
        copiedList.print();

        cout << "Copy test successful if both lists match." << endl;
    } catch (const exception& e) {
        cout << "ERROR: Copy functionality failed - " << e.what() << endl;
    }

    // Test: Index method with out-of-range error
    try {
        SortedList testList;
        testList.insert(10.0);
        testList.insert(20.0);
        testList.insert(30.0);

        cout << "Trying to access index 5 (out of range):" << endl;
        float outOfRangeElement = testList.index(5);  // Bu, out-of-range hatasý fýrlatmalý
        cout << "ERROR: Index out of range error was not thrown. Accessed element: " << outOfRangeElement << endl;
    } catch (const out_of_range& e) {
        cout << "Passed out-of-range index test: " << e.what() << endl;  // Beklenen sonuç
    }

    // Test: Index method with valid range
    try {
        SortedList testList;
        testList.insert(10.0);
        testList.insert(20.0);
        testList.insert(30.0);

        cout << "Accessing valid index 1: " << testList.index(1) << endl;  // Beklenen çýktý: 20.0
        cout << "Passed valid index access test." << endl;
    } catch (const exception& e) {
        cout << "ERROR: Valid index access failed - " << e.what() << endl;
    }


    // Test: Remove method with out-of-range error
    try {
        SortedList testList;
        testList.insert(10.0);
        testList.insert(20.0);
        testList.insert(30.0);

        cout << "Initial List: ";
        testList.print();

        cout << "\nTrying to remove element at index 5 (out of range):" << endl;
        testList.remove(5);  // This should throw an out-of-range error
        cout << "ERROR: Index out of range error was not thrown for remove." << endl;
    } catch (const out_of_range& e) {
        cout << "Passed out-of-range remove test: " << e.what() << endl;  // Expected outcome
    }

    // Test: Remove method with valid index
    try {
        SortedList testList;
        testList.insert(10.0);
        testList.insert(20.0);
        testList.insert(30.0);

        cout << "\nInitial List: ";
        testList.print();

        cout << "\nRemoving element at index 1 (should be 20.0):" << endl;
        float removedElement = testList.remove(1);  // Should remove this element
        cout << "Removed element: " << removedElement << endl;
        cout << "List after removal: ";
        testList.print();
        cout << "Passed valid remove test if list is updated correctly." << endl;
    } catch (const exception& e) {
        cout << "ERROR: Remove functionality failed - " << e.what() << endl;
    }

    // Test: Find method with non-existent number
    try {
        SortedList testList;
        testList.insert(10.0);
        testList.insert(20.0);
        testList.insert(30.0);

        cout << "\nCurrent List for find tests: ";
        testList.print();

        cout << "\nTrying to find 40.0 (not in the list):" << endl;
        size_t index = testList.find(40.0);  // Should throw a domain_error
        cout << "ERROR: Non-existent element error was not thrown. Found at index: " << index << endl;
    } catch (const domain_error& e) {
        cout << "Passed non-existent element find test: " << e.what() << endl;  // Expected outcome
    }

    // Test: Find method with existing number
    try {
        SortedList testList;
        testList.insert(10.0);
        testList.insert(20.0);
        testList.insert(30.0);

        cout << "\nCurrent List for find tests: ";
        testList.print();

        cout << "\nFinding 20.0 (should be at index 1):" << endl;
        size_t index = testList.find(20.0);  // Should find at index 1
        cout << "Found 20.0 at index: " << index << endl;
        cout << "Passed valid find test if index is correct." << endl;
    } catch (const exception& e) {
        cout << "ERROR: Find functionality failed - " << e.what() << endl;
    }

    // Test: Insert random values to fill the list and check sorted order
    try {
        SortedList testList;
        cout << "Inserting random values into the list:" << endl;
        for (int i = 0; i < SORTEDLIST_MAX_SIZE; ++i) {
            float randomValue = static_cast<float>(rand() % 100);  // Random number between 0 and 99
            cout << "Inserting " << randomValue << "..." << endl;
            testList.insert(randomValue);
            testList.print();
        }
        cout << "List after inserting " << SORTEDLIST_MAX_SIZE << " elements:" << endl;
        testList.print();
    } catch (const exception& e) {
        cout << "ERROR: Unexpected exception during insertion - " << e.what() << endl;
    }

    // Test: Insertion after reaching maximum capacity
    try {
        SortedList testList;
        // Fill the list to max capacity
        for (int i = 0; i < SORTEDLIST_MAX_SIZE; ++i) {
            testList.insert(static_cast<float>(i));
        }
        cout << "\nTrying to insert another element after reaching max capacity (should throw length_error):" << endl;
        testList.insert(50.0);  // This should throw a length_error
        cout << "ERROR: Length error was not thrown for exceeding max capacity." << endl;
    } catch (const length_error& e) {
        cout << "Passed max capacity insertion test: " << e.what() << endl;  // Expected outcome
    }

    return 0;

}

