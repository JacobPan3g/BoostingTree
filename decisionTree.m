function decisionTree( L, A, deepth, rootIdx )

global JP_MAX_HIGH;
global JP_T;

if deepth > JP_MAX_HIGH
	return;
elseif  length(L) == 0
	return;
elseif mean(L) == L(1)
	return;
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

	rootIdx
	minF
	tmpN1
	tmpN2

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

	size(L1)
	size(L2)

	% recursion
	ginis(minF) = 1e8;
	decisionTree( L1, A1, deepth+1, 2*rootIdx );
	decisionTree( L2, A2, deepth+1, 2*rootIdx+1 );

end

end
