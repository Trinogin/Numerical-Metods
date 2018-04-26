%%
N = 100;
A = 0.0;
B = 10.0;
x = linspace(A,B,N);
%dlmwrite('mnk_grid.txt',N);
dlmwrite('mnk_grid.txt',x,'delimiter',' ');

%%
y = (x - 2).*(x - 4).*(x - 8);
p = load('mnk_result.txt');
p =(rot90(p,2));
y_p = polyval(p,x);
plot(x,y_p);
grid on
hold on
plot(x,y);
legend('Interpolant','function');
%%
clear
clc
[x y] = titanium();
s1 = csape(x,y);
fnplt( s1, 'b--', [594, 632] )
grid on
