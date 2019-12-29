#include "compiler.hpp"

#include <iostream>

Compiler::Compiler():
    mIsValid(true)
{
}

Compiler::~Compiler()
{
}

bool Compiler::operator()(int argc, char** argv)
{
    return mIsValid;
}

bool Compiler::error(const char* message)
{
    std::cout << "compiler_error: \n    "
              << message << std::endl;

    return mIsValid = false;
}