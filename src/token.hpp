#pragma once

#include <vector>

class Token
{
private:
    static std::vector<Token*> TOKENS;

public:
    static void destroy();

    Token(std::size_t inPos,
          std::size_t inSize);
    ~Token();
    
    std::size_t pos;
    std::size_t size;
};