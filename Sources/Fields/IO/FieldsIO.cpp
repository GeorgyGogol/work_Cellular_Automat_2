#include "FieldsIO.h"

#include <fstream>
#include "AbstractField.h"
#include "SimpleSquareTestField.h"
#include "FieldSquare.h"

using namespace std;

/**
 * type ver
 * H W
 * Cells ...
 * ...
*/

void FieldsIO::SaveToFile(const std::string&, SimpleSquareTestField *pField)
{
    ofstream file;

    file.open(fileName);
    if (!file.is_open()) return;

    file<<"t0-v1"<<endl;
    file<<pField->getHeight()<<" "<<pField->getWidth()<<endl;

    for (int y = 0; y < pField->getHeight(); ++y) {
        for (int x = 0; x < pField->getWidth(); ++x) {
            file<<pField->getCellAt(x, y)<<" ";
        }
        file<<endl;
    }

    file.close();
}

void FieldsIO::SaveToFile(const std::string&, FieldSquare *pField)
{
    ofstream file;

    file.open(fileName);
    if (!file.is_open()) return;

    file<<"t1-v1"<<endl;
    file<<pField->getHeight()<<" "<<pField->getWidth()<<endl;

    SurfaceCell cell;
    for (int y = 0; y < pField->getHeight(); ++y) {
        for (int x = 0; x < pField->getWidth(); ++x) {
            cell = pField->getCellAt(x, y)
            file<<cell.getAltitude()<<"/";
            file<<cell.getLiquidCount()<<"/";
            //file<<cell.getAltitude()<<"/";

        }
        file<<endl;
    }

    file.close();
}

AbstractField *FieldsIO::LoadFromFile(const std::string&)
{
    ifstream file;

    file.open(fileName);
    if (!file.is_open()) return;

    file.close();

    return nullptr;
}
