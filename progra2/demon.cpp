#include "demon.h"

Demon::Demon(QString name, QString sin, QString desc, QString image)
{
    this->name = name;
    this->sin = sin;
    this->desc = desc;
    this->image = image;
}

Demon::Demon(){}

void Demon::condemn(DoubleList people)
{
    int quant = people.quantity;
    int percentage = quant * 5 / 100;
    DoubleList copy = people; //Copia de la lista de personas para poder modificarla y no perder el orden original, lo uso para ordenarla de mayor a menor
    Node *tmp = copy.first;

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
                    Node *temp;
                    tmp2 = tmp;
                    temp = tmp;
                }
            }
            else if (this->name == "Belcebú")
            {
                int difference = stoi(tmp->data->sins[1][1]) - stoi(tmp->data->goodDeeds[1][1]);
                int difference2 = stoi(tmp2->data->sins[1][1]) - stoi(tmp2->data->goodDeeds[1][1]);

                if (difference2 > difference)
                {
                    Node *temp;
                    tmp2 = tmp;
                    temp = tmp;
                }
            }
            else if (this->name == "Satán")
            {
                int difference = stoi(tmp->data->sins[2][1]) - stoi(tmp->data->goodDeeds[1][1]);
                int difference2 = stoi(tmp2->data->sins[2][1]) - stoi(tmp2->data->goodDeeds[1][1]);

                if (difference2 > difference)
                {
                    Node *temp;
                    tmp2 = tmp;
                    temp = tmp;
                }
            }
            else if (this->name == "Abadón")
            {
                int difference = stoi(tmp->data->sins[3][1]) - stoi(tmp->data->goodDeeds[1][1]);
                int difference2 = stoi(tmp2->data->sins[3][1]) - stoi(tmp2->data->goodDeeds[1][1]);

                if (difference2 > difference)
                {
                    Node *temp;
                    tmp2 = tmp;
                    temp = tmp;
                }
            }
            else if (this->name == "Mammón")
            {
                int difference = stoi(tmp->data->sins[4][1]) - stoi(tmp->data->goodDeeds[1][1]);
                int difference2 = stoi(tmp2->data->sins[4][1]) - stoi(tmp2->data->goodDeeds[1][1]);

                if (difference2 > difference)
                {
                    Node *temp;
                    tmp2 = tmp;
                    temp = tmp;
                }
            }
            else if(this->name == "Belfegor")
            {
                int difference = stoi(tmp->data->sins[5][1]) - stoi(tmp->data->goodDeeds[1][1]);
                int difference2 = stoi(tmp2->data->sins[5][1]) - stoi(tmp2->data->goodDeeds[1][1]);

                if (difference2 > difference)
                {
                    Node *temp;
                    tmp2 = tmp;
                    temp = tmp;
                }
            }
            else if (this->name == "Asmodeo")
            {
                int difference = stoi(tmp->data->sins[6][1]) - stoi(tmp->data->goodDeeds[1][1]);
                int difference2 = stoi(tmp2->data->sins[6][1]) - stoi(tmp2->data->goodDeeds[1][1]);

                if (difference2 > difference)
                {
                    Node *temp;
                    tmp2 = tmp;
                    temp = tmp;
                }
            }
        }
        tmp = tmp->next;
    }

    Node *tmp3 = copy.first;

    for(int i = 0; i <= percentage; i++)
    {
        this->heap[i] = tmp3;
        tmp3 = tmp3->next;
    }

}

void Demon::heapify(vector<Node *> arr, int n, int i)
{
    int largest = i; // Initialize largest as root
        int l = 2*i + 1; // left = 2*i + 1
        int r = 2*i + 2; // right = 2*i + 2

        // If left child is larger than root
        if (l < n && arr[l] > arr[largest])
            largest = l;

        // If right child is larger than largest so far
        if (r < n && arr[r] > arr[largest])
            largest = r;

        // If largest is not root
        if (largest != i)
        {
            swap(arr[i], arr[largest]);

            // Recursively heapify the affected sub-tree
            heapify(arr, n, largest);
        }
}

void Demon::heapSort(vector<Node *> arr, int n)
{
    // Build heap (rearrange array)
    for (size_t i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i=n-1; i>=0; i--)
    {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}
