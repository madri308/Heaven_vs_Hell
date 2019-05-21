#include "world.h"
#include "string.h"
#include "jsonparser.h"
#include "iostream"
#include "doublelist.h"
#include "human.h"
#include <ctime>
#include <chrono>
#include "sstream"
#include "binarysearchtree.h"

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
        Human *person = new Human(id,names[namePos],lastnames[namePos],countries[countriesPos][0],religions[religionPos],jobs[jobPos],childrens,dt);
        this->peolpe.add(person);           //Mete el humano a la lista
        /*//Se fija si existe un arbol de la familia.
        if(peolpe.getBySurnameAndCountrie(person->surname,person->country) != nullptr){//SI EXISTE
            //AGREGA A LA PERSONA AL ARBOL.
            peolpe.getBySurnameAndCountrie(person->surname,person->country)->data->family->insert(person);
            //A LA PERSONA LE OTORGA LA FAMILIA COMO ATRIBUTO.
            person->family = peolpe.getBySurnameAndCountrie(person->surname,person->country)->data->family;
            //AGARRA UNA PERSONA RANDOM DEL ARBOL Y LO SETEA COMO HIJO POR LA CANTIDAD DE HIJOS.
            for(size_t child = 0 ; child < person->childrens.size() ; child++){
                //person[child] = person->family->getRandom();
            }
        }else{  //SI NO EXISTE ARBOL DE LA FAMILIA
            BinarySearchTree *fam = new BinarySearchTree();   //Entonces crea el arbol
            person->family = fam;           //Y lo setea como atributo.
        }*/
    }
}

string* World::top10SinList()
{
    string Slist[10];
    for(int c = 0 ; c < 10 ; c++){
        for(int s = c+1; s<100;s++){
            int cant1,cant2;
            std::istringstream iss1 (this->countries[c][1]);
            std::istringstream iss2 (this->countries[s][1]);
            iss1 >> cant1;
            iss2 >> cant2;
            if(cant1<cant2){
                string temp1 = this->countries[c][1];
                string temp2 = this->countries[c][0];
                this->countries[c][1] = this->countries[s][1];
                this->countries[c][0] = this->countries[s][0];
                this->countries[s][1] = temp1;
                this->countries[s][0] = temp2;
            }
        }
        Slist[c] = this->countries[c][0];
        cout<<Slist[c]+" "+this->countries[c][1]<<endl;
    }
    return Slist;
}
