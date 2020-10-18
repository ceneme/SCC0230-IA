compile:
	g++ final.cpp -o final
	g++ master_random.cpp -o rand
rand_bfs:
	./rand
	for number in 0 1 2 3 4 ; do \
    	./final < $$number.in; \
	done
