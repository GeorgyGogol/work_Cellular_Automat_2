#pragma once

#include <string>
#include <map>

class AbstractField;
class SimpleSquareTestField;
class FieldSquare;

class FieldsIO
{
public:
    FieldsIO();

private:
    typedef AbstractField* (FieldsIO::*ReadMethod)(const std::string&);
    typedef std::map<std::string, ReadMethod> TyLoadMethodsMap;

    TyLoadMethodsMap LoadMethods;

public:
    void SaveToFile(const std::string& fileName, SimpleSquareTestField* pField);
    void SaveToFile(const std::string& fileName, FieldSquare* pField);

    AbstractField* LoadFromFile(const std::string& fileName);

    //AbstractField* LoadFromFile(std::string fileName);

};

