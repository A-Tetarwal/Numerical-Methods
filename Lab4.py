1 # = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
2 # T e s t I n t e r p o l a t i o n L a g r a n g e 0 2 . py : Work with Lagrange basis polynomials ...
3 #
4 # Written By : Mark Austin July 2023
5 # = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
6
7 import math ;
8
9 import numpy as np
10 import numpy . polynomial . polynomial as poly
11 import matplotlib . pyplot as plt
12
13 plt . style . use ( ’ seaborn - poster ’)
14
15 def main ():
16 print (" --- Case Study 1. Interpolation . lagrange () ... " );
17
18 x = [0 , 1, 3]
19 y = [1 , 0, 10]
20
21 print (" --- Create arrays of basis function coefficients ... " );
22
23 P0_coeff = [ 1 , -4.0/3.0 , 1.0/3.0 ]
24 P1_coeff = [ 0 , 1.5 , -0.5 ]
25 P2_coeff = [ 0 , -1.0/6.0 , 1.0/6.0 ]
26
27 # Get the polynomial function
Motivating Ideas Method of Divided Differences (Interpolation) Lagrange Interpolation Least Squares Analysis (Curve Fitting) PyCode 3: Lagrange Basis Polynomials
29 print (" --- Create and print polynomials ... " );
30
31 P0 = poly . Polynomial ( P0_coeff )
32 P1 = poly . Polynomial ( P1_coeff )
33 P2 = poly . Polynomial ( P2_coeff )
34
35 np . polynomial . set_default_printstyle ( ’ ascii ’)
36
37 print (" --- Create array of x values for plotting ... " );
38
39 x_new = np . arange ( -1.0 , 3.1 , 0.1)
40
41 print (" --- Plot Lagrange polynomials ... " );
42
43 fig = plt . figure ( figsize = (10 ,8))
44 plt . plot ( x_new , P0 ( x_new ) , ’b ’ , label = ’p0 (x) ’)
45 plt . plot ( x_new , P1 ( x_new ) , ’r ’ , label = ’p1 (x) ’)
46 plt . plot ( x_new , P2 ( x_new ) , ’g ’ , label = ’p2 (x) ’)
47
48 plt . plot (x , np . ones ( len (x )) , ’ko ’, x , np . zeros ( len ( x )) , ’ko ’)
49 plt . title ( ’ Lagrange Basis Polynomials ’)
50 plt . xlabel ( ’x ’)
51 plt . ylabel ( ’p(x ) ’)
52 plt . grid ()
53 plt . legend ()
54 plt . show ()
55
56 # call the main method ...
57
58 main ()
Motivating Ideas Method o