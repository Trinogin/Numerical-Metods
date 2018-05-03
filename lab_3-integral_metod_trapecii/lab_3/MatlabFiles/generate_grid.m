clc
clear

N = 3000;

A = -1.0;
B = 1;

%integral_ex = 2; % 1 / sqrt(x)
integral_ex = 0; % sign(x)

dlmwrite('grid.txt',N, 'delimiter',' ');
dlmwrite('grid.txt',integral_ex,'-append','delimiter',' ', 'precision','%.16f');

for i = 2:N
    x = linspace(A,B,i);  
    dlmwrite('grid.txt',x,'-append','delimiter',' ');
end;