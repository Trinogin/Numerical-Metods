clear
clc

max_uniform_eps = load('MaxEpsUnif.txt');
max_cheb_eps = load('MaxEpsCheb.txt');

n = length(max_uniform_eps);
x = 1 : n;

semilogy(x, max_uniform_eps);
grid on
hold on
semilogy(x, max_cheb_eps);
legend('Uniform grid','Chebyshev grid');
%text(20,10^2,'abs(x)');