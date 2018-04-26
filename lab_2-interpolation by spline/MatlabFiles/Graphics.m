clear
clc

P = load('result.txt');


n = 1 : length(P);
q = 1./n.^2;
f = 1./n.^4;

loglog(n,P);
grid on
hold on
loglog(n,q);
loglog(n,f);
legend('max(cos(x) - Ln(x)','1/n^2','1/n^4');