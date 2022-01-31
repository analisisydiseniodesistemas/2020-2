EXE0 :=00_TestCalcular.exe
EXE1 :=02_HolaMundo.exe
TOCLEAN:=*.o $(EXE0) $(EXE1)
CC = g++

default:$(EXE0) $(EXE1)
main.o:main.cpp
	$(CC) -c $< -o $@
Calcular.o:Calcular.cpp
	$(CC) -c $< -o $@
$(EXE0):main.o Calcular.o
	$(CC) $^ -o $@
$(EXE1):hola.cpp
	$(CC) $< -o $@
clean:
	rm -v $(TOCLEAN)

