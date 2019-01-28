#include<iostream>
using namespace std;
int main()
{
    float A[100][100],t,x,B[100],z;
    int R,C,k=0,m=0,l=0,n=0,p=0;
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
    {if(A[k][k]==0)            //Row interchange if element of primary diagonal of coefficient matrix is zero
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
                ++n;
                break;
            }
        }
      for(int j=0;j<C;j++)
    {
        if(A[k][j]!=0)
            ++l;
    }
    if(l==0)             //If all the elements of a row are 0 then there are infinite solutions
    {
        cout<<"\nThere are infinitely many solutions of the system of equations.\n";
        return 0;
    }
    else if(l==1&&A[k][C-1]!=0)  //If all the elements, except the last one, of a row are 0 then no solution exists
    {
        cout<<"\nNo solution exits for the system system of equations.\n";
        return 0;
    }
    l=0;
      z=A[k][C-1]/A[k+1][C-1];
      for(int j=k+1;j<C;j++)

      {
          if((A[k][j]/A[k+1][j])!=z)
            ++p;
      }
     if(n==0&&A[k][C-1]!=0)
     {
        if(p!=0)
        {
         cout<<"\nNo solution exists for the system of equations.\n";
         return 0;
        }
        else
        {
            cout<<"\nThe system of equations has infinite many solutions.\n";
         return 0;
        }
     }

     n=0;
     p=0;
    }

    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;


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
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;


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
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    ++m;
    }
    cout<<"OUTPUT MATRIX\n";
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;


    cout<<"The solution to the system of equations is\n";  //Display solutions
    for(int i=0;i<R;i++)
    {
        cout<<"X"<<i+1<<" = "<<A[i][C-1];
        cout<<endl;
    }
    return 0;
}
