#include "compiler.hpp"

int main(int argc, char** argv)
{
    Compiler compiler;

    if(compiler(argc, argv))
        return 0;
    else
        return 1;
}