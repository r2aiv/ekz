all:
	g++ -o 01 01.cpp
	#g++ -o 02 02.cpp
	#g++ -o 03 03.cpp

clean:
	rm 01 02 03

show1:
	cat 01.txt

show2:
	cat 02.txt

show3: 
	cat 03.txt

