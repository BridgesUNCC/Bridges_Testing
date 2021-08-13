#include "Bridges.h"
#include "SymbolCollection.h"
#include "SymbolGroup.h"
#include "Rectangle.h"
#include "Polyline.h"
#include "Polygon.h"
#include "Circle.h"

using namespace bridges;

int main(int argc, char **argv) {
	// create Bridges object
#if TESTING
	// command line args provide credentials and server to test on
	Bridges bridges (atoi(argv[1]), argv[2], argv[3]);

	if (argc > 4)
		bridges.setServer(argv[4]);

#else
	Bridges bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID",
		"YOUR_API_KEY");
#endif

	// title, description
	bridges.setTitle("Symbol Collection");
	bridges.setDescription("Illustrates using two groups of symbols, transformedat the group level");


	// create some symbols and add to symbol collection
	SymbolCollection sc;

	Rectangle r1(-50, 0, 25, 25);
		r1.setFillColor(Color("red"));
		r1.setOpacity(0.3f);
	
	Rectangle s1(-50, 0, 25, 25);
		s1.setFillColor(Color("orange"));
		s1.setOpacity(1.0f);
	
	// and a circle next to it
	Circle s2(50, 0, 25);
		s2.setFillColor(Color("green"));
		s2.setOpacity(1.0f);

	// create a symbol group and put s1 and s2 into it
	SymbolGroup g;
		g.rotate(50.);
		g.addSymbol(s1);
		g.addSymbol(s2);

	// add the group in the symbol collection 
	sc.addSymbol (g);

	Polygon s3;
		s3.addPoint(-25, -10);
		s3.addPoint(25, -10);
		s3.addPoint(0, 50);
		s3.setStrokeColor("darkorchid");
		s3.setStrokeWidth(2.0f);
		s3.setOpacity(1.0f);

	// draw axes
	Polyline s4;
		s4.addPoint(-100, 0);
		s4.addPoint(100, 0);
		s4.setStrokeColor("magenta");
		s4.setStrokeWidth(2.0f);
		s4.setOpacity(1.0f);

	Polyline s5;
		s5.addPoint(0, -100);
		s5.addPoint(0, 100);
		s5.setStrokeWidth(2.0f);
		s5.setOpacity(1.0f);

	Polygon s6;
		s6.addPoint (-30.0f, 40.0f);
		s6.addPoint (30.0f, 40.0f);
		s6.addPoint (0.0f, 80.0f);
		s6.setStrokeColor("cyan");
		s6.setFillColor("yellow");
		s6.setStrokeWidth(3.0f);
		s6.setOpacity(1.0f);

	SymbolGroup g2;
		g2.scale(0.5);
		g2.translate(100., 0.);
		g2.addSymbol(s3);
		g2.addSymbol(s4);
		g2.addSymbol(s5);
		g2.addSymbol(s6);

	sc.addSymbol(g2);

	// set visualizer type
	bridges.setDataStructure(sc);

	// visualize the JSON and Collection
	bridges.visualize();

	return 0;
}
