#make relationship file for the progam
test: main.o costFunc.o createYassign.o
	g++ -o test  main.o costFunc.o createYassign.o

main.o: main.cpp
	g++ -c main.cpp

costFunc.o: costFunc.cpp
	g++ -c costFunc.cpp

creatYasign.o: createYassign.cpp
	g++ -c createYassign.cpp

clean: 
	rm *.o
	rm assign2
