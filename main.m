tic;
if !exist('data')
	load a1a.data
end

% L: the labels
% A: the feature
[m,n] = size(A);

global JP_MAX_HIGH = 5;	% the real high + 1
%global JP_GINIS = zeros(n,1);

% get GINI
%JP_GINIS = GINI( JP_GINIS, A, L );
%[minGINI, minF] = min(GNIS)

% Build tree
T = zeros(1,2^JP_MAX_HIGH);
T = decisionTree(T, L, A, 1, 1);
	
toc;
