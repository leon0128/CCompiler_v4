#pragma once

#include <vector>

class Token
{
private:
    static std::vector<Token*> TOKENS;

public:
    static void destroy();

    Token(std::size_t inPos = 0,
          std::size_t inSize = 0);
    ~Token();
    
    std::size_t pos;
    std::size_t size;
};