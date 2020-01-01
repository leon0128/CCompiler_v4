#pragma once

class Compiler
{
public:
    Compiler();
    ~Compiler();

    bool operator()(int argc, char** argv);

private:
    bool error(const char* message);

    class Preprocessor* mPreprocessor;
    class Tokenizer* mTokenizer;

    bool mIsValid;
};