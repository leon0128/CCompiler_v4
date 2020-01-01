#include "compiler.hpp"
#include "data.hpp"
#include "debugger.hpp"
#include "preprocessor.hpp"
#include "tokenizer.hpp"
#include <iostream>

Compiler::Compiler():
    mPreprocessor(nullptr),
    mTokenizer(nullptr),
    mIsValid(true)
{
    mPreprocessor = new Preprocessor();
    mTokenizer = new Tokenizer();
}

Compiler::~Compiler()
{
    Debugger::debug();

    delete mTokenizer;
    delete mPreprocessor;
}

bool Compiler::operator()(int argc, char** argv)
{
    DATA::ARGC() = argc;
    DATA::ARGV() = argv;

    if(!(*mPreprocessor)())
        return error("failed to preprocess");
    if(!(*mTokenizer)())
        return error("failed to tokenize");

    return mIsValid;
}

bool Compiler::error(const char* message)
{
    std::cout << "compiler_error: \n    "
              << message
              << std::endl;

    return mIsValid = false;
}