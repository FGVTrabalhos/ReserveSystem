CXXFLAGS = 

prog: ReservationSystem.o ReservationRequest.o
	g++ $(CXXFLAGS) main.cpp -o prog ReservationSystem.o ReservationRequest.o

ReservationSystem.o: ReservationSystem.cpp ReservationSystem.hpp ReservationRequest.hpp
	g++ $(CXXFLAGS) -c ReservationSystem.cpp

ReservationRequest.o: ReservationRequest.cpp ReservationRequest.hpp
	g++ $(CXXFLAGS) -c ReservationRequest.cpp

clean:
	rm -f *.o prog