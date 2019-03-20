function [Avg, Var] = runIslandPop(n, p_birth, p_death, T, numSim, movie)

finalRatio = zeros(numSim,1);
speedOfA = 1;

for j=1:numSim
    x=rand(n,1);
    pop=zeros(n,1);
    pop(x<0.5)=1;
    
    tempFinalRatio = 0;
    for i=1:T
        pop = movePop(pop, speedOfA);
        pop = recruitBirth(pop, p_birth);
        pop = death(pop, p_death);
        tempFinalRatio = mean(pop);
        
        % Make movie.
        if (movie == 1)
            imagesc(pop', [0 1])
            colorbar
            pause(.25)
        end
        
        if (tempFinalRatio < 8.0e-3 || 1.00 - tempFinalRatio < 1e-4)
            break;
        end
    end
    finalRatio(j) = tempFinalRatio;
end

Avg = mean(finalRatio);
Var = var(finalRatio);
