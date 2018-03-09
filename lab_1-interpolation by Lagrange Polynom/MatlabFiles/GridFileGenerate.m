clear
clc

size_points = 1000;
size_grid = 50;

a = 0.0;
b = 5.0;

x_points = linspace(a, b, size_points);
dlmwrite('x_points.txt', size_points);
dlmwrite('x_points.txt', x_points','-append');

%% Writing sizes of vectors and vectors in file
% - ' means transpose, for imaging the vectors as the columns
dlmwrite('x_uniform.txt', size_grid);
dlmwrite('x_cheb.txt', size_grid);
for i = 1 : size_grid
    [x_uniform, x_cheb] = GridMaker(i,a,b);
    dlmwrite('x_uniform.txt', x_uniform,'-append','delimiter',' ');
    dlmwrite('x_cheb.txt',x_cheb,'-append','delimiter',' ');
end