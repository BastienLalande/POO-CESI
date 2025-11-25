#pragma once
#include <iostream>
#include <string>
#include "DynamicArray.hpp"

using namespace std;

typedef int ArrayElement;

string array_element_to_string(ArrayElement *el) {
  return to_string(*el);
}

void DynamicArray::resize(int size) {
    try {
        ArrayElement **temp;

        this->size = size;
        temp = new ArrayElement *[size];
        for (int i = 0; i < count; i++) {
        temp[i] = els[i];
        }

        delete[] els;
        els = temp;
    } catch (const std::bad_alloc& e) {
        this->size = this->size / 2;
        std::cerr << "Allocation failed: " << e.what() << std::endl;
    }
}
void DynamicArray::fit() { resize(count); }

DynamicArray::DynamicArray(int size) {
    count = 0;
    els = new ArrayElement *[size];
}

int DynamicArray::add(ArrayElement *el) {
    if (count >= RESIZE_THRESHOLD * size) {
        resize(size * 2);
    }

    els[count] = el;

    return count++;
}

ArrayElement *DynamicArray::remove(int i) {
    ArrayElement *ptr = nullptr;

    if(0 <= i && i < count) {
      ptr = els[i];
      els[i] = els[--count];

      if (count < REFIT_THRESHOLD * size) {
        fit();
      }
    }

    return ptr;
}

ArrayElement *DynamicArray::get(int i) { return els[i]; }

void DynamicArray::print() {
    cout << "[";
    if(count > 0) {
      for(int i = 0; i < count - 1; i++) {
        cout << array_element_to_string(els[i]) << ", ";
      }
      cout << array_element_to_string(els[count - 1]);
    }
    cout << "]";
}
