#include <string>
#include "Bridges.h"
#include "TreeElement.h"

using namespace std;
using namespace bridges;

int main(int argc, char **argv) {

#if TESTING
                        // command line args provide credentials and server to test on
    //Bridges *bridges =  new Bridges(atoi(argv[1]), argv[2], argv[3]);
    Bridges bridges (atoi(argv[1]), argv[2], argv[3]);
    
    if (argc > 4)
        bridges.setServer(argv[4]);

	bridges.setTitle("A General Tree Example");
	bridges.setDescription("A basic tree with seven nodes. Three on one side and three on the other. The root node is set to red with 0.3 opacity. "
				"The other six nodes are neutral color.");
			
#else
    Bridges bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID",
                                "YOUR_API_KEY");
#endif

	TreeElement<string> *t0 = new TreeElement<string>("Hello", "Hello");
	TreeElement<string> *t2 = new TreeElement<string>("This", "This");
	TreeElement<string> *t3 = new TreeElement<string>("is", "is");
	TreeElement<string> *t4 =  new TreeElement<string>("a", "a");
	TreeElement<string> *t5 =  new TreeElement<string>("generic", "generic");
	TreeElement<string> *t6 =  new TreeElement<string>("Tree", "Tree");
	TreeElement<string> *t7 =  new TreeElement<string>("Representation", "Representation");

	// put in labels for each node; we simply use integers


	t0->setLabel(t0->getValue());
	t2->setLabel(t2->getValue());
	t3->setLabel(t3->getValue());
	t4->setLabel(t4->getValue());
	t5->setLabel(t5->getValue());
	t6->setLabel(t6->getValue());
	t7->setLabel(t7->getValue());

	// add links to children

	t0->addChild(t2);
	t0->addChild(t3);
	t0->addChild(t4);
	t2->addChild(t5);
	t2->addChild(t6);
	t3->addChild(t7);

	// set some visual attributes

	t0->getVisualizer()->setColor(Color("red"));
	t0->getVisualizer()->setOpacity(0.3f);

	// provide BRIDGES the  handle to the tree structure
	bridges.setDataStructure(t0);

	bridges.visualize();

	return 0;
}
