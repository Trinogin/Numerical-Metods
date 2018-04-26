clear
clc

N = 100; % Number of points

A = -1.0; % right and left border of interval
B =  1;

dlmwrite('grid.txt',N);

for i = 4 : N
    interval = linspace(A, B, i);
    %f_x = sin(interval);
    %f_x = cos(interval);
    
    dlmwrite('grid.txt', interval,'-append',  'delimiter',' ');
   % dlmwrite('grid.txt', f_x,'-append', 'delimiter',' ');
end;

dlmwrite('extrafile.txt',N,'delimiter',' ');

%%
clear
clc


x = -2:0.1:7;
y =(x - 1).* (x + 1).* (x - 5);
plot(x,y);
grid on
cftool