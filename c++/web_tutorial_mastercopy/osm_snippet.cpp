#include "Bridges.h"
#include "DataSource.h"
#include "GraphAdjList.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include <fstream>
#include "data_src/OSMData.h"
#include "data_src/OSMVertex.h"
#include "data_src/OSMEdge.h"

using namespace std;
using namespace bridges;

int main(int argc, char **argv) {

	// create Bridges object
#if TESTING
	// command line args provide credentials and server to test on
	Bridges bridges (atoi(argv[1]), argv[2], argv[3]);

	if (argc > 4)
		bridges.setServer(argv[4]);

	bridges.setTitle("An Open Street Map Example");
	bridges.setDescription("Illustrates the road map of the UNC Charlotte Campus.");

#else
	Bridges bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY");
#endif

	DataSource ds(bridges);
	OSMData osm_data = ds.getOSMData("Charlotte, North Carolina");
	
	vector<OSMVertex> vertices = osm_data.getVertices();
	vector<OSMEdge> edges = osm_data.getEdges();

	double coords[2];
	cout << "Number of Vertices [Charlotte]:" << vertices.size() << endl;
	cout << "Number of Edges [Charlotte]:" << edges.size() << endl;

	// get cartesian coordinate  location of first vertex
	osm_data.getVertices()[0].getCartesianCoords(coords);
	cout << "Location of first vertex [Cartesian Coord]: " <<  coords[0] << ","
		<< coords[1] << endl;
	return 0;
}
