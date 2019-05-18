#include "world.h"
#include "string.h"
#include "jsonparser.h"
#include "iostream"
#include "doublelist.h"
#include "human.h"
#include <ctime>
#include <chrono>

using namespace std;

World::World()
{
    //Agarra las listas y le mete los datos del json.
    JsonParser *m = new JsonParser(this->names,this->lastnames,this->jobs,this->religions,this->countries);
}

void World::generatePeople(int peopleQuan){
    for(int human = 0; human < peopleQuan ; human++){
        srand(time(NULL));
        int id = rand() % 9999999;
        while(this->peolpe.exist(id)){
            id = rand() % 9999999;
        }
        time_t now = time(0);
        char *dt = ctime(&now);
        int namePos = rand() % 1000;
        int religionPos = rand() % 10;
        int countriesPos = rand() % 100;
        int jobPos = rand() % 50;
        size_t childrens = rand() % 9;
        Human *person = new Human(human,names[namePos],lastnames[namePos],countries[countriesPos],religions[religionPos],jobs[jobPos],childrens,dt);
        this->peolpe.add(person);
        //Crear arbol avl,Splay con humanos del mismo apellido y pais que se determino.
    }
}
