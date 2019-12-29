#include "data.hpp"

int    argc;
char** argv;
std::string source;
std::string preprocess;

int&    DATA::ARGC(){return argc;}
char**& DATA::ARGV(){return argv;}
std::string& DATA::SOURCE(){return source;}
std::string& DATA::PREPROCESS(){return preprocess;}