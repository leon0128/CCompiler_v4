#pragma once

#include <cstddef>

class Tokenizer
{
public:
    Tokenizer();
    ~Tokenizer();

    bool operator()();

private:
    bool isIdentifier();
    bool isIntegral();
    bool isSymbol();
    bool isIgnore();

    bool isAlphabet(char c) const;
    bool isNumber(char c) const;

    std::size_t mIndex;
    bool mIsValid;
};