#include "hell.h"
#include "string"
#include "iostream"
#include "demon.h"
Hell::Hell()
{
    QString demonInfo[7][4] = {
        {"Lucifer","Orgullo","Lucifer era el ángel más brillante, quien se rebeló contra Dios y fue expulsado del paraíso para convertirse en Satán o Satanás.",":/new/prefix1/lucifer.jpg"},
        {"Belcebú","Envidia","Belcebú en sus formas alegóricas toma a veces una apariencia colosal; de rostro hinchado, coronado con una cinta de fuego, cornudo negro y amenazante, peludo y con alas de murciélago.",":/new/prefix1/Belcebu.jpg",},
        {"Satán","Ira","“Satanás” o “Satán” se utilizan en general para designar al Diablo después de la caída en tanto que “Lucifer” se usa generalmente para referirse al Diablo en su esplendor primigenio y previo a la caída.",":/new/prefix1/Satan.jpg"},
        {"Abadón","Pereza","Abadón o Abaddon, es el jefe destructor de los demonios de la séptima jerarquía.",":/new/prefix1/Abbadon.jpg"},
        {"Mammón","Codicia","Es el demonio ante el cual se arrodillan todos aquellos esclavos del dinero que habitan en el mundo consumista de la actualidad.",":/new/prefix1/Mammón.jpg"},
        {"Belfegor","Glotoneria","Él es el demonio que encarna el vicio de la pereza y todas las conductas que de ella nacen. De ese modo, Belfegor tienta a los hombres",":/new/prefix1/Belfegor.jpg"},
        {"Asmodeo","Lujuria","Asmodeo es descrito como una entidad que posee tres rostros, uno de esos rostro y su torso son de un humano, además de que cabalga un dragón portando una lanza mientras sus otros rostros son de cordero y de toro.",":/new/prefix1/Asmodeo.jpg"}};

    for(int d = 0 ; d < 7 ; d++){
        Demon *newDemon = new Demon(demonInfo[d][0],demonInfo[d][1],demonInfo[d][2],demonInfo[d][3],d);
        this->demons[d] = newDemon;
    }
}

