#include <iostream>
using namespace std;

#include "vectortemplate.h"

int main() {
    Vector<int> intVec;
    intVec.push_back(10);
    intVec.push_back(20);
    intVec.push_back(30);
    cout << "Integer Vector: ";
    intVec();

    intVec.insert_by_index(1, 15);
    cout << "After inserting 15 at index 1: ";
    intVec();

    intVec.pop_back();
    cout << "After popping the back: ";
    intVec();

    intVec.pop_front();
    cout << "After popping the front: ";
    intVec();

    size_t index = intVec.find(20);
    cout << "Index of 20: " << index << endl;

    Vector<float> floatVec;
    floatVec.push_back(3.14f);
    floatVec.push_back(2.71f);
    floatVec.push_back(1.61f);
    cout << "Float Vector: ";
    floatVec();

    floatVec.insert_by_index(1, 2.5f);
    cout << "After inserting 2.5 at index 1: ";
    floatVec();

    floatVec.pop_back();
    cout << "After popping the back: ";
    floatVec();

    floatVec.pop_front();
    cout << "After popping the front: ";
    floatVec();

    index = floatVec.find(2.71f);
    cout << "Index of 2.71f: " << index << endl;

    Vector<double> doubleVec;
    doubleVec.push_back(3.14159);
    doubleVec.push_back(2.71828);
    doubleVec.push_back(1.61803);
    cout << "Double Vector: ";
    doubleVec();

    doubleVec.insert_by_index(1, 2.5);
    cout << "After inserting 2.5 at index 1: ";
    doubleVec();

    doubleVec.pop_back();
    cout << "After popping the back: ";
    doubleVec();

    doubleVec.pop_front();
    cout << "After popping the front: ";
    doubleVec();

    index = doubleVec.find(2.71828);
    cout << "Index of 2.71828: " << index << endl;

    Vector<char> charVec;
    charVec.push_back('a');
    charVec.push_back('b');
    charVec.push_back('c');
    cout << "Character Vector: ";
    charVec();

    charVec.insert_by_index(1, 'z');
    cout << "After inserting 'z' at index 1: ";
    charVec();

    charVec.pop_back();
    cout << "After popping the back: ";
    charVec();

    charVec.pop_front();
    cout << "After popping the front: ";
    charVec();

    index = charVec.find('b');
    cout << "Index of 'b': " << index << endl;

    Vector<string> stringVec;
    stringVec.push_back("Hello");
    stringVec.push_back("World");
    stringVec.push_back("Vector");
    cout << "String Vector: ";
    stringVec();

    stringVec.insert_by_index(1, "C++");
    cout << "After inserting 'C++' at index 1: ";
    stringVec();

    stringVec.pop_back();
    cout << "After popping the back: ";
    stringVec();

    stringVec.pop_front();
    cout << "After popping the front: ";
    stringVec();

    index = stringVec.find("World");
    cout << "Index of 'World': " << index << endl;

    cout << "Sorting the Integer Vector in ascending order: ";
    intVec.sort();
    intVec();

    cout << "Sorting the Float Vector in descending order: ";
    floatVec.sort(true);
    floatVec();

    return 0;
}
