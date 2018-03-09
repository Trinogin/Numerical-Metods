This is a work on the interpolation of polynomials.
Polynomial of Lagrange.
-----------------------------------------------------------------------------------
Researching addiction epsilon == max⁡|f(x)-L_n⁡〖(x)〗| with (x on [a;b] ) from 
degree of polynomial and the same addiction in one point. 
Functions different types.
sin(x) - smooth function
abs(x) - bend function (on [-1;1]) !! =>

!! 
Researching is on [a;b] = [-1.0;1.0]

-----------------------------------------------------------------------------------
1st part.
-----------------------------------------------------------------------------------
Generating of a grids, two types. 
This part is in Matlab.
File "GridFileGenerate.m":

1st type - uniform grid, it s like x_i=x_(i-1)+h.

2nd type - chebyshev grid, grid with formula x_i=(a+b)/2+(b-a)/2 * cos⁡〖((2i+1)π)/(2(n+1))〗.

Function "GridMaker.m" create 2 grids of size "i", one is uniform 
and second is chebyshev grid.

In File "GridFileGenerate.m" creating grids of size from 1 to size_grid on the [a;b],
also created splitting of interval [a;b] for computing epsilon in this 
points and searching maximum. This grids printed into files. 
1)x_points.txt - splitting [a;b]
2)x_uniform.txt - uniform grid for max epsilon 
3)x_cheb.txt - chebyshev grid for max epsilon
4)point_uniform.txt - uniform grid for epsilon on point
5)point_cheb.txt - chebyshev grid for epsilon on point

-----------------------------------------------------------------------------------
2nd part
-----------------------------------------------------------------------------------
Reading all grids, filling y(x). In cycle by grid sizes computings 2 things 
(on every iteration)
1) Maximum Epsilon on [a;b] 
2) Epsilon in one point. (0.8 for example)

All results is writing to files.
4 files.
1)Maximum Epsilon on uniform grid -> MaxEpsUnif.txt
2)Maximum Epsilon on chebyshev grid -> MaxEpsCheb.txt
3)Epsilon in point by unifrom grid -> PointEpsUniform.txt
4)Epsilon in point by chebyshev grid -> PointEpsCheb.txt

-----------------------------------------------------------------------------------
3rd part 
-----------------------------------------------------------------------------------
In file "EpsGraph.m" creating graphics of different epsilons
