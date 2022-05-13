/**
 * @file Video.h
 * @author remy.tang@telecom-paris.fr
 * @brief File that declares the Video class and associated methods.
 * @version 0.1
 * @date 2022-02-11
 */
#ifndef VIDEO_H
#define VIDEO_H

#include <string>
#include "stdlib.h"
#include "MediaObject.h"

/**
 * @brief Represents a Video with set length.
 */
class Video : public MediaObject {

    private:
        int length{};
    
    public:
        /**
         * @brief Construct a new empty Video object with null length.
         */
        inline Video() : MediaObject(), length(0) {};
        ~Video () {std::cout << "Vidéo détruite : " << getName() << std::endl;};
        
        /**
         * @brief Construct a new named Video object with null length.
         */
        inline Video(std::string name, std::string pathName) :
        MediaObject(name, pathName), length(0) {};

        /**
         * @brief Construct a new Video object with set length.
         */
        inline Video(std::string name, std::string pathName, int length) :
        MediaObject(name, pathName), length(length) {};

        inline void setLength(int len) {length = len;};
        inline int getLength() const {return length;};

        /**
         * @brief Outputs the Video characteristics:
         * name, pathName, length.
         * 
         * @param stream The output stream.
         */
        inline void showAttributes(std::ostream& stream) const override {
            // removed all \n and endl
            stream
            << "name: " << getName() << ", "
            << "pathName: " << getPathName() << ", "
            << "latitude: " << getLength() << ".";
        };
        // inline void showAttributes(std::ostream& stream) const override {
        //     stream
        //     << "name: " << getName() << "\n"
        //     << "pathName: " << getPathName() << "\n"
        //     << "latitude: " << getLength() << "\n"
        //     << std::endl;
        // };

        /**
         * @brief Plays the Video.
         */
        inline void play() const override {
            std::string command = "mpv " + getPathName() 
                                   + "/" + getName() + ".mp4 &";
            std::system(command.c_str());
        };
};

#endif