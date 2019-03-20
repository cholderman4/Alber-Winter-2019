function [pop] = recruitBirth(pop, p_birth)

% circPop = [pop(end); pop; pop(1)];
% 
% % Recruit to A
% circPop=strrep(circPop, [1,0,1], [1,1,1]);
% 
% % %Birth from B
% circPop=strrep(circPop(2:end), [0,0], [0,4,0]);
% circPop=strrep(circPop, [4], [0]);



 
n=size(pop,1);
i=1;
while ( i <= n) 
    %%
    %Set left and right neighbors to account for circle wrapping around.
    if (i == 1)
        L = n;
    else
        L = i - 1;
    end

    if (i == n)
        R = 1;
    else 
        R = i + 1;
    end
    %%
    
    if (pop(i) == 0)
        if (pop(R) == 0 && rand < p_birth)
            %birth
            pop = [pop(1:i); 0; pop(i+1:end)];
            i=i+1;
            n=n+1;
            
        elseif ( pop(L) == 1 && pop(R) == 1)
            %convert to A
            pop(i) = 1;
        end
    end
    % Check for death.
    
    i = i+1;
end

  


end


