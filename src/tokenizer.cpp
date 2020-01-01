#include "tokenizer.hpp"
#include "token.hpp"
#include "data.hpp"

Tokenizer::Tokenizer():
    mIndex(0),
    mIsValid(true)
{
}

Tokenizer::~Tokenizer()
{
}

bool Tokenizer::operator()()
{
    for(std::size_t i = 0; i < DATA::PREPROCESS().size(); i++)
    {
        

        std::size_t endPos = i;
        for(; endPos < DATA::PREPROCESS().size(); endPos)
        {
            if()
        }
    }

    return mIsValid;
}

bool Tokenizer::isIdentifier()
{
    if(!isAlphabet(DATA::PREPROCESS().at(mIndex)))
        return false;

    Token* token = new Token(mIndex);
    for(; mIndex < DATA::PREPROCESS().size(); mIndex++)
    {
        char c = DATA::PREPROCESS().at(mIndex);
        if(!isAlphabet(c) && !isNumber(c))
            break;
    }

    token->size = mIndex - token->pos;
    DATA::TOKENIZE().push_back(token);
    
    return true;
}

bool Tokenizer::isIntegral()
{
    if(!isNumber(DATA::PREPROCESS().at(mIndex)))
        return false;

    Token* token = new Token(mIndex);
    for(; mIndex < DATA::PREPROCESS().size(); mIndex++)
    {
        if(!isNumber(DATA::PREPROCESS().at(mIndex)))
            break;
    }

    token->size = mIndex - token->pos;
    DATA::TOKENIZE().push_back(token);

    return true;
}

bool Tokenizer::isSymbol()
{
    char c = DATA::PREPROCESS().at(mIndex);

    if(c = 10)
}

bool Tokenizer::isAlphabet(char c) const
{
    if((c >= 'a' && c <= 'z') ||
       (c >= 'A' && c <= 'Z'))
        return true;
    else
        return false;
}

bool Tokenizer::isNumber(char c) const
{
    if(c >= '0' && c <= '9')
        return true;
    else
        return false;
}