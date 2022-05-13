//
// main.cpp
// Created on 21/10/2018
//

#include <iostream>
#include <string>
#include <sstream>
#include "tcpserver.h"

#include "MediaObject.h"
#include "Photo.h"
#include "Video.h"
#include "Film.h"
#include "MediaGroup.h"
#include "MediaDatabase.h"

using namespace std;

#define ETAPE_11

int main(int argc, const char* argv[]) {   
    #ifdef ETAPE_1

    std::cout << "Hello brave new world" << std::endl;
    return 0;

    #endif

    #ifdef ETAPE_2_3

    string path = "myPath";
    string name = "myName";

    MediaObject * mc = new MediaObject(name, path);
    mc->showAttributes(cout);

    #endif

    #ifdef ETAPE_4

    Photo * p = new Photo("photoName", "photoPath", 200, 800);
    p->showAttributes(cout);

    cout << endl;

    Video * v = new Video("videoName", "videoPath", 666);
    v->showAttributes(cout);

    cout << endl;

    // Impossible de créer un objet MediaObject :
    // function "MediaObject::play" is a pure virtual function
    // car nous avons déclaré :
    // virtual void play() const = 0;

    // MediaObject * mc = new MediaObject("mediaName", "mediaPath");
    // mc->showAttributes(cout);

    #endif

    #ifdef ETAPE_5

    // Nous utilisons ici le polymorphisme caractéristique de l'orienté objet.
    // Cela est possible en particulier car nous avons déclaré la méthode
    // showAttributes comme virtual dans MediaObject, et que nous l'avons
    // redéfinie dans les sous-classes Photo et Vidéo.
    // Le tableau contient des pointeurs vers les objets pour utiliser le
    // principe de liaison tardive : la méthode appelée est celle du pointé,
    // pas du pointeur. 

    Photo * p1 = new Photo("photoName1", "photoPath1", 300, 1000);
    Photo * p2 = new Photo("photoName2", "photoPath2", 1080, 1920);
    Photo * p3 = new Photo();
    Video * v1 = new Video("videoName1", "videoPath1", 666);
    Video * v2 = new Video("videoName2", "videoPath2", 2048);
    Video * v3 = new Video();

    MediaObject * arr[6] = {v1, p1, v2, p2, v3, p3};

    for (MediaObject * elmt : arr) {
        elmt->showAttributes(cout);
        cout << endl;
    };

    #endif

    #ifdef ETAPE_6

    // Pour ne pas violer le principe d'encapsulation, nous faisons en sorte
    // de ne retourner que des copies des chapitres d'un Film, au lieu d'un
    // pointeur vers la variable d'instance du Film. Sans cela, un autre objet
    // aurait accès à cette variable privée et pourrait la modifier.

    Film * f1 = new Film("Titanic", "titanicPath", {300,400,500});
    Film * f2 = new Film("Matrix", "matrixPath", 1000, {300, 700});
    Film * f3 = new Film("film3", "film3Path", {111,222,333,444,555});
    Film * f4 = new Film();

    f1->showAttributes(cout);
    cout << endl;
    f2->showAttributes(cout);
    cout << endl;
    f3->showAttributes(cout);
    cout << endl;
    f4->showAttributes(cout);

    // Changing chapters for the Titanic film
    cout << "Changing chapters for Titanic to: [0, 1, 2, 3]" << endl;
    f1->setChapters({0,1,2,3});
    f1->showAttributes(cout);
    cout << endl;

    #endif

    #ifdef ETAPE_7

    // On utilise des smartpointers pour nous faciliter la tache et détruire
    // automatiquement les objets créés avec new.
    // Pour assurer la copie et l'indépendance des listes de chapitres, il faudrait
    // redéfinir l'opérateur de copie = et faire de la deep copy, c'est-à-dire 
    // ne copier que les champs des variables et non les pointeurs, sans quoi
    // deux Films copiés partageront la même liste de chapitres.

    Film * f1 = new Film("Titanic", "titanicPath", {300,400,500});
    Film * f2 = f1;

    f1->showAttributes(cout);
    unique_ptr<int[]> chaps1 = f1->getChapters();

    f2->showAttributes(cout);
    unique_ptr<int[]> chaps2 = f1->getChapters();

    delete f1;
    if (chaps1) {
        cout << "Chapters list 1 still exists!" << endl;
    } else {
        cout << "Chapters list 1 no longer exists!" << endl;
    }
 
    #endif

    #ifdef ETAPE_8_9

    // On a ici une liste de pointeurs d'objets pour utiliser la propriété de
    // liaison tardive. En Java, on n'a que des références vers les objets, 
    // qui sont comparables à des pointeurs.

    shared_ptr<Photo> p1 = shared_ptr<Photo>(new Photo("photoName1", "photoPath1", 300, 1000));
    shared_ptr<Photo> p2 = shared_ptr<Photo>(new Photo("photoName2", "photoPath2", 1080, 1920));
    shared_ptr<Photo> p3 = shared_ptr<Photo>(new Photo());
    shared_ptr<Video> v1 = shared_ptr<Video>(new Video("videoName1", "videoPath1", 666));
    shared_ptr<Video> v2 = shared_ptr<Video>(new Video("videoName2", "videoPath2", 2048));
    shared_ptr<Video> v3 = shared_ptr<Video>(new Video());
    shared_ptr<Film>  f1 = shared_ptr<Film>(new Film("Titanic", "titanicPath", {300,400,500}));
    shared_ptr<Film>  f2 = shared_ptr<Film>(new Film("Matrix", "matrixPath", 1000, {300, 700}));
    shared_ptr<Film>  f3 = shared_ptr<Film>(new Film("film3", "film3Path", {111,222,333,444,555}));
    shared_ptr<Film>  f4 = shared_ptr<Film>(new Film());

    MediaGroup * allGroup = new MediaGroup("myGroup", {v1, p1, v2, p2, v3, p3, f1, f2, f3, f4});
    MediaGroup * group1 = new MediaGroup("group1", {v1,p1,f1});
    MediaGroup * group2 = new MediaGroup("group2", {v1,p1,v2,p2,f1,f2,f3});

    allGroup->showAttributes(cout);
    cout << endl;
    group1->showAttributes(cout);
    cout << endl;
    group2->showAttributes(cout);
    cout << endl;

    delete allGroup;

    // Il reste tous les objets de group1 car ils sont toujours pointés
    group1->showAttributes(cout);
    cout << endl;

    delete group1;
    delete group2;

    #endif

    #ifdef ETAPE_10

    // Pour empêcher la création de classes avec new on peut rendre 'new' private
    // et faire en sorte que MediaDatabase soit friend des classes multimédia.

    shared_ptr<MediaDatabase> MediaDB = shared_ptr<MediaDatabase>(new MediaDatabase());

    MediaPtr p1 = MediaDB->addPhoto("photoName1", "photoPath1", 300, 1000);
    MediaPtr p2 = MediaDB->addPhoto("photoName2", "photoPath2", 1080, 1920);
    MediaPtr v1 = MediaDB->addVideo("videoName1", "videoPath1", 666);
    MediaPtr v2 = MediaDB->addVideo("videoName2", "videoPath2", 2048);
    MediaPtr  f1 = MediaDB->addFilm("Titanic", "titanicPath", {300,400,500});
    MediaPtr  f2 = MediaDB->addFilm("Matrix", "matrixPath", 1000, {300, 700});
    MediaPtr  f3 = MediaDB->addFilm("film3", "film3Path", {111,222,333,444,555});

    // Showing a few MediaObject
    MediaDB->searchShowMedia("photoName1", cout);
    cout << "\n";
    MediaDB->searchShowMedia("videoName1", cout);
    cout << "\n";
    MediaDB->searchShowMedia("Matrix", cout);
    cout << "\n";

    // Create a group and show its content
    MediaGroupPtr g1 = MediaDB->addGroup("group1", {p1, v1, f1});
    MediaDB->searchShowGroup("group1", cout);
    cout << "\n";

    // Erase the Titanic movie from the DB
    MediaDB->eraseMedia("Titanic");

    #endif

    #ifdef ETAPE_11

    shared_ptr<MediaDatabase> MediaDB = shared_ptr<MediaDatabase>(new MediaDatabase());

    MediaPtr p1 = MediaDB->addPhoto("Bird", "./sampleMedia/Photo", 180, 180);
    MediaPtr p2 = MediaDB->addPhoto("Cat", "./sampleMedia/Photo", 190, 190);
    MediaPtr p3 = MediaDB->addPhoto("Dog", "./sampleMedia/Photo", 150, 150);
    MediaPtr v1 = MediaDB->addVideo("Beach", "./sampleMedia/Video", 13);
    MediaPtr v2 = MediaDB->addVideo("Mountain", "salsaPath", 2048);
    MediaPtr v3 = MediaDB->addVideo("Ocean", "rockPath", 9000);
    MediaPtr  f1 = MediaDB->addFilm("Titanic", "titanicPath", {300,400,500});
    MediaPtr  f2 = MediaDB->addFilm("Matrix", "matrixPath", 1000, {300, 700});
    MediaPtr  f3 = MediaDB->addFilm("Jurassic_Park", "jurassicParkPath", {111,222,333,444,555});

    MediaGroupPtr photos = MediaDB->addGroup("Photos", {p1, p2, p3});
    MediaGroupPtr videos = MediaDB->addGroup("Videos", {v1, v2, v3});
    MediaGroupPtr films = MediaDB->addGroup("Films", {f1, f2, f3});
    MediaGroupPtr sampleMedia = MediaDB->addGroup("Samples", {p1, p2, p3, v1});

    const int PORT = 3331;

    // cree le TCPServer
    auto* server =
    new TCPServer( [&](string const& request, string& response) {

    // the request sent by the client to the server
    cout << "request: " << request << endl;

    // Turn request to a stringstream and extract the first word
    stringstream reqStream(request);
    string command;
    reqStream >> command;
    string arg1;

    stringstream respStream;

    if (command.compare("help") == 0) {
        response = "Try clicking on all the buttons ;)";
    } else if (command.compare("media") == 0) {
        if (reqStream >> arg1) {
            int search = MediaDB->searchShowMedia(arg1, respStream);
            if (search == -1) {
                response = "Media not found: " + arg1;
            } else {
                response = respStream.str();
            }
        } else {
            MediaDB->showMedia(respStream);
            response = "Available media: " + respStream.str();     
        }
    } else if (command.compare("play") == 0) {
        reqStream >> arg1;
        int search = MediaDB->searchPlayMedia(arg1);
        if (search == -1) {
            response = "Media not found: " + arg1;
        } else {
            response = "Playing media on server: " + arg1;
        }
    } else if (command.compare("hello") == 0) {
        response = "Hi, I'm the set-top box! You can ask me to search or play a media that is available :)";
    } else if (command.compare("group") == 0) {
        if (reqStream >> arg1) {
            int search = MediaDB->searchShowGroupNames(arg1, respStream);
            if (search == -1) {
                response = "Group not found: " + arg1;
            } else {
                response = respStream.str();
            }
        } else {
            MediaDB->showGroups(respStream);
            response = "Available groups: " + respStream.str();   
        }
    } else {
        response = "Unrecognized command: '" + request + "', type 'help' to get a list of commands. ";
    }

    // return false would close the connection with the client
    return true;

    });


    // lance la boucle infinie du serveur
    std::cout << "Starting Server on port " << PORT << std::endl;

    int status = server->run(PORT);

    // en cas d'erreur
    if (status < 0) {
        std::cerr << "Could not start Server on port " << PORT << std::endl;
        return 1;
    }

    #endif

    return 0;
}
