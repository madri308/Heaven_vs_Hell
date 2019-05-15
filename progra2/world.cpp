#include "world.h"
#include "string.h"
#include "jsonparser.h"
#include "iostream"
#include "doublelist.h"
#include "human.h"

using namespace std;

World::World()
{
    //Agarra las listas y le mete los datos del json.
    JsonParser *m = new JsonParser(this->names,this->lastnames,this->religions,this->countries,this->jobs);

    this->generatePeople();    //Genera a las 10000 personas.
}

void World::generatePeople(){
    for(int human = 0; human < 9999 ; human++){
        int namePos = rand() % 1000;
        int religionPos = rand() % 10;
        int countriesPos = rand() % 100;
        int jobPos = rand() % 50;
        int childrens = rand() % 8;
        Human *person = new Human(human,names[namePos],lastnames[namePos],countries[countriesPos],religions[religionPos],childrens);
        this->peolpe.add(person);
        //Crear arbol avl,Splay con humanos del mismo apellido y pais que se determino.
    }
}
