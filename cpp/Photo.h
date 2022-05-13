/**
 * @file Photo.h
 * @author remy.tang@telecom-paris.fr
 * @brief File that declares the Photo class and associated methods.
 * @version 0.1
 * @date 2022-02-11
 */
#ifndef PHOTO_H
#define PHOTO_H

#include <string>
#include <cstring>
#include "stdlib.h"
#include "MediaObject.h"

/**
 * @brief Represents a photo with set dimensions.
 */
class Photo : public MediaObject {

    private:
        /// The dimensions of the photo.
        int latitude{};
        int longitude{};
    
    public:
        /**
         * @brief Construct a new empty Photo object with null dimensions.
         */
        inline Photo(): MediaObject(), latitude(0), longitude(0) {};
        ~Photo () {std::cout << "Photo détruite : " << getName() << std::endl;};
        
        /**
         * @brief Construct a new Photo object with set parameters
         * and null dimensions.
         */
        inline Photo(std::string name, std::string pathName):
        MediaObject(name, pathName), latitude(0), longitude(0) {};

        /**
         * @brief Construct a new Photo object with set parameters.
         */
        inline Photo(std::string name, std::string pathName, int latitude, int longitude ):
        MediaObject(name, pathName), latitude(latitude), longitude(longitude) {};

        inline void setLatitude(int lat) {latitude = lat;};
        inline int getLatitude() const {return latitude;};

        inline void setLongitude(int longi) {longitude = longi;};
        inline int getLongitude() const {return longitude;};

        /**
         * @brief Outputs the Photo characteristics:
         * name, pathName, latitude, longitude.
         * 
         * @param stream The output stream.
         */
        inline void showAttributes(std::ostream& stream) const override {
            // removed all \n and endl
            stream
            << "name: " << getName() << ", "
            << "pathName: " << getPathName() << ", "
            << "latitude: " << getLatitude() << ", "
            << "longitude: " << getLongitude() << ".";
        };
        // inline void showAttributes(std::ostream& stream) const override {
        //     stream
        //     << "name: " << getName() << "\n"
        //     << "pathName: " << getPathName() << "\n"
        //     << "latitude: " << getLatitude() << "\n"
        //     << "longitude: " << getLongitude() << "\n"
        //     << std::endl;
        // };
        
        /**
         * @brief Displays the photo.
         */
        inline void play() const override {
            std::string command = "imagej " + getPathName() + "/" + getName() + ".jpg &";
            std::system(command.c_str());
        };
        
};

#endif