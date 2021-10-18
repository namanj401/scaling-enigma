%% Joint PDF of X and Y
N = 1000000;
X_val = rand([1, N]);
Y_val = rand([1, N]);
dx = 0.1;
nx = -1:dx:2;
binx = nx - 0.05;
binx = binx(2:length(binx));
dy = 0.1;
ny = -1:dy:2;
biny = ny - 0.05;
biny = biny(2:length(biny));
[BIN_X, BIN_Y] = meshgrid(binx, biny);
Z = zeros([length(binx), length(biny)]);
lessX = zeros([1, N]);
moreX = zeros([1, N]);
lessY = zeros([1, N]);
moreY = zeros([1, N]);
for i = 1:length(binx)
    for j = 1:length(biny)
        lessX = X_val < (BIN_X(i, j) + 0.5*dx);
        moreX = X_val > (BIN_X(i, j) - 0.5*dx);
        lessY = Y_val < (BIN_Y(i, j) + 0.5*dy);
        moreY = Y_val > (BIN_Y(i, j) - 0.5*dy);
        Z(i, j) = sum(lessX & moreX & lessY & moreY)/N;
    end
end

surf(BIN_X, BIN_Y, Z/(dx*dy));
xlabel('X');
ylabel('Y');
zlabel('PDF');
title('Joint PDF of X and Y');
colorbar

%% Empirical Marginal Distribution
pdf_x = zeros([1, length(binx)]);
less_x = zeros([1, N]);
more_x = zeros([1, N]);
for i = 1:length(binx)
    less_x = X_val <(binx(i) + 0.5*dx);
    more_x = X_val >(binx(i) - 0.5*dx);
    pdf_x(i) = sum(less_x & more_x)/N;
end

plot(binx, pdf_x/dx); hold on
grid on
title('Empirical Marginal PDF');


%% Marginal Calculated by conditioning on Y
epsilon = 0.1;
lt = 0.3;
ht = 0.3 + epsilon;
mask = (Y_val < (0.3+epsilon)) & (Y_val > 0.3) ;
Y_new = Y_val(mask);
Y_new = Y_new(Y_new~=0);
X_new = X_val(mask);
X_new = X_new(X_new~=0);
pdf_x_new = zeros([1, length(binx)]);
less_x_new = zeros([1, N]);
more_x_new = zeros([1, N]);
for i = 1:length(binx)
    less_x_new = X_new <(binx(i) + 0.5*dx);
    more_x_new = X_new >(binx(i) - 0.5*dx);
    pdf_x_new(i) = sum(less_x_new & more_x_new)/(length(X_new));
end

plot(binx, pdf_x_new/dx);
grid on
legend({'Empirical Marginal PDF', 'PDF calculated by conditioning'});
title('PDF');
