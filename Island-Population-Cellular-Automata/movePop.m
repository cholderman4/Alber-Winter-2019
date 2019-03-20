function [pop] = movePop(pop, speedOfA)

n=size(pop,1);
move=zeros(n,1);
randMove = rand(n,1);

% Set options for A movement.
% Depending on speed, A can move up to 2 steps right or left.
switch speedOfA
    case 0
        % Slow speed of A
        a = [-1, 0, 1];
    case 1
        % Medium speed of A
        a = [-2,-1,0,1,2];
    case 2
        % Fast speed of A
        a = [-2, 0, 2];
end
p_a = (1/size(a,2)):(1/size(a,2)):1;

% Set parameters for B movement.
% B can move up to one step right or left.
b = [-1, 0, 1];
p_a = (1/size(b,2)):(1/size(b,2)):1;

% Get the movements of A's and B's.
for i=size(a,2):-1:1
    move(pop==1 & randMove < p_a(i))= a(i);
end

for j=size(b,2):-1:1
    move(pop==0 & randMove < p_b(j))= b(j);
end


% Calculate new position. Individuals may go off the edge and may be in the
% same spot as another.
oldPos(:,1) = 1:n;
newPos = oldPos + move;


% Circular boundary conditions.
newPos(newPos==-1) = n-1;
newPos(newPos==0) = n;
newPos(newPos==n+1) = 1;
newPos(newPos==n+2) = 2;

%[randMove, pop, move, oldPos, newPos]
A=[newPos, move, pop];

A=sortrows(A, [1,2]);
if (~isempty(A))
%     newPop(:,1)=[0];
% else
    pop(:,1)=A(:,3);
end


end

