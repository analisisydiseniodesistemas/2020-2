EXE0:=00_Planeacion_EDO_EJ2020.exe
OBJETOSA:=CalendarioA.o ActividadA.o AsignacionA.o DiaA.o util.o
CC=g++
CXXFLAGS +=-DCAL_GREGORIANO -I../CommonFiles/

$(EXE0):$(OBJETOSA) use_Calendario.o bubbles.o EDO_data.o
	$(CC) $^ -o $@
CalendarioA.o:../CommonFiles/Calendario.cpp
	$(CC) -DLEAPYEAR -c $^ -o $@
AsignacionA.o:../CommonFiles/Asignacion.cpp
	$(CC)  -c $^ -o $@
ActividadA.o:../CommonFiles/Actividad.cpp
	$(CC)  -c $^ -o $@
DiaA.o:../CommonFiles/Dia.cpp
	$(CC) -DEDO_PLANNING  -c $^ -o $@
util.o:../CommonFiles/util.cpp
	$(CC) -DLEAPYEAR -c $^ -o $@
gettingdate.o:../CommonFiles/gettingdate.c
	$(CC) -c $^ -o $@
bubbles.o:../CommonFiles/bubbles.cpp
	$(CC) -I../CommonFiles/ -c $^ -o $@
EDO_data.o:EDO_data.cpp
	$(CC) -I../CommonFiles/ -c $<
clean:
	rm -v *.o *.exe *.stackdump
