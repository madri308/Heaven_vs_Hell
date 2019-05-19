#include "world.h"
#include "string.h"
#include "jsonparser.h"
#include "iostream"
#include "doublelist.h"
#include "human.h"
#include <ctime>
#include <chrono>
#include "avltree.h"

using namespace std;

World::World()
{
    //Agarra las listas y le mete los datos del json.
    JsonParser *m = new JsonParser(this->names,this->lastnames,this->jobs,this->religions,this->countries);
}

void World::generatePeople(int peopleQuan){
    srand(time(NULL));
    //CREA LA CANTIDAD DE HUMANOS DEPENDIENDO DEL PARAMETRO
    for(int human = 0; human < peopleQuan ; human++){
        int id = rand() % 9999999;          //ID RANDOM
        while(this->peolpe.exist(id)){      //Si el id existe
            id = rand() % 9999999;          //genera otro hasta qu eno exista
        }
        //Saca fecha y hora de nacimiento
        time_t now = time(0);
        char *dt = ctime(&now);
        //Saca los datos normales
        int namePos = rand() % 1000;        //NOMBRE RANDOM
        int religionPos = rand() % 10;      //RELGION RANDOM
        int countriesPos = rand() % 100;    //PAIS RANDOM
        int jobPos = rand() % 50;           //TRABAJO RANDOM
        size_t childrens = rand() % 9;      //CANTIDAD DE HIJOS RANDOM
        //CREA EL HUMANO CON SUS DATOS
        Human *person = new Human(id,names[namePos],lastnames[namePos],countries[countriesPos],religions[religionPos],jobs[jobPos],childrens,dt);
        this->peolpe.add(person);           //Mete el humano a la lista
        //Se fija si existe un arbol de la familia.
        /*
        if(peolpe.getBySurnameAndCountrie(person->surname,person->country) != nullptr){//SI EXISTE
            //AGREGA A LA PERSONA AL ARBOL.
            peolpe.getBySurnameAndCountrie(person->surname,person->country)->data->family->add(person);
            //A LA PERSONA LE OTORGA LA FAMILIA COMO ATRIBUTO.
            person->family = peolpe.getBySurnameAndCountrie(person->surname,person->country)->data->family;
            //AGARRA UNA PERSONA RANDOM DEL ARBOL Y LO SETEA COMO HIJO POR LA CANTIDAD DE HIJOS.
            for(size_t child = 0 ; child < person->childrens.size() ; child++){
                person[child] = person->family->getRandom();
            }
        }else{//SI NO EXISTE ARBOL DE LA FAMILIA
            AVLTree *fam = new AVLTree();   //Entonces crea el arbol
            person->family = fam;           //Y lo setea como atributo.
        }*/
    }
}
