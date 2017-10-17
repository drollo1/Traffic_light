all: Driver.o Vehicle.o IntersectionFlowRate.o TrafficSim.o LinkedList.o
	g++ -Wall Driver.o Vehicle.o IntersectionFlowRate.o TrafficSim.o LinkedList.o   -o Driver.out

LinkedList.o: LinkedList.cpp
	g++ -Wall -c LinkedList.cpp

TrafficSim.o: TrafficSim.cpp
	g++ -Wall -c TrafficSim.cpp

IntersectionFlowRate.o: IntersectionFlowRate.cpp
	g++ -Wall -c IntersectionFlowRate.cpp

Vehicle.o: Vehicle.cpp
	g++ -Wall -c Vehicle.cpp

Driver.o: Driver.cpp
	g++ -Wall -c Driver.cpp

run: 
	./Driver.out $(CLEAR) $(INPUT)
# -f removes any errors if the file is not present
clean:
	rm -rf *.o
	rm -f Driver.out
	rm -f *~ *.h.gch *#
