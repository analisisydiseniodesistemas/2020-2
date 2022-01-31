EXE0:=00_buckets.exe
EXE1:=01_buckets.exe
EXE2:=02_buckets.exe
EXE3:=03_buckets.exe
TO_CLEAN:=*.o *.exe \
*.stackdump

CC=g++

default:$(EXE0) $(EXE1) $(EXE2) $(EXE3)

$(EXE0):main.o funciones.o
	$(CC) $^ -o $@
$(EXE1):main0.o funciones.o
	$(CC) $^ -o $@
$(EXE2):main1.o funciones.o
	$(CC) $^ -o $@
$(EXE3):main2.o funciones.o
	$(CC) $^ -o $@
main.o:main.cpp
	$(CC) -c $< -o $@
funciones.o:funciones.cpp
	$(CC) -c $< -o $@
main0.o:main0.cpp
	$(CC) -c $< -o $@
main1.o:main1.cpp
	$(CC) -c $< -o $@
main2.o:main2.cpp
	$(CC) -c $< -o $@
clean:
	rm -v $(TO_CLEAN)

