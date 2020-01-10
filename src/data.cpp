#include "data.hpp"
#include "token.hpp"
#include "symbol.hpp"

int    argc;
char** argv;
std::string source;
std::string preprocess;
std::vector<Token*> tokenize;
std::vector<Symbol*> parser;

int&    DATA::ARGC(){return argc;}
char**& DATA::ARGV(){return argv;}
std::string& DATA::SOURCE(){return source;}
std::string& DATA::PREPROCESS(){return preprocess;}
std::vector<Token*>&  DATA::TOKENIZE(){return tokenize;}
std::vector<Symbol*>& DATA::PARSER(){return parser;}