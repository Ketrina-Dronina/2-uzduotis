#ifndef HAS_DIGIT_H
#define HAS_DIGIT_H

#include <string>

bool has_digit(string s)
{
    return (s.find_first_of("0123456789") != string::npos);
};

#endif