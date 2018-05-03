clear
clc
P = load('result.txt');

n = length(P);

x = 1:n;

plot(x,P);
grid on