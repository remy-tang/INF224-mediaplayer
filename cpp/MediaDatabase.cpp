#include <map>
#include <string>
#include "MediaObject.h"
#include "Photo.h"
#include "Video.h"
#include "Film.h"
#include "MediaGroup.h"
#include "MediaDatabase.h"

using namespace std;
using MediaPtr = shared_ptr<MediaObject>;
using MediaGroupPtr = shared_ptr<MediaGroup>;

MediaPtr MediaDatabase::addPhoto(string name, string pathName) {
    MediaPtr photo = MediaPtr(new Photo(name, pathName));
    mediaCollection[name] = photo;
    return mediaCollection[name];
};

MediaPtr MediaDatabase::addPhoto(string name, string pathName, int latitude, int longitude) {
    MediaPtr photo = MediaPtr(new Photo(name, pathName, latitude, longitude));
    mediaCollection[name] = photo;
    return mediaCollection[name];
};

MediaPtr MediaDatabase::addVideo(string name, string pathName) {
    MediaPtr video = MediaPtr(new Video(name, pathName));
    mediaCollection[name] = video;
    return mediaCollection[name];
};

MediaPtr MediaDatabase::addVideo(string name, string pathName, int length) {
    MediaPtr video = MediaPtr(new Video(name, pathName, length));
    mediaCollection[name] = video;
    return mediaCollection[name];
};

MediaPtr MediaDatabase::addFilm(string name, string pathName, initializer_list<int> chapList) {
    MediaPtr film = MediaPtr(new Film(name, pathName, chapList));
    mediaCollection[name] = film;
    return mediaCollection[name];
};

MediaPtr MediaDatabase::addFilm(string name, string pathName, int length, initializer_list<int> chapList) {
    MediaPtr film = MediaPtr(new Film(name, pathName, length, chapList));
    mediaCollection[name] = film;
    return mediaCollection[name];
};
       
shared_ptr<MediaGroup> MediaDatabase::addGroup(string groupName, list<MediaPtr> group) {
    MediaGroupPtr newGroup = MediaGroupPtr(new MediaGroup(groupName, group));
    mediaGroupCollection[groupName] = newGroup;
    return mediaGroupCollection[groupName];
};
        
shared_ptr<MediaGroup> MediaDatabase::addGroup(string groupName, initializer_list<MediaPtr> mediaList) {
    MediaGroupPtr newGroup = MediaGroupPtr(new MediaGroup(groupName, mediaList));
    mediaGroupCollection[groupName] = newGroup;
    return mediaGroupCollection[groupName];
};

int MediaDatabase::eraseMedia(std::string name){
    // Delete the MediaObject from all groups
    for (map<string, MediaGroupPtr>::iterator it=mediaGroupCollection.begin(); it!=mediaGroupCollection.end(); ++it) {
        it->second->eraseMediaFromGroup(name);
    };

    map<string, MediaPtr>::iterator it = mediaCollection.find(name);
    if (it != mediaCollection.end()) {
        mediaCollection.erase(it);
        return 0;
    } else {
        return -1;
    }
};

int MediaDatabase::eraseGroup(std::string groupName){
    map<string, MediaGroupPtr>::iterator it = mediaGroupCollection.find(groupName);
    if (it != mediaGroupCollection.end()) {
        mediaGroupCollection.erase(it);
        return 0;
    } else {
        return -1;
    }
};

int MediaDatabase::searchShowMedia(string fileName, std::ostream& stream) {
    map<string, MediaPtr>::iterator it = mediaCollection.find(fileName);
    if (it != mediaCollection.end()) {
        it->second->showAttributes(stream);
        return 0;
    } else {
        return -1;
    }
};

int MediaDatabase::searchShowGroup(string groupName, std::ostream& stream) {
    map<string, MediaGroupPtr>::iterator it = mediaGroupCollection.find(groupName);
    if (it != mediaGroupCollection.end()) {
        it->second->showAttributes(stream);
        return 0;
    } else {
        return -1;
    }
};

int MediaDatabase::searchShowGroupNames(string groupName, std::ostream& stream) {
    map<string, MediaGroupPtr>::iterator it = mediaGroupCollection.find(groupName);
    if (it != mediaGroupCollection.end()) {
        it->second->showNames(stream);
        return 0;
    } else {
        return -1;
    }
};

int MediaDatabase::searchPlayMedia(string fileName) {
    map<string, MediaPtr>::iterator it = mediaCollection.find(fileName);
    if (it != mediaCollection.end()) {
        it->second->play();
        return 0;
    } else {
        return -1;
    }
};

void MediaDatabase::showMedia(std::ostream& stream) {
    for (std::map<string, MediaPtr>::iterator it=mediaCollection.begin(); it!=mediaCollection.end(); ++it)
        stream << "'" << it->second->getName() << "' ";
};

void MediaDatabase::showGroups(std::ostream& stream) {
    for (std::map<string, MediaGroupPtr>::iterator it=mediaGroupCollection.begin(); it!=mediaGroupCollection.end(); ++it)
        stream << "'" << it->second->getName() << "' ";
};