%% INSTRUCTIONS: comment/uncomment lines so that only one value for 'params' is chosen.
% Each set of parameter values has been saved after observing a different
% (and interesting) final equilibrium state.

% Swirly Stripes
% params = [1.9091    5.2955    1.7273   -0.3955   -2.7273];

% Thick Stripes/Swirls
% params = [3.0202    7.1843    2.6162   -0.8177    4.9293];

% Long Spots
% params = [2.7929    6.7980    2.4343   -0.7313    -13.4747];

% Small Sparse Spots
% params = [1.5303    4.6515    1.4242   -0.2515   -4.6061];

% Thin Stripes and Spots
% params = [1.7576    5.0379    1.6061   -0.3379   -3.1515];

% Thick Stripes
% params = [2.3131    10.9823    2.0505   -0.95490    0.4040];

% Thin blue stripes/spots
% params = [2.0859    5.5960    1.8687   -0.4626   3.0505];

%Stripes
% params = [2.0526    5.5395    1.8421   -0.4500   -1.2632];

% Small Regular Spots
% params = [1.6579    4.8684    1.5263   -0.3000   -3.7895];

% Regular Swirls
% params = [1    5    4   -0.5   1];

% Long Thick Swirls
% params = [3.5000    8.0000    3.0000   -1.0000    8.0000];

%
% params = [1.9211    5.3158    1.7368   -0.4000   -2.1053];

%
% params = [2.9737    7.1053    2.5789   -0.8000    4.6316];

% params = [1.9211    5.3158    1.7368   -0.4000   -2.1053];

% Single radius
% params = [1.5    4    10   0   0];
%%

m=100;
[A, E] = initializeSystem(0.5, m, params );
E = calcStartEnergy(A, params);
[B, E] = runSimulation(A, params, 1, E(1,end));
