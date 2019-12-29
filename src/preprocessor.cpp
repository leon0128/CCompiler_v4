#include "preprocessor.hpp"
#include "data.hpp"
#include "file_manager.hpp"
#include <iostream>
#include <string>

Preprocessor::Preprocessor():
    mIsValid(true)
{
}

Preprocessor::~Preprocessor()
{
}

bool Preprocessor::operator()()
{
    if(!isValidArgument())
        return mIsValid;
    if(!isOpenedFile())
        return mIsValid;
    if(!isDeletedComment())
        return mIsValid;

    return mIsValid;
}

bool Preprocessor::isValidArgument()
{
    if(DATA::ARGC() < 2)
    {
        std::cerr << "preprocessor_error:\n    "
                     "invalid number of command line arguments"
                  << std::endl;
        mIsValid = false;
    }

    return mIsValid;
}

bool Preprocessor::isOpenedFile()
{
    if(!FileManager::read(DATA::ARGV()[1],
                          DATA::SOURCE()))
    {
        std::cerr << "preprocessor_error:\n    "
                     "cannot open file "
                     "(" << DATA::ARGV()[1] << ")"
                  << std::endl;
        mIsValid = false;
    }

    DATA::PREPROCESS() = DATA::SOURCE();
    return mIsValid;
}

bool Preprocessor::isDeletedComment()
{
    std::size_t begPos = std::string::npos;
    std::size_t endPos = std::string::npos;

    for(begPos = DATA::PREPROCESS().find("//");
        begPos != std::string::npos;
        begPos = DATA::PREPROCESS().find("//"))
    {
        endPos = DATA::PREPROCESS().find("\n", begPos);
        
        std::size_t count
            = (endPos != std::string::npos)
                ? (endPos - begPos) : (DATA::PREPROCESS().size() - 1);
        
        DATA::PREPROCESS().replace(begPos,
                                   count,
                                   "");
    }

    for(begPos = DATA::PREPROCESS().find("/*");
        begPos != std::string::npos;
        begPos = DATA::PREPROCESS().find("/*"))
    {
        endPos = DATA::PREPROCESS().find("*/", begPos + 2);

        if(endPos != std::string::npos)
        {
            std::string repStr;
            for(std::size_t i = begPos; i != endPos; i++)
            {
                if(DATA::PREPROCESS().at(i) == '\n')
                    repStr.push_back('\n');
            }

            DATA::PREPROCESS().replace(begPos,
                                       endPos + 2 - begPos,
                                       repStr);
        }
        else
        {
            std::cerr << "preprocerror_error:\n    "
                         "unterminated \" /* *** */ \" comment"
                      << std::endl;
            mIsValid = false;
            break; 
        }
    }

    return mIsValid;
}