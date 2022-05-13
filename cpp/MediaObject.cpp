#include "MediaObject.h"
#include <string>
using namespace std;

MediaObject::MediaObject(string _name, string _fileName) {
    name = _name;
    pathName = _fileName;
};

void MediaObject::setName(string n) {
    name = n;
};

string MediaObject::getName() const {
    return name;
};

void MediaObject::setPathName(string n) {
    pathName = n;
};

string MediaObject::getPathName() const {
    return pathName;
};

// Show the name and pathName attributes to stream.
void MediaObject::showAttributes(ostream& stream) const {
    stream
    << "name: " << getName() << "\n"
    << "pathName: " << getPathName() << "\n"
    << std::endl;
};






