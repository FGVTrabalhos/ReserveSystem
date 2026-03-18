CXXFLAGS = 

prog: ReservationSystem.o ReservationRequest.o list.o
	g++ $(CXXFLAGS) main.cpp -o prog ReservationSystem.o ReservationRequest.o list.o

ReservationSystem.o: ReservationSystem.cpp ReservationSystem.hpp ReservationRequest.hpp list.hpp
	g++ $(CXXFLAGS) -c ReservationSystem.cpp

ReservationRequest.o: ReservationRequest.cpp ReservationRequest.hpp
	g++ $(CXXFLAGS) -c ReservationRequest.cpp

list.o: list.hpp list.cpp ReservationRequest.hpp
	g++ $(CXXFLAGS) -c list.cpp

clean:
	rm -f *.o prog