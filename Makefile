__start__: obj __lines_for_space__ interp __plugin__
	export LD_LIBRARY_PATH="./libs"; ./interp komendy.txt

obj:
	mkdir obj

libs:
	mkdir libs

__lines_for_space__:
	@echo
	@echo
	@echo

__plugin__:
	cd plugin; make

CPPFLAGS=-Wall -pedantic -std=c++17 -Iinc
LDFLAGS=-Wall

interp: obj/InterfaceVector.o obj/LibInterface.o obj/main.o obj/xmlinterp.o obj/testy.o obj/Poczatek.o
	g++ ${LDFLAGS} -o interp  obj/main.o obj/InterfaceVector.o obj/LibInterface.o obj/xmlinterp.o obj/testy.o  obj/Poczatek.o -ldl -lxerces-c

obj/InterfaceVector.o: inc/LibInterface.hh inc/InterfaceVector.hh\
					src/InterfaceVector.cpp
	g++ -c ${CPPFLAGS} -o obj/InterfaceVector.o src/InterfaceVector.cpp

obj/xmlinterp.o: src/xmlinterp.cpp 
	g++ -c ${CPPFLAGS} -o obj/xmlinterp.o src/xmlinterp.cpp

obj/Poczatek.o: src/Poczatek.cpp 
	g++ -c ${CPPFLAGS} -o obj/Poczatek.o src/Poczatek.cpp

obj/LibInterface.o: inc/LibInterface.hh inc/Interp4Command.hh\
					src/LibInterface.cpp
	g++ -c ${CPPFLAGS} -o obj/LibInterface.o src/LibInterface.cpp

obj/testy.o: inc/testy.hh\
					src/testy.cpp
	g++ -c ${CPPFLAGS} -o obj/testy.o src/testy.cpp

obj/main.o: src/main.cpp inc/Interp4Command.hh inc/LibInterface.hh inc/xmlinterp.hh inc/testy.hh inc/Poczatek.hh
	g++ -c ${CPPFLAGS} -o obj/main.o src/main.cpp

clean:
	rm -f obj/* interp core*


clean_plugin:
	cd plugin; make clean

cleanall: clean
	cd plugin; make cleanall
	cd dox; make cleanall
	rm -f libs/*
	find . -name \*~ -print -exec rm {} \;

help:
	@echo
	@echo "  Lista podcelow dla polecenia make"
	@echo 
	@echo "        - (wywolanie bez specyfikacji celu) wymusza"
	@echo "          kompilacje i uruchomienie programu."
	@echo "  clean    - usuwa produkty kompilacji oraz program"
	@echo "  clean_plugin - usuwa plugin"
	@echo "  cleanall - wykonuje wszystkie operacje dla podcelu clean oraz clean_plugin"
	@echo "             oprocz tego usuwa wszystkie kopie (pliki, ktorych nazwa "
	@echo "             konczy sie znakiem ~)."
	@echo "  help  - wyswietla niniejszy komunikat"
	@echo
	@echo " Przykladowe wywolania dla poszczegolnych wariantow. "
	@echo "  make           # kompilacja i uruchomienie programu."
	@echo "  make clean     # usuwa produkty kompilacji."
	@echo
 
