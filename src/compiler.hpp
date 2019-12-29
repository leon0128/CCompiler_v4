#pragma once

class Compiler
{
public:
    Compiler();
    ~Compiler();

    bool operator()(int argc, char** argv);

private:
    bool error(const char* message);

    bool mIsValid;
};