tic;
if !exist('data')
	load a1a.data
end

% L: the labels
% A: the feature
[m,n] = size(A);

global JP_MAX_HIGH = 5;	% the real high + 1
global JP_GINIS = zeros(n,1);

% get GINI
%info = zeros(n,3);		% some extra-info of gini
for i = 1:n
	dNum = 0;
	cNum1 = 0;
	cNum2 = 0;
	for j = 1:m
		if A(j,i) == 1
			dNum = dNum + 1;
			if L(j) == 1
				cNum1 = cNum1 + 1;
			end
		else
			if L(j,1) == 1
				cNum2 = cNum2 + 1;
			end
		end
	end
	P = dNum/m;
	p1 = cNum1/(dNum+1e-8);
	p2 = cNum2/(m-dNum+1e-8);
	JP_GINIS(i) = P*(2*p1*(1-p1)) + (1-P)*(2*p2*(1-p2));
%	info(i,:) = [dNum, cNum1, cNum2];
end
%[minGINI, minF] = min(GNIS)

% Build tree
T = zeros(1,2^JP_MAX_HIGH);
T = decisionTree(T, L, A, 1, 1);
	
toc;
