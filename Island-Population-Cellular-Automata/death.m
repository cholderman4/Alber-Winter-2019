function [pop] = death(pop, p_death)
    n = size(pop,1);
    randDeath = rand(n,1);

    pop(randDeath < p_death)=[];
end

