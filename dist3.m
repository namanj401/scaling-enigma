%% Define parameters
lambda = 3;

%% Analytical pdf plot
M = 1000;
x = linspace(0, 10, M);
plot(x, lambda*exp(-lambda*x));
legend('$\lambda e^{-\lambda x}$', 'Interpreter', 'latex');
grid on

%% Calculating/Plotting empirical pdf
N = 100;
x1 = exprnd(1/lambda, [1, N]);
da = 0.1;
n = -4:da:4;
bin = n - 0.05;
bin = bin(2:length(bin));
s = zeros([1, length(bin)]);
less = zeros([1, N]);
more = zeros([1, N]);
for i =1:length(bin)
    less = x1 < (bin(i) + 0.5*da);
    more = x1 > (bin(i) - 0.5*da);
    s(i) = sum(less & more)/N;
end

plot(bin, s/da);
grid on
title('Emprical Pmf Plot for N=100');

%%
N2 = 1000;
x1 = exprnd(1/lambda, [1, N2]);
da = 0.1;
n = -4:da:4;
bin = n - 0.05;
bin = bin(2:length(bin));
s2 = zeros([1, length(bin)]);
less = zeros([1, N2]);
more = zeros([1, N2]);
for i =1:length(bin)
    less = x1 < (bin(i) + 0.5*da);
    more = x1 > (bin(i) - 0.5*da);
    s2(i) = sum(less & more)/N2;
end

plot(bin, s2/da);
grid on
title('Emprical Pmf Plot for N=1000');

%%
N3 = 10000;
x1 = exprnd(1/lambda, [1, N3]);
da = 0.1;
n = -4:da:4;
bin = n - 0.05;
bin = bin(2:length(bin));
s3 = zeros([1, length(bin)]);
less = zeros([1, N3]);
more = zeros([1, N3]);
for i =1:length(bin)
    less = x1 < (bin(i) + 0.5*da);
    more = x1 > (bin(i) - 0.5*da);
    s3(i) = sum(less & more)/N3;
end

plot(bin, s3/da);
grid on
title('Emprical Pmf Plot for N=10000');

%% Compare Analytical and Empirical Pmf
plot(bin, s/da); hold on
plot(bin, s2/da); hold on
plot(bin, s3/da); hold on
plot(x, lambda*exp(-lambda*x));
grid on
legend({'N=100', 'N=1000', 'N=10000', 'Analytical pdf: \lambda e^{-\lambda x}'})

%% Empirical Mean
Emp_Mean = dot(bin, s3/da)*da;
display(Emp_Mean);
Emp_Mean = dot(bin, s2/da)*da;
display(Emp_Mean);
Emp_Mean = dot(bin, s/da)*da;
display(Emp_Mean);
%% Analytical Mean
Ana_Mean = 1/lambda;
display(Ana_Mean);

%% Percentage Error
display(abs(Ana_Mean - Emp_Mean)*100/(Ana_Mean));

