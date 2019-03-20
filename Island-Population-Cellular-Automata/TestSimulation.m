n = 50; % Population size.
T = 50; % Maximum number of time steps.
p_birth = 0:.1:1; % All possible birth probabilities.
p_death = 0:.1:0.5; % All possible death probabilities.
numSim = 20; % Number of simulations to run for each parameter value.
b = size(p_birth, 2);
d = size(p_death, 2);


Avg = zeros(b,d);
Var = zeros(b,d);

for i=1:b
   for j=1:d
       [Avg(i,j), Var(i,j)] = runIslandPop(n, p_birth(i), p_death(j), T, numSim, 0);
       [p_birth(i),p_death(j)]
   end
end

% Display results.
image([0 1], [0 1], Avg,'CDataMapping','scaled')
colorbar

save("fixed.mat");


