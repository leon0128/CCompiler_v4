#pragma once

class Preprocessor
{
public:
    Preprocessor();
    ~Preprocessor();

    bool operator()();

private:
    bool isValidArgument();
    bool isOpenedFile();
    bool isDeletedComment();

    bool mIsValid;
};