function ginis = GINI( L, A )

[m,n] = size(A);
ginis = zeros( n, 1 );
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
	ginis(i) = P*(2*p1*(1-p1)) + (1-P)*(2*p2*(1-p2));
end

end
