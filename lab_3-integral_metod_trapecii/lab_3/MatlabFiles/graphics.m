clc
clear

P = load('result.txt');

n = 1 : length(P);
q = 1./n.^2;

%loglog(n,q);
%semilogy(n,q);
plot(n,q);
grid on
hold on
%loglog(n,P);
%semilogy(n,P);
plot(n,P);
legend('1/n^2','abs(I*(x) - I_h(x)')