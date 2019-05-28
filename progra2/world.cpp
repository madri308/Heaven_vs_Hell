#include "world.h"
#include "string.h"
#include "jsonparser.h"
#include "iostream"
#include "doublelist.h"
#include "human.h"
#include <ctime>
#include <chrono>
#include "sstream"
#include "hell.h"
#include "node.h"
#include "avltree.h"

using namespace std;

World::World()
{
    //Agarra las listas y le mete los datos del json.
    JsonParser *m = new JsonParser(this->names,this->lastnames,this->jobs,this->religions,this->countries);
    this->peopleTree = new BinarySearchTree();
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
<<<<<<< HEAD
<<<<<<< HEAD
        int childrens = rand() % 9;      //CANTIDAD DE HIJOS RANDOM
=======
        size_t childrens = rand() % 9;      //CANTIDAD DE HIJOS RANDOM
>>>>>>> parent of efaaa3a... Merge branch 'master' of https://github.com/madri308/Heaven_vs_Hell
        //CREA EL HUMANO CON SUS DATOS
        Human *person = new Human(id,names[namePos],lastnames[namePos],countries[countriesPos][0],religions[religionPos],jobs[jobPos],childrens,dt);
        Node *humanNode = new Node(person);
        this->peolpe.add(humanNode);           //Mete el humano a la lista.
        this->peopleTree->insert(person);      //Mete el humano al arbol.
        //Se fija si existe un arbol de la familia.
<<<<<<< HEAD
        if(relative != nullptr){//SI EXISTE
<<<<<<< HEAD

            relative->data->family->insert(person);     //AGREGA LA PERSONA AL ARBOL FAMILIAR.

            person->family = relative->data->family;   //A LA PERSONA LE OTORGA LA FAMILIA COMO ATRIBUTO.

            int t = person->childCount;                     //t es el tope, la cantidad de hijos que necesita
            if(person->family->count < person->childCount){ //pero si hay muy pocas personas en el arbol
                t = person->family->count;                  //entoces establece y como la cantidad de personas ne el arbol
=======
        size_t childrens = rand() % 9;      //CANTIDAD DE HIJOS RANDOM
        //CREA EL HUMANO CON SUS DATOS
        Human *person = new Human(id,names[namePos],lastnames[namePos],countries[countriesPos][0],religions[religionPos],jobs[jobPos],childrens,dt);
        Node *humanNode = new Node(person);
        this->peolpe.add(humanNode);           //Mete el humano a la lista.
        this->peopleTree->insert(person);      //Mete el humano al arbol.
        //Se fija si existe un arbol de la familia.
        if(peolpe.getBySurnameAndCountrie(person->surname,person->country) != nullptr){//SI EXISTE
            //AGREGA A LA PERSONA AL ARBOL.
            peolpe.getBySurnameAndCountrie(person->surname,person->country)->data->family->insert(person);
            //A LA PERSONA LE OTORGA LA FAMILIA COMO ATRIBUTO.
            person->family = peolpe.getBySurnameAndCountrie(person->surname,person->country)->data->family;
            //AGARRA UNA PERSONA RANDOM DEL ARBOL Y LO SETEA COMO HIJO POR LA CANTIDAD DE HIJOS.
            for(size_t child = 0 ; child < person->childrens.size() ; child++){
                person[child] = person->family->getRandom();
                //Validar que esa persona random no sea le mismo o el papa o la mama.
>>>>>>> parent of efaaa3a... Merge branch 'master' of https://github.com/madri308/Heaven_vs_Hell
            }
=======
=======
        if(peolpe.getBySurnameAndCountrie(person->surname,person->country) != nullptr){//SI EXISTE
>>>>>>> parent of efaaa3a... Merge branch 'master' of https://github.com/madri308/Heaven_vs_Hell
            //AGREGA A LA PERSONA AL ARBOL.
            peolpe.getBySurnameAndCountrie(person->surname,person->country)->data->family->insert(person);
            //A LA PERSONA LE OTORGA LA FAMILIA COMO ATRIBUTO.
<<<<<<< HEAD
            person->family = relative->data->family;
>>>>>>> parent of 0544e3d... Merge branch 'master' of https://github.com/madri308/Heaven_vs_Hell
=======
            person->family = peolpe.getBySurnameAndCountrie(person->surname,person->country)->data->family;
>>>>>>> parent of efaaa3a... Merge branch 'master' of https://github.com/madri308/Heaven_vs_Hell
            //AGARRA UNA PERSONA RANDOM DEL ARBOL Y LO SETEA COMO HIJO POR LA CANTIDAD DE HIJOS.
            for(size_t child = 0 ; child < person->childrens.size() ; child++){
                person[child] = person->family->getRandom();
                //Validar que esa persona random no sea le mismo o el papa o la mama.
            }
        }else{  //SI NO EXISTE ARBOL DE LA FAMILIA
<<<<<<< HEAD
<<<<<<< HEAD
            AVLTree *fam = new AVLTree(person->surname+"-"+person->country);   //Entonces crea el arbol
            fam->count++;
            fam->insert(person);
=======
            AVLTree *fam = new AVLTree();   //Entonces crea el arbol
>>>>>>> parent of efaaa3a... Merge branch 'master' of https://github.com/madri308/Heaven_vs_Hell
=======
            AVLTree *fam = new AVLTree();   //Entonces crea el arbol
>>>>>>> parent of efaaa3a... Merge branch 'master' of https://github.com/madri308/Heaven_vs_Hell
            person->family = fam;           //Y lo setea como atributo.
        }
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
