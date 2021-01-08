import bridges.connect.Bridges;
import bridges.base.SLelement;
import java.util.Iterator;

//
// In part 2 of this tutorial we demonstrate how we can style the nodes and links
// of the singly linked list  and displays them
//
// Reference: SLelement, Bridges classes, ElementVisualizer, LinkVisualizer, Color
//
public class tut_sllist_p2 {

	public static void main(String[] args) throws Exception {

		// Create Bridges object,  fill in credentials
#if TESTING

		Bridges bridges = new Bridges(Integer.parseInt(args[0]), args[1], args[2]);
		bridges.setServer(args[3]);
#else
		Bridges bridges = new Bridges(YOUR_ASSIGNMENT_NUMBER, "YOUR_USER_ID",
			"YOUR_API_KEY");
#endif
		// set title
		bridges.setTitle("A Single Linked List Example");

		// set  description
		bridges.setDescription("A singly linked list of 4 nodes with names; the nodes in this example use string as the generic type"); 

		// create the linked list elements with student names
		SLelement<String>  st0 = new SLelement<String> ("Gretel Chaney");
		SLelement<String>  st1 = new SLelement<String> ("Lamont Kyler");
		SLelement<String>  st2 = new SLelement<String> ("Gladys Serino");
		SLelement<String>  st3 = new SLelement<String> ("Karol Soderman");
		SLelement<String>  st4 = new SLelement<String> ("Starr McGinn");

		//  link the elements
		st0.setNext(st1);
		st1.setNext(st2);
		st2.setNext(st3);
		st3.setNext(st4);

		// we want to see these names in the visualization so we will set them as
		// the nodes' labels. We will retrieve the nodes' generic data for the label
		st0.setLabel(st0.getValue());
		st1.setLabel(st1.getValue());
		st2.setLabel(st2.getValue());
		st3.setLabel(st3.getValue());
		st4.setLabel(st4.getValue());

		// now we want to style the nodes and links to illustrate the visual
		// attributes that can be applied to elements and links between links
		// Elements have color, opacity, shape and opacity attributes. Links
		// have color, thickness and label attributes

		// set colors for list elements - see the Color class for supported colors
		st0.setColor("red");
		st2.setColor("aliceblue");

		// color the links - must specify a valid terminating element
		st0.getLinkVisualizer(st1).setColor("green");
		st3.getLinkVisualizer(st4).setColor("magenta");

		// adjust link thickness
		st2.getLinkVisualizer(st3).setThickness(5.0f);

		// set node transparency
		st4.setOpacity (0.5f);

		// set link labels
		st0.getLinkVisualizer(st1).setLabel("Gretel Chaney --> Lamont Kyler");

		// set shape of node
		st2.setShape("square");
		st4.setShape ("triangle");

		// tell Bridges the head of the list
		bridges.setDataStructure(st0);

		// visualize the linked list (hit the key 'l' on the visualzation to see all labels
		bridges.visualize();
	}
}
