/**
 * @file MediaGroup.h
 * @author remy.tang@telecom-paris.fr
 * @brief File that declares the MediaGroup class and associated methods.
 * @version 0.1
 * @date 2022-02-11
 */
#ifndef MEDIAGROUP_H
#define MEDIAGROUP_H

#include <list>
#include <string>
#include "MediaObject.h"

/**
 * @brief Represents a collection of MediaObject.
 */

using MediaPtr = std::shared_ptr<MediaObject>;

class MediaGroup : std::list<MediaPtr> {

    private:
        std::string groupName{}; 
        std::list<MediaPtr> group{}; 

    public:
        /**
         * @brief Construct a new empty MediaGroup object.
         */
        inline MediaGroup() : groupName("defaultGroupName") {};

        ~MediaGroup() {std::cout << "MediaGroup: " << groupName << " détruit "<< std::endl;};

        /**
         * @brief Construct a new MediaGroup object from a structured list of MediaObject.
         */
        inline MediaGroup(std::string groupName, std::list<MediaPtr> group) :
        groupName(groupName), group(group) {};

        /**
         * @brief Construct a new MediaGroup object from a list of MediaObject.
         */
        inline MediaGroup(std::string groupName, std::initializer_list<MediaPtr> mediaList) :
        groupName(groupName) {
            for (MediaPtr media : mediaList) {
                group.push_back(media);
            };
        };

        /**
         * @brief Get the MediaGroup name.
         */
        inline std::string getName() {return groupName;};

        /**
         * @brief Erase a MediaObject from the MediaGroup by its name.
         */
        inline void eraseMediaFromGroup(std::string name) {
            for (list<MediaPtr>::iterator it = group.begin(); it != group.end(); ) {
                if (name.compare((*it)->getName()) == 0) {
                    it = group.erase(it);
                } else {
                    ++it;
                };
            };
        };

        /**
         * @brief Displays the attributes of all MediaObject in the collection.
         * 
         * @param stream The output stream.
         */
        inline void showAttributes(std::ostream& stream) {
            stream << groupName << " group contents: ";

            std::list<MediaPtr>::iterator it;
            for (it = group.begin(); it != group.end(); ++it) {
                (*it)->showAttributes(stream);
            };
        };

        /**
         * @brief Displays the names of all MediaObject in the collection.
         * 
         * @param stream The output stream.
         */
        inline void showNames(std::ostream& stream) {
            stream << groupName << " group contents: ";

            std::list<MediaPtr>::iterator it;
            for (it = group.begin(); it != group.end(); ++it) {
                stream << "'" << (*it)->getName() <<"' ";
            };
        };
};

#endif