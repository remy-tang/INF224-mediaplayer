#include "Film.h"
#include <memory>
using namespace std;

Film::Film(string name, string pathName, initializer_list<int> chapList) {
    this->setName(name);
    this->setPathName(pathName);

    unsigned int k = 0;
    unsigned int n = sizeof(chapList);
    unsigned int len = 0;

    chapters = std::unique_ptr<int[]>(new int[n]);
    for (int chapter : chapList) {
        chapters[k] = chapter;
        len += chapter;
        k++;
    };
    setLength(len);
    setNumberOfChapters(k);
};

Film::Film(string name, string pathName, int length,
            initializer_list<int> chapList) : Video(name, pathName, length) {
    unsigned int k = 0;
    unsigned int n = chapList.size();

    chapters = std::unique_ptr<int[]>(new int[n]);
    for (int chapter : chapList) {
        chapters[k] = chapter;
        k++;
    };
    setNumberOfChapters(k);
};

void Film::setChapters(initializer_list<int> chapList) {
    // When using int arrays only
    // if (chapters) {
    //     delete chapters;
    // };
    unsigned int k = 0;
    unsigned int n = chapList.size();
    chapters = std::unique_ptr<int[]>(new int[n]);
    for (int chapter : chapList) {
        chapters[k] = chapter;
        k++;
    };
    numberOfChapters = k;
};

unique_ptr<int[]> Film::getChapters() const {
    unique_ptr<int[]> chaptersCopy (new int[numberOfChapters]);
    
    for (unsigned int k = 0; k<numberOfChapters; k++) {
        chaptersCopy[k] = chapters[k];
        k++;
    };

    return chaptersCopy;
};