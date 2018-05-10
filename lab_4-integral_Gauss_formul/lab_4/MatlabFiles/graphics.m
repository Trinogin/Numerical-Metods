clear
clc

%%
P = load('result.txt');
loglog(P(:,2),P(:,1));
grid on
hold on
%%
P_1 = load('result_1.txt');
loglog(P_1(:,2),P_1(:,1));

%%
P_2 = load('result_2.txt');
loglog(P_2(:,2),P_2(:,1));

%%
P_3 = load('result_3.txt');
loglog(P_3(:,2),P_3(:,1));
n = length(P);

x = 1:n;

ylabel('I-I_h');
xlabel('h');
legend('n = 2','n = 3','n = 5','n = 6');
plot(x,P);
grid on