/**
 * @file MediaDatabase.h
 * @author remy.tang@telecom-paris.fr
 * @brief File that declares the MediaDatabase class and associated methods.
 * @version 0.1
 * @date 2022-02-11
 */

#ifndef MEDIADATABASE_H
#define MEDIADATABASE_H

#include <map>
#include <string>
#include "MediaObject.h"
#include "Photo.h"
#include "Video.h"
#include "Film.h"
#include "MediaGroup.h"

/**
 * @brief Represents a collection of MediaObject and MediaGroup.
 */

using MediaPtr = std::shared_ptr<MediaObject>;
using MediaGroupPtr = std::shared_ptr<MediaGroup>;

class MediaDatabase : public std::map<std::string, MediaPtr>, public std::map<std::string, MediaGroupPtr> {

    private:
        std::map<std::string, MediaPtr> mediaCollection;
        std::map<std::string, MediaGroupPtr> mediaGroupCollection;

    public:
        /**
         * @brief Construct a new Media Database object.
         */
        inline MediaDatabase() {};

        ~MediaDatabase() {std::cout << "MediaDatabase détruite "<< std::endl;};

        /**
         * @brief Create a named Photo and add it to the collection.
         * 
         * @return A pointer to the newly created Photo.
         */
        MediaPtr addPhoto(std::string name, std::string pathName);

        /**
         * @brief Create a named and sized Photo and add it to the collection.
         * 
         * @return A pointer to the newly created Photo.
         */
        MediaPtr addPhoto(std::string name, std::string pathName, int latitude, int longitude);

        /**
         * @brief Create a named Video and add it to the collection.
         * 
         * @return A pointer to the newly created Video.
         */
        MediaPtr addVideo(std::string name, std::string pathName);

        /**
         * @brief Create a named Video with length and add it to the collection.
         * 
         * @return A pointer to the newly created Video.
         */
        MediaPtr addVideo(std::string name, std::string pathName, int length);

        /**
         * @brief Create a named Film and add it to the collection.
         * 
         * @return A pointer to the newly created Film.
         */
        MediaPtr addFilm(std::string name, std::string pathName);

        /**
         * @brief Create a named Film with chapters and add it to the collection.
         * 
         * @return A pointer to the newly created Film.
         */
        MediaPtr addFilm(std::string name, std::string pathName, std::initializer_list<int> chapList);

        /**
         * @brief Create a named Film with chapters and length and add it to the collection.
         * 
         * @return A pointer to the newly created Film.
         */
        MediaPtr addFilm(std::string name, std::string pathName, int length, std::initializer_list<int> chapList);

        /**
         * @brief Construct a new MediaGroup object from a structured list of MediaObject.,
         * and add it to the collection of groups.
         */
        MediaGroupPtr addGroup(std::string groupName, std::list<MediaPtr> group);
        
        /**
         * @brief Construct a new MediaGroup object from a list of MediaObject,
         * and add it to the collection of groups.
         */
        MediaGroupPtr addGroup(std::string groupName, std::initializer_list<MediaPtr> mediaList);

        /**
         * @brief Erase a MediaObject by its name.
         */
        int eraseMedia(std::string name);

        /**
         * @brief Erase a MediaGroup by its name.
         */
        int eraseGroup(std::string groupName);

        /**
         * @brief Search a MediaObject by its name and show its attributes.
         */
        int searchShowMedia(std::string fileName, std::ostream& stream);

        /**
         * @brief Search a MediaGroup by its name and show its attributes.
         */
        int searchShowGroup(std::string groupName, std::ostream& stream);

        /**
         * @brief Search a MediaGroup by its name and show its elements names.
         */
        int searchShowGroupNames(std::string groupName, std::ostream& stream);

        /**
         * @brief Search a MediaObject by its name and play it.
         */
        int searchPlayMedia(std::string fileName);

        /**
         * @brief Shows the available media.
         */
        void showMedia(std::ostream& stream);

        /**
         * @brief Shows the available groups.
         */
        void showGroups(std::ostream& stream);

};

#endif