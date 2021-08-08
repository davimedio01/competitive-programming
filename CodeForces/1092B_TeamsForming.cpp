#include <iostream>
#include <stdio.h>

#define max 100

using namespace std;

void GnomeSort(int vet[], int n);
void troca(int *x, int *y);

int main()
{

    int num_students;
    cin >> num_students;

    if (num_students % 2 == 0)
    {

        int vet[max];
        for (int i = 0; i < num_students; i++)
        {
            cin >> vet[i];
        }

        //Ordenando o Vetor (Gnome Sort)
        GnomeSort(vet, num_students);

        int total = 0;

        for (int i = 0; i < num_students - 1; i += 2)
        {
            total += (vet[i + 1] - vet[i]);
        }

        cout << total << endl;
    }

    return 0;
}

void GnomeSort(int vet[], int n)
{

    int aux = 0;
    while (aux < n)
    {

        if (aux == 0)
            aux++;

        if (vet[aux] >= vet[aux - 1])
            aux++;
        else
        {
            troca(&(vet[aux]), &(vet[aux - 1]));
            aux--;
        }
    }
}

void troca(int *x, int *y)
{
    int aux;

    aux = (*x);
    (*x) = (*y);
    (*y) = aux;
}