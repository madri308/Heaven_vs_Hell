#include "demon.h"
#include <fstream>
#include <QDateTime>
#include <QFile>

Demon::Demon(QString name, QString sin, QString desc, QString image,int d)
{
    this->name = name;
    this->sin = sin;
    this->desc = desc;
    this->image = image;
    this->n = d;
}

Demon::Demon(){}

void Demon::condemn(DoubleList people)
{
    int quant = people.quantity;
    int percentage = quant * 5 / 100;
    DoubleList copy = people; //Copia de la lista de personas para poder modificarla y no perder el orden original, lo uso para ordenarla de mayor a menor
    Node *tmp = copy.first;
    QDateTime dateAndTime = QDateTime::currentDateTime();
    QString dateString = dateAndTime.toString("yyy:MM:dd hh:mm:ss");
    QString filename = dateString + ".txt";
    QFile file (filename);

    while(tmp != nullptr)
    {
        Node *tmp2 = tmp->next;
        while (tmp2 != nullptr) {
            if(this->name == "Lucifer") //SI ES LUCIFER COMPARO LOS PECADOS DE IRA
            {
                int difference = stoi(tmp->data->sins[0][1]) - stoi(tmp->data->goodDeeds[0][1]); //RESTA DE LOS PECADOS DE IRA Y DE CALMA
                int difference2 = stoi(tmp2->data->sins[0][1]) - stoi(tmp2->data->goodDeeds[0][1]); //RESTA DEL NODO A COMPARAR

                if(difference2 > difference)
                {
                    Node *tmp3 = tmp2;
                    tmp2 = tmp;
                    tmp3 = tmp;
                }
            }
            else if (this->name == "Belcebú")
            {
                int difference = stoi(tmp->data->sins[1][1]) - stoi(tmp->data->goodDeeds[1][1]);
                int difference2 = stoi(tmp2->data->sins[1][1]) - stoi(tmp2->data->goodDeeds[1][1]);

                if (difference2 > difference)
                {
                    Node *tmp3 = tmp2;
                    tmp2 = tmp;
                    tmp3 = tmp;
                }
            }
            else if (this->name == "Satán")
            {
                int difference = stoi(tmp->data->sins[2][1]) - stoi(tmp->data->goodDeeds[1][1]);
                int difference2 = stoi(tmp2->data->sins[2][1]) - stoi(tmp2->data->goodDeeds[1][1]);

                if (difference2 > difference)
                {
                    Node *tmp3 = tmp2;
                    tmp2 = tmp;
                    tmp3 = tmp;
                }
            }
            else if (this->name == "Abadón")
            {
                int difference = stoi(tmp->data->sins[3][1]) - stoi(tmp->data->goodDeeds[1][1]);
                int difference2 = stoi(tmp2->data->sins[3][1]) - stoi(tmp2->data->goodDeeds[1][1]);

                if (difference2 > difference)
                {
                    Node *tmp3 = tmp2;
                    tmp2 = tmp;
                    tmp3 = tmp;
                }
            }
            else if (this->name == "Mammón")
            {
                int difference = stoi(tmp->data->sins[4][1]) - stoi(tmp->data->goodDeeds[1][1]);
                int difference2 = stoi(tmp2->data->sins[4][1]) - stoi(tmp2->data->goodDeeds[1][1]);

                if (difference2 > difference)
                {
                    Node *tmp3 = tmp2;
                    tmp2 = tmp;
                    tmp3 = tmp;
                }
            }
            else if(this->name == "Belfegor")
            {
                int difference = stoi(tmp->data->sins[5][1]) - stoi(tmp->data->goodDeeds[1][1]);
                int difference2 = stoi(tmp2->data->sins[5][1]) - stoi(tmp2->data->goodDeeds[1][1]);

                if (difference2 > difference)
                {
                    Node *tmp3 = tmp2;
                    tmp2 = tmp;
                    tmp3 = tmp;
                }
            }
            else if (this->name == "Asmodeo")
            {
                int difference = stoi(tmp->data->sins[6][1]) - stoi(tmp->data->goodDeeds[1][1]);
                int difference2 = stoi(tmp2->data->sins[6][1]) - stoi(tmp2->data->goodDeeds[1][1]);

                if (difference2 > difference)
                {
                    Node *tmp3 = tmp2;
                    tmp2 = tmp;
                    tmp3 = tmp;
                }
            }

        }

        tmp = tmp->next;
    }

    tmp = copy.first;

    for (int i= 0; i < percentage; i++)
    {

    }
}

void Demon::insertToHeap(AVLTree *tree)
{
    tree->getSins(this->n,tree->root);
    this->heap->insertKey(tree);
}
