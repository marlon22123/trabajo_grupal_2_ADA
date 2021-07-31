
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void bucketSort(float arr[], int n)
{
    // Crea n número de cubos vacíos
    vector<float> b[n];
    // poner datos en sus posibles cubos
    for (int i=0; i<n; i++)
    {
       int bi = n*arr[i];
       b[bi].push_back(arr[i]);
    }
    // Ordena la matriz usando la función sort () predeterminada de la biblioteca de algoritmos
    for (int i=0; i<n; i++)
       sort(b[i].begin(), b[i].end());
    // Concatenar todos los cubos en
    int index = 0;
    for (int i = 0; i < n; i++)
        for ( int j = 0; j < (signed)b[i].size(); j++)
          arr[index++] = b[i][j];
}

int main()
{
    float data[] = {0.34 , 0.53 , 0.6 , 0.21 , 0.16 , 0.35 , 0.38 , 0.56 , 0.67 , 0.12};
    int len = sizeof(data)/sizeof(data[0]);
    cout << "La matriz sin ordenar es :";
    for (int i=0; i<len; i++)
       cout << data[i] << " ";
    bucketSort(data, len);
    cout << endl<<"La matriz ordenada es   :";
    for (int i=0; i<len; i++)
       cout << data[i] << " ";
    cout<<endl;
    return 0;
}


