clear
clc

max_uniform_eps = load('MaxEpsUnif.txt');
max_cheb_eps = load('MaxEpsCheb.txt');

point_uniform_eps = load('PointEpsUniform.txt');
point_cheb_eps = load('PointEpsCheb.txt');

n = length(max_uniform_eps);
x = 1 : n;
% About x: all vector have the same length,
% and we can use one vector x for all graphics

figure('Name','Max epsilon on interval');
semilogy(x, max_uniform_eps);
grid on
hold on
semilogy(x, max_cheb_eps);
legend('Uniform grid','Chebyshev grid');
text(20,10^2,'sin(x)');

figure('Name','Epsilon in one point');
semilogy(x, point_uniform_eps);
grid on
hold on
semilogy(x, point_cheb_eps);
legend('Uniform grid','Chebyshev grid');
text(10,10^4,'abs(x) in point 0.8');
