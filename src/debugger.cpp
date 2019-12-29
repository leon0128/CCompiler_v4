#include "debugger.hpp"
#include "file_manager.hpp"
#include "data.hpp"
#include <iostream>

const char* Debugger::SOURCE_FILENAME
    = "debug/source.log";
const char* Debugger::PREPROCESS_FILENAME
    = "debug/preprocess.log";

void Debugger::debug()
{
    sourceDebug();
    preprocessDebug();
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

void Debugger::error(const char* message)
{
    std::cerr << "debug_error:\n    "
              << message
              << std::endl;
}