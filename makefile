#make relationship file for the progam
test: main.o costFunc.o createYassign.o readIn.cpp 
	g++ -o test  main.o costFunc.o createYassign.o readIn.cpp 

debug: main.o costFunc.o createYassign.o readIn.cpp 
	g++ -g -o debug main.o costFunc.o createYassign.o readIn.cpp 

main.o: main.cpp
	g++ -c -g  main.cpp

annealingFunc.o: annealingFunc.cpp
	g++ -c -g annealingFunc.cpp
 
costFunc.o: costFunc.cpp
	g++ -c -g costFunc.cpp

creatYasign.o: createYassign.cpp
	g++ -c -g createYassign.cpp

readIn.o: readIn.cpp
	g++ -c -g readIn.cpp
clean: 
	rm *.o
	rm test
	rm debug
