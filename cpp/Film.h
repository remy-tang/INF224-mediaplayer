/**
 * @file Film.h
 * @author remy.tang@telecom-paris.fr
 * @brief File that declares the Film class and associated methods.
 * @version 0.1
 * @date 2022-02-11
 */

#ifndef FILM_H
#define FILM_H

#include "Video.h"
#include <cstdarg>
#include <memory>

/**
 * @brief Reprensents a Film, which a special type of video.
 */
class Film : public Video {

    private:
        std::shared_ptr<int[]> chapters{}; ///< Contains the lengths for Film chapters.
        unsigned int numberOfChapters{};

    public:
        inline Film() : Video(), chapters(nullptr), numberOfChapters(0) {};
        ~Film() {std::cout << "Film détruit : " << getName() << std::endl;};

        /**
         * @brief Construct a new Film object, and compute the total length
         * using the lenghts of chapters.
         * 
         * @param chapList The list of timestamps for Film chapters.
         */
        Film(std::string name, std::string pathName,
             std::initializer_list<int> chapList);

        /**
         * @brief Construct a new Film object, with a specified total length.
         * 
         * @param chapList The list of lengths for Film chapters.
         */
        Film(std::string name, std::string pathName, int length,
             std::initializer_list<int> chapList);
        
        /**
         * @brief Get the list of chapter lengths.
         */
        std::unique_ptr<int[]> getChapters() const;

        /**
         * @brief Update the list of chapters lenghts.
         * 
         * @param chapList The new list of timestamps for Film chapters.
         */
        void setChapters(std::initializer_list<int> chapList);

        /**
         * @brief Set the number of chapters for this Film.
         */
        void setNumberOfChapters(int n) {numberOfChapters = n;};

        /**
         * @brief Get the number of chapters for this Film.
         */
        inline int getNumberOfChapters() const {return numberOfChapters;};

        /**
         * @brief Outputs the Film characteristics: 
         * name, pathName, each chapter's duration.
         * 
         * @param stream The output stream.  
         */
        inline void showAttributes(std::ostream& stream) const override {
            // removed all \n and endl
            stream
            << "name: " << getName() << ", "
            << "pathName: " << getPathName() << ", "
            << "chapters duration: ";
            for (unsigned int k = 0; k<numberOfChapters; k++) {
                stream << "chapter " << k << ": " << chapters[k] << "; ";
            };
        };
        // inline void showAttributes(std::ostream& stream) const override {
        //     stream
        //     << "name: " << getName() << "\n"
        //     << "pathName: " << getPathName() << "\n"
        //     << "chapters duration: " << "\n";
        //     for (unsigned int k = 0; k<numberOfChapters; k++) {
        //         stream << "chapter " << k << ": " << chapters[k] << "\n";
        //     };
        //     stream << std::endl;
        // };

        /**
         * @brief Plays the Film.
         */
        inline void play() const override {
            std::string command = "mpv " + getPathName() + "/" + getName() + ".mp4 &";
            std::system(command.c_str());
        };

};


#endif