execute: main.cpp
	g++ main.cpp -std=c++17 -I ./references/ac-library;xclip -selection c -o;python -c 'print("-"*63)';xclip -selection c -o | ./a.out;rm ./a.out

# 上のやつをただ見やすく改行しただけ
#execute: main.cpp
#	g++ main.cpp -std=c++17 -I ./references/ac-library;\
#	xclip -selection c -o;\
#	python -c 'print("-"*63)';\
#	xclip -selection c -o | ./a.out;\
#	rm ./a.out

#run2: main.cpp
#	g++ main.cpp; xclip -selection c -o; python -c 'print("-"*63)'; xclip -selection c -o | ./a.out; rm ./a.out
#run: mycode.cpp
#	g++ mycode.cpp ; xclip -selection c -o | ./a.out ; rm ./a.out ; cat mycode.cpp | xclip -selection c


handmade: main.cpp
	g++ main.cpp -std=c++17 -I ./references/ac-library; ./a.out; rm ./a.out


submit:
	cat main.cpp | xclip -selection c

reset:
	cp references/main.cpp ./main.cpp

combined_submit:
	cp main.cpp ./references/ac-library/;\
	cd ./references/ac-library/;\
	python3 expander.py main.cpp;\
	cat combined.cpp | xclip -selection c

