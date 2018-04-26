clc
clear

N = 3000;

A = 0.0;
B = pi;

integral_ex = 2.0;

dlmwrite('grid.txt',N, 'delimiter',' ');
dlmwrite('grid.txt',integral_ex,'-append','delimiter', ' ');
for i = 2:N
    x = linspace(A,B,i);  
    dlmwrite('grid.txt',x,'-append','delimiter', ' ');
end;

