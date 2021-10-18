%% Define Parameters
n = 4;
p = 0.3;

%% Analytical Pmf Plot
p_x = zeros([1, n+1]);

for i =0:n
    p_x(i+1) = nchoosek(n, i)*p^i*(1-p)^(n-i);
end

plot(0:n, p_x);
xticks([0 1 2 3 4])
ax = gca;
ax.XGrid = 'on';

%% Calculating/Plotting Empirical Pmf
N = 100;
val = binornd(n, p, [1, N]);
s = zeros([1, n+1]);

for i = 0:n
    s(i+1) = sum(val == i)/N;
end

plot(0:n, s);
xticks([0 1 2 3 4])
ax = gca;
ax.XGrid = 'on';
title('Emprical Pmf Plot for N=100');

%%
N2 = 1000;
val2 = binornd(n, p, [1, N2]);
s2 = zeros([1, n+1]);

for i = 0:n
    s2(i+1) = sum(val2 == i)/N2;
end

plot(0:n, s2);
xticks([0 1 2 3 4])
ax = gca;
ax.XGrid = 'on';
title('Emprical Pmf Plot for N=1000');

%%
N3 = 10000;
val3 = binornd(n, p, [1, N3]);
s3 = zeros([1, n+1]);

for i = 0:n
    s3(i+1) = sum(val3 == i)/N3;
end

plot(0:n, s3);
xticks([0 1 2 3 4])
ax = gca;
ax.XGrid = 'on';
title('Emprical Pmf Plot for N=10000');

%% Compare Analytical and Empirical Pmf

plot(0:n, s); hold on
plot(0:n, s2); hold on
plot(0:n, s3); hold on
plot(0:n, p_x); 
xticks([0 1 2 3 4])
ax = gca;
ax.XGrid = 'on';
legend({'N=100', 'N=1000', 'N=10000', 'Analytical'})
%% Error Vs. different values of N
clf
error = zeros([1, 3]);
error(1) = dot(s-p_x, s-p_x)/N;
error(2) = dot(s2-p_x, s2-p_x)/N2;
error(3) = dot(s3-p_x, s3-p_x)/N3;
plot(1:3, error);
% xticks([100 1000 10000])
xticklabels({'N=100', '', 'N=1000', '', 'N=10000'});
grid on


%% Empirical Mean
Emp_Mean = dot(0:n, s3);
display(Emp_Mean);
Emp_Mean = dot(0:n, s2);
display(Emp_Mean);
Emp_Mean = dot(0:n, s);
display(Emp_Mean);
%% Analytical Mean
Ana_Mean = n*p;
display(Ana_Mean);

%% Percentage Error 
display(abs(Ana_Mean-Emp_Mean)*100/(Ana_Mean));




     
