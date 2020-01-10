#pragma once

class Parser
{
public:
    Parser();
    ~Parser();

    bool operator()();

private:
    bool mIsValid;
};