
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

 int particion(vector<int>&,int ,int );
 void r_quicksort(vector<int>&,int,int);

 int r_particion(vector<int>&,int,int);


void r_quicksort(vector<int>&array,int inicio,int fin){
    if(inicio<fin){
        int pivote=r_particion(array,inicio,fin);
        r_quicksort(array,inicio,pivote-1);
        r_quicksort(array,pivote+1,fin);
    }
}

int r_particion(vector<int>&arreglo,int inicio,int fin){

            int i=inicio+rand()%(fin-inicio+1);

               swap(arreglo[fin],arreglo[i]);
               return particion(arreglo,inicio,fin);

}


int particion(vector<int>&arreglo,int inicio,int fin){
    int x=arreglo[fin];
    int i=inicio-1;
    for(int j=inicio;j<=fin-1;j++){
      if(arreglo[j]<=x){
              i=i+1;
            swap(arreglo[i],arreglo[j]);
    }
}
    swap(arreglo[i+1],arreglo[fin]);
    return i+1;
}







int main()
{
    vector<int>arreglo={2,4,1,7,6,3,5};

    int inicio=0,fin=arreglo.size();
  r_quicksort(arreglo,inicio,fin);
    cout<<"array ordenado: ";
 for(int i=inicio+1;i<=fin;i++){

            cout<<"->"<<arreglo[i];

    }

}

