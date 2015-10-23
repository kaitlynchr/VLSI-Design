#make relationship file for the progam
test: main.o costFunc.o createYassign.o readIn.cpp
	g++ -o test  main.o costFunc.o createYassign.o readIn.cpp

main.o: main.cpp
	g++ -c main.cpp

costFunc.o: costFunc.cpp
	g++ -c costFunc.cpp

creatYasign.o: createYassign.cpp
	g++ -c createYassign.cpp

readIn.o: readIn.cpp
	g++ -c readIn.cpp
clean: 
	rm *.o
	rm test
