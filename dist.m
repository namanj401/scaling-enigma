%%  Define Parameters
M = 10;

%% Analytical CDF Plot
x = linspace(-1, 2, M);
plot(x, [zeros([1, 3]), x(4:6), ones([1, 4])]);
grid on

%% Calculating/Plotting Empirical CDF
N = 100;
val = rand([1, N]);
p_x = zeros([1, M]);
for i = 1:M
    p_x(i) = sum(val <= x(i))/N;
end

plot(x, p_x);
grid on;
title('Emprical CDF Plot for N=100');
%%
N2 = 1000;
val2 = rand([1, N2]);
p_x2 = zeros([1, M]);
for i = 1:M
    p_x2(i) = sum(val2 <= x(i))/N2;
end

plot(x, p_x2);
grid on;
title('Emprical CDF Plot for N=1000');
%%
N3 = 10000;
val3 = rand([1, N3]);
p_x3 = zeros([1, M]);
for i = 1:M
    p_x3(i) = sum(val3 <= x(i))/N3;
end

plot(x, p_x3);
grid on;
title('Emprical CDF Plot for N=10000');
%% Compare Analytical and Empirical CDF
plot(x, p_x); hold on
plot(x, p_x2); hold on
plot(x, p_x3); hold on
plot(x, [zeros([1, 3]), x(4:6), ones([1, 4])]);
grid on
legend({'N=100', 'N=1000', 'N=10000', 'Analytical'})
%% Empirical Mean
Emp_Mean = sum(val3)/N3;
display(Emp_Mean);
Emp_Mean = sum(val2)/N2;
display(Emp_Mean);
Emp_Mean = sum(val)/N;
display(Emp_Mean);
%% Analytical Mean
Ana_Mean = 1/2;
display(Ana_Mean);
%% Percentage Error
display(abs(0.5-Emp_Mean)*100/0.5);
