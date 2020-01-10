#include "symbol.hpp"

std::vector<Symbol*> Symbol::SYMBOLS;

Symbol::Symbol()
{
    SYMBOLS.push_back(this);
}

Symbol::~Symbol()
{
}

void Symbol::destroy()
{
    for(auto&& sym : SYMBOLS)
        delete sym;
}