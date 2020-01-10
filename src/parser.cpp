#include "parser.hpp"

Parser::Parser():
    mIsValid(true)
{
}

Parser::~Parser()
{
}

bool Parser::operator()()
{
    return mIsValid;
}