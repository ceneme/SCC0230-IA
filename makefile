compile:
	g++ -O3 final.cpp -o final
	g++ -O3 master_random.cpp -o rand

rand_bfs:
	for ncities in 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 ;     \
	do                                                                     \
		./rand < 0rand$$ncities.in ;                                       \
		for ntests in 0 1 2 3 4 ;                                          \
		do                                                                 \
			./final < $$ncities-$$ntests.in;                               \
		done                                                               \
	done                                                                   \

rand_dfs:
	./rand < r1.in
	for number in 0 1 2 3 4 ; do \
    	./final < $$number.in > 1res$$number.txt; \
	done

rand_dijkstra:
	./rand < r2.in
	for number in 0 1 2 3 4 ; do \
    	./final < $$number.in > 2res$$number.txt; \
	done

rand_ae:
	./rand < r3.in
	for number in 0 1 2 3 4 ; do \
    	./final < $$number.in > 3res$$number.txt; \
	done

rand_idae:
	./rand < r4.in
	for number in 0 1 2 3 4 ; do \
    	./final < $$number.in > 4res$$number.txt; \
	done
