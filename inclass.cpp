#include <iostream>
#include <stdexcept>
#include "intclass.h"

using namespace ns;

set::set(int len) {
    length = len;
    for (int i = 0; i < len; i++) {
        data[i] = i + 1;
    }
}

set::set(int len, const int *array) {
    for (int i = 0; i < len; i++) {
        add_element(array[i]);
    }
}

std::ostream & set::print(std::ostream &c) {
    for (int i = 0; i < length; i++)
        c << data[i] << endl;
    return c;
}

std::istream & set::scan(std::istream &s) {
    int value;
    s >> length;
    for (int i = 0; i  < length; i++) {
        s >> value;
        add_element(value);
    }
    return s;
}

set &set::merge(set &merge_data) {
    set new_data;
    for (int i = 0; i < length; i++)
        new_data.add_element(data[i]);
    for (int i = 0; i < merge_data.length; i++)
        new_data.add_element(merge_data.data[i]);
    return new_data;
}

void set::add_element(int value) {
    if (length == max_length)
        throw std::overflow_error("Overflow error");
    for (int i = 0; i < length; i++)
        if (data[i] == value)
            throw std::range_error("Element is of the data already");
    data[length] = value;
    length++;
}

set &set::intersection(set &inter_data) const {
    set new_data;
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < inter_data.length; j++) {
            if (data[i] == inter_data.data[j])
                new_data.add_element(data[i]);
        }
    }
    return new_data;
}

set &set::subtraction(set &sub_data) {
    set inter_data = intersection(sub_data);
    set new_data;
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < inter_data.length; j++) {
            if (data[i] == inter_data.data[i])
                new_data.add_element(data[i]);
            if (sub_data.data[i] == inter_data.data[i])
                new_data.add_element(sub_data.data[i]);
        }
    }
    return new_data;
}

int set::is_in_set(int value) {
    for (int i = 0; i < length; i++)
        if (data[i] == value)
            return 0;
    return 1;
}
