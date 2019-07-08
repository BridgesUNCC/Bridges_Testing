#include "Bridges.h"
#include "SymbolCollection.h"
#include "Rectangle.h"
#include "Polygon.h"
#include "Circle.h"
#include "Label.h"

using namespace bridges;

int main(int argc, char **argv) {
#if TESTING
	// command line args provide credentials and server to test on
	//Bridges *bridges =  new Bridges(atoi(argv[1]), argv[2], argv[3]);

    Bridges bridges (atoi(argv[1]), argv[2], argv[3]);
    
    if (argc > 4)
        bridges.setServer(argv[4]);

	bridges.set_title("Symbol Collection");
	bridges.set_description("Red square, green circle, magenta horizontal and vertical lines, "
				"and a test label with a purple outline.");
			
#else
    Bridges bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID",
                                "YOUR_API_KEY");
#endif

	SymbolCollection sc; 
	Rectangle s1(-25, 0, 50, 50);
	s1.setFillColor(Color("red"));
	sc.addSymbol(&s1);

	Circle s2(25, 0, 25);
	s2.setFillColor(Color("green"));
	sc.addSymbol(&s2);
	
	Polygon s3;

	s3.addPoint(-100, 0);
	s3.addPoint(100, 0);
	s3.addPoint(0, 0);
	s3.addPoint(0, -100);
	s3.addPoint(0, 100);
	s3.addPoint(0, 0);
	s3.setStrokeColor(Color("magenta"));
	sc.addSymbol(&s3);

	Label l;
	l.setLocation(0,25);
	l.setFontSize(12);
	l.setStrokeWidth(1.0f);
	l.setLabel("test label");
	l.setStrokeColor(Color("purple"));
	sc.addSymbol(&l);

	// set visualizer type

	bridges.setDataStructure(sc);
				// visualize the JSON and Collection
	bridges.visualize();
			
	return 0;
}
