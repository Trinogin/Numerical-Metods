function [x_unif,x_cheb] = GridMaker(i,a,b)

x_unif = linspace(a,b,i);

for k = 1 : i
    x_cheb(k) = (a + b)/2.0 + (b - a)/2.0 * cos((2*k + 1)*pi/(2*(i + 1)));
end
end

