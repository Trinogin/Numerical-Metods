P = load( 'result.txt');

n = 1:length(P);

f = P(1,:).^2; 
eps = P(2,:) - f;


semilogy(eps, ); 