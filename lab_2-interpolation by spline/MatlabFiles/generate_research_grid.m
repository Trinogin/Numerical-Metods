clear
clc

N = 5; % Number of points

A = 0.0; % right and left border of interval
B = 2*pi;

interval = linspace(A, B, N);

dlmwrite('r_grid.txt',N);
dlmwrite('r_grid.txt', interval,'-append',  'delimiter',' ');


dlmwrite('extrafile.txt',N,'-append','delimiter',' ');