/**
 * @file MediaObject.h
 * @author remy.tang@telecom-paris.fr
 * @brief File that declares the MediaObject class and associated methods.
 * @version 0.1
 * @date 2022-02-11
 */
#ifndef MEDIACLASS_H
#define MEDIACLASS_H

#include <string>
#include <iostream>
#include <ostream>

/**
 * @brief Base class for all Media objects.
 */
class MediaObject {

    private:
        std::string name{};
        std::string pathName{};

    public:
        MediaObject() : name("defaultName"), pathName("defaultPathName") {};

        MediaObject(std::string name, std::string fileName);

        virtual ~MediaObject() {std::cout << "Quelqu'un a détruit " << name << std::endl;};

        void setName(std::string name);
        std::string getName() const;

        void setPathName(std::string name);
        std::string getPathName() const;

        /**
         * @brief Allows to output the MediaObject characteristics
         * into a stream. Must be implemented by the sub-classes.
         * 
         * @param stream The output stream. 
         */
        virtual void showAttributes(std::ostream& stream) const=0;

        /**
         * @brief Plays the MediaObject. 
         * Must be implemented by the sub-classes.
         */
        virtual void play() const = 0;

};

#endif