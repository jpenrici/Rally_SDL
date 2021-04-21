# Makefile

SVGMANAGER_PATH = ../SVG_Manager/src/

speedometer : speedometer.o svg_manager.o
	g++ -g -Wall -o Create_svg_speedometer speedometer.o svg_manager.o

speedometer.o : speedometer.cpp $(SVGMANAGER_PATH)svg_manager.h
	g++ -g -Wall -c speedometer.cpp -I $(SVGMANAGER_PATH)
	
svg_manager.o : $(SVGMANAGER_PATH)svg_manager.cpp $(SVGMANAGER_PATH)svg_manager.h
	g++ -g -Wall -c $(SVGMANAGER_PATH)svg_manager.cpp

clean:
	rm -f Create_svg_speedometer *.o
