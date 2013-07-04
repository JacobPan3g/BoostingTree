tic;
if !exist('data')
	load a1a.data
end

% L: the labels
% A: the feature
[m,n] = size(A);

global JP_MAX_HIGH;	% the real high = MAX_HIGH - 1
global JP_T;

JP_MAX_HIGH = 2;
JP_T = [];

% Build tree
decisionTree(L, A, 1, 1);
	
toc;
