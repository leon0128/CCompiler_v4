#include "token.hpp"

std::vector<Token*> Token::TOKENS;

void Token::destroy()
{
    for(auto&& token : TOKENS)
        delete token;
}

Token::Token(std::size_t inPos,
             std::size_t inSize):
    pos(inPos),
    size(inSize)
{
    TOKENS.push_back(this);
}