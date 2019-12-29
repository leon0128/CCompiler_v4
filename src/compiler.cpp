#include "compiler.hpp"
#include "data.hpp"
#include "debugger.hpp"
#include "preprocessor.hpp"
#include <iostream>

Compiler::Compiler():
    mPreprocessor(),
    mIsValid(true)
{
    mPreprocessor = new Preprocessor();
}

Compiler::~Compiler()
{
    Debugger::debug();

    delete mPreprocessor;
}

bool Compiler::operator()(int argc, char** argv)
{
    DATA::ARGC() = argc;
    DATA::ARGV() = argv;

    if(!(*mPreprocessor)())
        return error("failed to preprocess");

    return mIsValid;
}

bool Compiler::error(const char* message)
{
    std::cout << "compiler_error: \n    "
              << message
              << std::endl;

    return mIsValid = false;
}