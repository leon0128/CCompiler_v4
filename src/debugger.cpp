#include "debugger.hpp"
#include "file_manager.hpp"
#include "data.hpp"
#include "token.hpp"
#include <sstream>
#include <iostream>

const char* Debugger::SOURCE_FILENAME
    = "debug/source.log";
const char* Debugger::PREPROCESS_FILENAME
    = "debug/preprocess.log";
const char* Debugger::TOKENIZE_FILENAME
    = "debug/tokenize.log";

void Debugger::debug()
{
    sourceDebug();
    preprocessDebug();
    tokenizeDebug();
}

void Debugger::sourceDebug()
{
    if(!FileManager::write(SOURCE_FILENAME,
                           DATA::SOURCE()))
        error("falied to debug source code");
}

void Debugger::preprocessDebug()
{
    if(!FileManager::write(PREPROCESS_FILENAME,
                           DATA::PREPROCESS()))
        error("failed to debug preprocess data");
}

void Debugger::tokenizeDebug()
{
    std::stringstream stream;

    stream << "[idx, ln, val]\n\n";

    for(std::size_t tokIdx = 0, preIdx = 0, ln = 1;
        preIdx < DATA::PREPROCESS().size() && tokIdx < DATA::TOKENIZE().size();
        preIdx++)
    {
        if(DATA::TOKENIZE().at(tokIdx)->pos == preIdx)
        {
            stream << "- [" << tokIdx
                   << ", "  << ln
                   << ", \"";
            for(std::size_t i = 0;
                i < DATA::TOKENIZE().at(tokIdx)->size;
                i++)
                stream << DATA::PREPROCESS().at(preIdx + i);
            stream << "\"]\n";
            
            preIdx += DATA::TOKENIZE().at(tokIdx)->size - 1;
            tokIdx++;
        }
        else
        {
            if(DATA::PREPROCESS().at(preIdx) == '\n')
                ln++;
        }
    }

    std::string data(stream.str());
    if(!FileManager::write(TOKENIZE_FILENAME,
                           data))
        error("failed to debug tokenize data");
}

void Debugger::error(const char* message)
{
    std::cerr << "debug_error:\n    "
              << message
              << std::endl;
}