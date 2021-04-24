# Makefile

SVGMANAGER_PATH = ../SVG_Manager/src/

all :
	make odometer
	make speedometer

odometer : create_odometer.o svg_manager.o
	g++ -g -Wall -o Create_svg_odometer create_odometer.o svg_manager.o

create_odometer.o : create_odometer.cpp $(SVGMANAGER_PATH)svg_manager.h counter.h
	g++ -g -Wall -c create_odometer.cpp -I $(SVGMANAGER_PATH)

speedometer : create_speedometer.o svg_manager.o
	g++ -g -Wall -o Create_svg_speedometer create_speedometer.o svg_manager.o

create_speedometer.o : create_speedometer.cpp $(SVGMANAGER_PATH)svg_manager.h
	g++ -g -Wall -c create_speedometer.cpp -I $(SVGMANAGER_PATH)
	
svg_manager.o : $(SVGMANAGER_PATH)svg_manager.cpp $(SVGMANAGER_PATH)svg_manager.h
	g++ -g -Wall -c $(SVGMANAGER_PATH)svg_manager.cpp

clean:
	rm -f Create_svg_odometer Create_svg_speedometer *.o
