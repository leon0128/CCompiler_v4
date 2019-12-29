#pragma once

class Debugger
{
private:
    static const char* SOURCE_FILENAME;
    static const char* PREPROCESS_FILENAME;

public:
    Debugger() = delete;

    static void debug();

private:
    static void sourceDebug();
    static void preprocessDebug();

    static void error(const char* message);
};