function isLeaf = decisionTree( L, A, deepth, rootIdx )

global JP_MAX_HIGH;
global JP_T;
global JP_LEAF;

isLeaf = 0;

if deepth > JP_MAX_HIGH
	isLeaf = 1;
elseif  length(L) == 0
	isLeaf = 1;
elseif mean(L) == L(1)
	isLeaf = 1;
else
	% get the optimal feature
	ginis = GINI( L, A );
	while 1
		tag = 1;
		[minGINI, minF] = min(ginis);
		for i = 1:length(JP_T)
			if JP_T(i) == minF
				ginis(minF) = 1e8;
				tag = 0;
				break;
			end
		end
		if tag == 1
			break;
		end
	end
	JP_T(rootIdx) = minF;

	% separate the D (L&A)
	[m,n] = size(A);
	tmpV1 = [];
	tmpV2 = [];
	tmpN1 = 0;
	tmpN2 = 0;
	for i = 1:m
		if A(i,minF) == 1
			tmpN1 = tmpN1 + 1;
			tmpV1(tmpN1) = i;
		else
			tmpN2 = tmpN2 + 1;
			tmpV2(tmpN2) = i;
		end		
	end

	%rootIdx
	%minF
	%tmpN1
	%tmpN2

	if tmpN1 == 0
		L1 = [];
		A1 = [];
	else	
		L1 = L(tmpV1);
		A1 = A(tmpV1,:);
	end
	if tmpN2 == 0
		L2 = [];
		A2 = [];
	else	
		L2 = L(tmpV2);
		A2 = A(tmpV2,:);
	end

	%size(L1)
	%size(L2)

	% recursion
	ginis(minF) = 1e8;
	isLeaf1 = decisionTree( L1, A1, deepth+1, 2*rootIdx );
	isLeaf2 = decisionTree( L2, A2, deepth+1, 2*rootIdx+1 );

	% is leaf
	if isLeaf1 & isLeaf2 == 1
		[idx, tmp] = size(JP_LEAF);
		JP_LEAF(idx+1, 1) = rootIdx;
		% compute the label
		if mean(L) >= 0
			JP_LEAF(idx+1, 2) = 1;
		else
			JP_LEAF(idx+1, 2) = -1;
		end
	end
end

end
