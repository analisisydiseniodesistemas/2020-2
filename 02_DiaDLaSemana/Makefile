EXE:=00TestFecha.exe
EXE1:=01TestFecha.exe 
EXE2:=02TestCdD.exe
LIMPIEZA:=*.o $(EXE) $(EXE1) $(EXE2)
ARCHIVOSOBJETO:=gettingdate.o Calendario.o Dia.o Asignacion.o
CC=g++
MYCXXFLAGS=-I./ -I../source/CommonFiles/
default: $(EXE) $(EXE1) $(EXE2)
$(EXE):DNombreDia.o $(ARCHIVOSOBJETO) main.o
	$(CC) -I./ $^ -o $@
$(EXE1):mainA.o DNombreDia.o $(ARCHIVOSOBJETO)
	$(CC)  $^ -o $@
$(EXE2):testCdD.o CdD.o DNombreDia.o $(ARCHIVOSOBJETO)
	$(CC)  $^ -o $@
DNombreDia.o:DNombreDia.cpp
	$(CC) -DUSAR_STRING $(MYCXXFLAGS) -c $< -o $@
main.o:main.cpp
	$(CC) $(MYCXXFLAGS) -c $< -o $@
mainA.o:main.cpp
	$(CC) -DLMC1 $(MYCXXFLAGS) -c $< -o $@
gettingdate.o:../source/CommonFiles/gettingdate.c
	$(CC) -c $^ -o $@
Calendario.o:../source/CommonFiles/Calendario.cpp
	$(CC) -DUSAR_STRING -DLEAPYEAR -I./ -c $< -o $@
Dia.o:../source/CommonFiles/Dia.cpp
	$(CC) -DADS_PLANNING -c $< -o $@
Asignacion.o:../source/CommonFiles/Asignacion.cpp
	$(CC) -I./ -c $< -o $@
#######################################################
CdD.o:CdD.cpp
	$(CC) -DLEAP_YEAR -c $< -o $@
testCdD.o:testCdD.cpp
	$(CC) $(MYCXXFLAGS) -c $< -o $@
clean:
	rm -v $(LIMPIEZA)


