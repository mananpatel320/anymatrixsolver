#include<iostream>
using namespace std;
int main()
{
    float A[100][100],t,x,B[100];
    int R,C,k=0,m=0;
    cout<<"Rows:";cin>>R;        //input rows in augmented matrix
    cout<<"Columns:";cin>>C;     //input columns in augmented matrix
    for(int i=0;i<R;i++)         //augmented matrix input loop
    {
        for(int j=0;j<C;j++)
        {
            cin>>A[i][j];
        }
    }
    cout<<endl;
    cout<<"INPUT MATRIX\n";     //Display the matrix entered
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
    while(k<R)
    {if(A[k][k]==0)            //Row interchange if element of primary diagonal of coeffecient matrix is zero
    {
        for(int i=k+1;i<R;++i)
        {
            if(A[i][k]!=0)
            {
                for(int j=0;j<C;++j)
                {
                    t=A[i][j];
                    A[i][j]=A[k][j];
                    A[k][j]=t;
                }
                break;
            }
        }
    }
    x=A[k][k];
    if(A[k][k]!=1)           //Row transformation: Divide all the elements of the row by its first non-zero element from left side
    {
        for(int j=k;j<C;j++)
        {
            A[k][j]/=x;
        }
    }
    for(int i=k+1;i<=R;i++)  //Store values(in array B) of all the elements lying below(in same column as that element) the
    {	                     //first non-zero element of that row(from left side).
        B[i]=A[i][k];
    }
    for(int j=0;j<C;j++)    //Conversion of matrix to Echelon form
    {
        for(int i=k+1;i<=R;i++)
        {
            A[i][j]-=(A[k][j]*B[i]);
        }
    }
    ++k;
    }
    while(m<(R-1))
    {for(int i=0;i<(R-m-1);i++)  //Conversion of matrix to Row Reduced Echelon form
    {
        B[i]=A[i][C-m-2];
    }
    for(int j=0;j<C;j++)
    {
        for(int i=0;i<(R-m-1);i++)
        {
            A[i][j]-=(A[R-m-1][j]*B[i]);
        }
    }
    ++m;
    }
    cout<<"The solution to the system of equations is\n";  //Display solutions
    for(int i=0;i<R;i++)
    {
        cout<<"X"<<i+1<<" = "<<A[i][C-1];
        cout<<endl;
    }
    return 0;
}
