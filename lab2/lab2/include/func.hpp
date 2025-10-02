#pragma once
#include <string>
#include <stdexcept>
#include <iostream>

class Four {
private:
    size_t arraySize;
    unsigned char *dataArray;
public:
    Four();
    Four(unsigned int t);
    Four(const std::initializer_list< unsigned char> &vals);
    Four(const unsigned char *vals, const size_t n);
    Four(const std::string &vals);

    Four(const Four& other);
    Four(Four&& other) noexcept;

    Four add(const Four &other) const;
    Four sub(const Four &other) const;

    bool eq(const Four &other) const;
    bool gt(const Four &other) const;
    bool ge(const Four &other) const;
    bool lt(const Four &other) const;
    bool le(const Four &other) const;

    std::ostream& print(std::ostream& outputStream) const;

    virtual ~Four() noexcept;
};