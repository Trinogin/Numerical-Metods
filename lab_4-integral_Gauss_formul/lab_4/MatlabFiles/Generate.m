clear
clc
%%
N = 100;
A = 0;
B = pi;

%%
syms t ;
f = sym('sin(t)');
exact_int = int(f,t,A,B)

%%
syms x;
expr = legendreP(N,x);
roots = vpasolve(expr == 0.0);
derivative = diff(expr, x, 1);

weights = 1 : N;

for i = 1 : N
    temp = subs (derivative, x, roots(i));
    temp2 = double(temp);
    weights(i) =  2.0 / ( (1 - roots(i)^2 ) * temp2^2);
end;

%%
dlmwrite('grid.txt',N);
dlmwrite('grid.txt',exact_int,'-append','precision',16);
dlmwrite('grid.txt',A,'-append','precision',16);
dlmwrite('grid.txt',B,'-append','precision',16);
dlmwrite('grid.txt',roots,'-append','precision',16);
dlmwrite('grid.txt',weights,'-append','precision',16, 'delimiter', ' ');