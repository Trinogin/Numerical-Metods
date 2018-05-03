clc
clear

A = 0.0;
B = pi;

N = 500000;

dlmwrite('grid_2.txt',N, 'delimiter',' ');

i = 3;


x_1 = linspace(A,B,i);
x_2 = linspace(A,B,i * 2 - 1);
          
dlmwrite('grid_2.txt',x_1,'-append','delimiter', ' ');
dlmwrite('grid_2.txt',x_2,'-append','delimiter', ' '); 
   
i = 5;
while i <= N / 2
    x_1 = x_2;
    x_2 = linspace(A,B,i * 2 - 1);
    dlmwrite('grid_2.txt',x_1,'-append','delimiter', ' ');
    dlmwrite('grid_2.txt',x_2,'-append','delimiter', ' ');
    i = i * 2 - 1;
end;