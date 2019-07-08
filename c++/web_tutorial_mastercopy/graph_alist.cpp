#include <string>
#include "Bridges.h"
#include "DataSource.h"
#include "data_src/ActorMovieIMDB.h"
#include "GraphAdjList.h"

using namespace std;
using namespace bridges;

int main(int argc, char **argv) {
#if TESTING
                        // command line args provide credentials and server to test on
    //Bridges *bridges =  new Bridges(atoi(argv[1]), argv[2], argv[3]);
    Bridges bridges (atoi(argv[1]), argv[2], argv[3]);
    
    if (argc > 4)
        bridges.setServer(argv[4]);

	// set a title for the visualization
	bridges.set_title("A Simple Graph (Adjacency List) Example using IMDB Actor/Movie Data");
	bridges.set_description("Two lists each having an actor as the root node with 15 movies they played in as leaf nodes. "
				"Root nodes are both red, Kevin Bacon's leaf nodes are green and Denzel Washington's leaf nodes are neutral.");
			
#else
    Bridges bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID",
                                "YOUR_API_KEY");
#endif

	DataSource *ds = new DataSource;
	vector<ActorMovieIMDB> actor_list = ds->getActorMovieIMDBData(1813);

	GraphAdjList<string, string, int> graph;


	// first create vertices for two actors
	string bacon = "Kevin_Bacon_(I)", washington = "Denzel_Washington";
	// add them to the graph
	graph.addVertex(bacon, "");
	graph.addVertex(washington, "");

	// color the nodes
	graph.getVertex(bacon)->setColor("red");
	graph.getVertex(washington)->setColor("red");

	graph.addEdge(bacon, washington, 1);

	// we will find the first 15 immediate neighbors of of the two actors
	// and color those links and nodes by followng their adjacency lists
	int cnt1 = 0, cnt2 = 0;
	for (int k = 0; k < actor_list.size(); k++) {
		// from the actor movie data, get an actor-movie pair
		string a = actor_list.at(k).getActor();
		string m = actor_list.at(k).getMovie();

		if ((a == "Kevin_Bacon_(I)") && (cnt1 < 15)) {

			// add vertices for this movie  and an edge for the link
			graph.addVertex(m, "");
			graph.addEdge(bacon, m, 1);
			graph.addEdge(m, bacon, 1);

			// make the movie node a bit transparent
			graph.getVertex(m)->setOpacity(0.5f);
			cnt1++;
		}
		else if ((a == "Denzel_Washington") && (cnt2 < 15)) {
			// add vertices for this movie  and an edge for the link
			graph.addVertex(m, "");
			graph.addEdge(washington, m, 1);
			graph.addEdge(m, washington, 1);
			// make the movie node a bit transparent
			graph.getVertex(m)->setOpacity(0.5f);
			cnt2++;
		}
	}


	// Next, we illustrate traversing the adacency list and color the
	// movie nodes adjacent to the Kevin Bacon node.

	// we will use iterators to traverse the adjacency list

	for (auto& edge: graph.outgoingEdgeSetOf(bacon)) {
		string from = edge.from(), to = edge.to();	
		if (to != "Denzel_Washington")
			graph.getVisualizer(to)->setColor("green");	
	}

/*
	SLelement<Edge<string>>  *head = graph.getAdjacencyList().at(bacon);
	// traverse the adjacency list
	for (SLelement<Edge<string>> *sle = head; sle != nullptr;
		sle = sle->getNext() ) {
		// get the terminating vertex
		string term_vertex = sle->getValue().getVertex();
		// find the corresponding element
		Element<string> *el = graph.getVertex(term_vertex);
		// set the  color of the node except the Denzel W. node
		if (term_vertex != "Denzel_Washington")
			el->setColor(Color("green"));
	}
*/

	// provide BRIDGES the  handle to the tree structure
	bridges.setDataStructure(&graph);
	// Visualize the graph
	bridges.visualize();

	return 0;
}
