#include "Bridges.h"
#include "DataSource.h"
#include <iostream>
#include <string>
#include "data_src/ElevationData.h"

using namespace std;
using namespace bridges;

int main(int argc, char **argv) {

	// create Bridges object
#if TESTING
	// command line args provide credentials and server to test on
	Bridges bridges (atoi(argv[1]), argv[2], argv[3]);

	if (argc > 4)
		bridges.setServer(argv[4]);

	bridges.setTitle("An Elevation Map Dataset Example");
#else
	Bridges bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY");
#endif

	//create the Bridges object, set credentials

	bridges.setServer("clone");

	DataSource ds;
	dataset::ElevationData *elev_data;
	try {
		elev_data = ds.getElevationData(6.020558108041891,46.10757941505641,
						9.707863253414155,47.77059916141684, 0.02);
	}
	catch (std::string s) {
		std::cerr << "Exception: " << s << "\n";
	}

	// print the data dimensions  and the firs 10 elevation data values
	cout << "\tWidth: " << elev_data->getCols() << endl
		<< "\tHeight: " << elev_data->getRows() << endl
		<< "\tResolution: " <<  elev_data->getCellSize() << endl 
		<< "\tLower Left Corner: "  << elev_data->getxll()  << 
				 ", " <<  elev_data->getyll() <<endl;

	cout << "The first 10 elevation values.." << endl;
	for (int k = 0; k < 10; k++)
		cout << elev_data->getVal(0, k) << "  " << endl;
	cout << endl;

	return 0;
}
