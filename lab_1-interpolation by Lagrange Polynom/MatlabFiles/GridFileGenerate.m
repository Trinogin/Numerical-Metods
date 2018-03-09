clear
clc

size_points = 1000;
size_grid = 60;
%% a,b - border of interval for seraching max epsilon
a = -1.0;
b = 1.0;

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

%% For one point

dlmwrite('point_uniform.txt', size_grid);
dlmwrite('point_cheb.txt', size_grid);
for i = 1 : size_grid
    [point_x_uniform, point_x_cheb] = GridMaker(i,a,b);
    dlmwrite('point_uniform.txt', point_x_uniform,'-append','delimiter',' ');
    dlmwrite('point_cheb.txt',point_x_cheb,'-append','delimiter',' ');
end
