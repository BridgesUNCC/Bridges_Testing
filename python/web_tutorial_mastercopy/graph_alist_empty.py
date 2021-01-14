from bridges.graph_adj_list import *
from bridges.bridges import *

import sys


def main():

    # create the Bridges object, set credentials
#if TESTING
    # command line args provide credentials and server to test on
    args = sys.argv[1:]
    bridges = Bridges(int(args[0]), args[1], args[2])
    if len(args) > 3:
        bridges.connector.set_server(args[3])
#else
    bridges = Bridges(YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY")
#endif

    
    # creating a 3 vertices graph with one edge.
    g = GraphAdjList()
    a1 = "Kevin_Bacon_(I)"
    a2 = "Denzel_Washington"
    a3 = "Noone"
    g.add_vertex(a1, "")
    g.add_vertex(a2, "")
    g.add_vertex(a3, "")
    g.add_edge(a1, a2)
    
    # works
    for edge in g.out_going_edge_set_of(a1):
        f = edge.fromv
        to = edge.tov
    
    # does not work
    for edge in g.out_going_edge_set_of(a2):
        f = edge.fromv
        to = edge.tov

    # does not work
    for edge in g.out_going_edge_set_of(a3):
        f = edge.fromv
        to = edge.tov
            
if __name__ == "__main__":
    main()

