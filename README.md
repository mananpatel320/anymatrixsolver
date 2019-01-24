#Linear Equation Solver
The C++ program gives a solution of system of linear equations containing upto 100 unknowns.
A 2D array is used to solve these equations.
Mathematically speaking, Gauss-Jordan elimination method is used to solve the system of linear eqations.
The user has to input the augmented matrix, which in turn gets converted to Row Reduced Echelon Form to obtain solution.

You need to input the augmented matrix representing the system of equations.
For example augmented matrix of system of equations
   2x+2y-4z=14
   3x+y+z=8
   2x-y+2z=-1
   is given by
   2 2 -4 14
   3 1 1 8
   2 -1 2 -1
   In the above example 
   2 2 -4
   3 1 1
   2 -1 2 
   is called the coeffecient matrix.(Let's say A)
   And,
   14
   8
   -1
   is called constant matrix.(Let's say B)
   Hence the augmented matrix is represented by [A|B].
   

The program is designed and compiled in gcc g++ compiler for C++14.
It might work for other compilers too.
Run and build the .cpp file.

Two images are attached in repo representing the working of program in codeblocks IDE shell.

NOTE:Please input n x (n+1) order matrices only. (where n<100)
     (exp. 2x3 or 3x4 or 4x5 or 5x6 etc. order matrices are only valid).
     Also the system of equations must have a solution in order for the program to work.
