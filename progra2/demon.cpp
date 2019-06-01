#include "demon.h"
#include <fstream>
#include <QDateTime>
#include <QFile>
#include <QTextStream>
#include <vector>
#include <iostream>
#include "src/SmtpMime"

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
    vector<Node*> copy(quant);
    Node *tmp = people.first;

    QDateTime dateAndTime = QDateTime::currentDateTime();
    QString dateString = dateAndTime.toString("yyyy:MM:dd");
    QString yearMonthDay = dateAndTime.toString("yyyy:MM:dd");
    QString filename = this->name+"Log" + QString::number(this->count);
    QFile file ("C:/Users/Sebas Villanueva/Documents/GitHub/Heaven_vs_Hell/" + filename +".txt");
    QTextStream out(&file);
    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
        cout << "verga" << endl;
        return;
    }
    file.flush();
    file.close();

    for(int i = 0; i < quant; i++)
    {
        copy[i] = tmp;
        //cout << copy[i]->data->name << endl;
        tmp = tmp->next;
    }

    if (this->name == "Lucifer")
    {
        for(int c = 0; c < quant; c++)
        {
            for(int s = c+1; s < quant; s++)
            {
                int difference = stoi(copy[c]->data->sins[6][1]) - stoi(copy[c]->data->goodDeeds[6][1]);
                int difference2 = stoi(copy[s]->data->sins[6][1]) - stoi(copy[s]->data->goodDeeds[6][1]);

                if (difference2 > difference)
                {
                    Node *tmp = copy[c];
                    copy[c] = copy[s];
                    copy[s] = tmp;
                }
            }
        }
    }
    else if (this->name == "Belcebú")
    {
        for(int c = 0; c < quant; c++)
        {
            for(int s = c+1; s < quant; s++)
            {
                int difference = stoi(copy[c]->data->sins[5][1]) - stoi(copy[c]->data->goodDeeds[5][1]);
                int difference2 = stoi(copy[s]->data->sins[5][1]) - stoi(copy[s]->data->goodDeeds[5][1]);

                if (difference2 > difference)
                {
                    Node *tmp = copy[c];
                    copy[c] = copy[s];
                    copy[s] = tmp;
                }
            }
        }
    }
    else if (this->name == "Satán")
    {
        for(int c = 0; c < quant; c++)
        {
            for(int s = c+1; s < quant; s++)
            {
                int difference = stoi(copy[c]->data->sins[4][1]) - stoi(copy[c]->data->goodDeeds[4][1]);
                int difference2 = stoi(copy[s]->data->sins[4][1]) - stoi(copy[s]->data->goodDeeds[4][1]);

                if (difference2 > difference)
                {
                    Node *tmp = copy[c];
                    copy[c] = copy[s];
                    copy[s] = tmp;
                }
            }
        }
    }
    else if (this->name == "Abadón")
    {
        for(int c = 0; c < quant; c++)
        {
            for(int s = c+1; s < quant; s++)
            {
                int difference = stoi(copy[c]->data->sins[3][1]) - stoi(copy[c]->data->goodDeeds[3][1]);
                int difference2 = stoi(copy[s]->data->sins[3][1]) - stoi(copy[s]->data->goodDeeds[3][1]);

                if (difference2 > difference)
                {
                    Node *tmp = copy[c];
                    copy[c] = copy[s];
                    copy[s] = tmp;
                }
            }
        }
    }
    else if (this->name == "Mammón")
    {
        for(int c = 0; c < quant; c++)
        {
            for(int s = c+1; s < quant; s++)
            {
                int difference = stoi(copy[c]->data->sins[2][1]) - stoi(copy[c]->data->goodDeeds[2][1]);
                int difference2 = stoi(copy[s]->data->sins[2][1]) - stoi(copy[s]->data->goodDeeds[2][1]);

                if (difference2 > difference)
                {
                    Node *tmp = copy[c];
                    copy[c] = copy[s];
                    copy[s] = tmp;
                }
            }
        }
    }
    else if (this->name == "Belfegor")
    {
        for(int c = 0; c < quant; c++)
        {
            for(int s = c+1; s < quant; s++)
            {
                int difference = stoi(copy[c]->data->sins[1][1]) - stoi(copy[c]->data->goodDeeds[1][1]);
                int difference2 = stoi(copy[s]->data->sins[1][1]) - stoi(copy[s]->data->goodDeeds[1][1]);

                if (difference2 > difference)
                {
                    Node *tmp = copy[c];
                    copy[c] = copy[s];
                    copy[s] = tmp;
                }
            }
        }
    }
    else if (this->name == "Asmodeo")
    {
        for(int c = 0; c < quant; c++)
        {
            for(int s = c+1; s < quant; s++)
            {
                int difference = stoi(copy[c]->data->sins[0][1]) - stoi(copy[c]->data->goodDeeds[0][1]);
                int difference2 = stoi(copy[s]->data->sins[0][1]) - stoi(copy[s]->data->goodDeeds[6][1]);

                if (difference2 > difference)
                {
                    Node *tmp = copy[c];
                    copy[c] = copy[s];
                    copy[s] = tmp;
                }
            }
        }
    }

    for(int j = 0; j < percentage; j++)
    {
        string sin = "";
        string GD = "";
        string GD2 = "";
        for(int d = 0 ; d<7 ; d++)
        {
            if(QString::fromStdString(copy[j]->data->sins[d][0]) == this->sin){
                sin = copy[j]->data->sins[d][1];
                GD = copy[j]->data->goodDeeds[d][1];
                GD2 = copy[j]->data->goodDeeds[d][0];
            }
        }

        QString text = dateString + " Humano: " + QString::number(copy[j]->data->id) + " " + QString::fromStdString(copy[j]->data->name)
               + " " + QString::fromStdString(copy[j]->data->surname) + " " + QString::fromStdString(copy[j]->data->country) + " Murió el "
               + yearMonthDay + " condenado por " + QString::fromStdString(sin) + " pecados de " + this->sin + " y " +
               QString::fromStdString(GD) + " acciones de " + QString::fromStdString(GD2) + " por el demonio " + this->name + "\n";

        if(file.exists())
        {
            if(file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
            {
                QTextStream out(&file);
                out << text;
                file.flush();
                file.close();
            }
            else
            {
                cout << "no existe" << endl;
            }
        }

    }
    this->count++;


}

void Demon::insertToHeap(AVLTree *tree)
{
    tree->getSins(this->n,tree->root);
    this->heap->insertKey(tree);
}
