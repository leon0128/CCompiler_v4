#pragma once

#include <string>
#include <vector>

class Token;

namespace DATA
{
    int&    ARGC();
    char**& ARGV();
    
    std::string& SOURCE();
    std::string& PREPROCESS();
    
    std::vector<Token*>& TOKENIZE();
};