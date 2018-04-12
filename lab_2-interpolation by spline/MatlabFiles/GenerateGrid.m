clear
clc

N = 100; % Number of points

A = 0.0; % right and left border of interval
B = 10.0;

interval = linspace(A, B, N);

f_x = interval.^2 ;

dlmwrite('grid.txt',N);
dlmwrite('grid.txt', interval,'-append',  'delimiter',' ');
dlmwrite('grid.txt', f_x,'-append', 'delimiter',' ');
