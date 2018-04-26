% Data: x and y
[x, y] = titanium();

% Scalars a, b, and c
a = -2;
b = -1;
c = 0;

% End condition at left
e = x(1);

% The cubic spline interpolant s1 to the
% given data using the default end
% condition
s1 = csape(x,y);

% The cubic spline interpolant s0 to 
% zero data and some (nontrivial) end
% condition at e
s0 = csape(x,[1,zeros(1,length(y)),0],[1,0]);

% Compute the derivatives of the first
%  polynomial piece of s1 and s0
ds1 = fnder(fnbrk(s1,1));
ds0 = fnder(fnbrk(s0,1));

% Compute interpolant with desired end conditions
lam1 = a*fnval(ds1,e) + b*fnval(fnder(ds1),e);
lam0 = a*fnval(ds0,e) + b*fnval(fnder(ds0),e);
pp = fncmb(s0,(c-lam1)/lam0,s1);

%%
fnplt( pp, [594, 632] )
grid on
hold on
fnplt( s1, 'b--', [594, 632] )
plot( x, y, 'ro', 'MarkerFaceColor', 'r' )
hold off
axis( [594, 632, 0.62, 0.655] )
legend 'Desired end-conditions' ...
'Default end-conditions' 'Data' ...
    Location SouthEast