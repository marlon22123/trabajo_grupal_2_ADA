#include <iostream>
#define max 100
using namespace std;

int main()
{
    int A[max],j,item,temp,i,k,n;
    cout<<"INGRESE EL NUMERO DE ELEMENTOS A ORDENAR:";
    cin>>n;
    for(i=1;i<=n;i++)
    cin >> A[i];

    for(k=n;k>0;k--)
    {
        for(i=1;i<=k;i++)
        {
            item=A[i];
            j=i/2;
            while(j>0 && A[j]<item)
            {
                A[i]=A[j];
                i=j;
                j=j/2;
            }
            A[i]=item;
        }
        temp=A[1];
        A[1]=A[k];
        A[k]=temp;
    }
    cout<<"EL NUEVO ORDEN ES :"<<endl;
    for(i=1;i<=n;i++)
    cout<<A[i] << endl;
    return 0;
}


