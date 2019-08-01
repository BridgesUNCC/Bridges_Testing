from bridges.bridges import *
from bridges.array import *
import sys

def main():
    args = sys.argv[1:]

    # create the Bridges object, set credentials
#if TESTING             
    # command line args provide credentials and server to test on
    bridges = Bridges(int(args[0]), args[1], args[2])
    if len(args) > 3:   
        bridges.connector.set_server(args[3])
#else                   
    bridges = Bridges(YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY");
#endif 

    #Bridges title, description 
    bridges.set_title("Two-Dimensional Array Example")
    bridges.set_description("Illustrates a 2D array with visual attributes");


    # for 2D array 6x6
    num_rows = 6
    num_cols = 6
    my_array = Array(y_dim = num_rows, x_dim = num_cols)

    #populate the array
    for row in range(num_rows):
        for col in  range(num_cols):
            my_array[row, col].label = "El " + str(row*num_cols + col);

    #color some of the elements
    my_array[0, 0].color = "red"
    my_array[0, 3].color = "green"
    my_array[5, 0].color = "blue"
    my_array[5, 3].color = "magenta"
    my_array[1, 1].color = "cyan"
    my_array[2, 2].color = "yellow"

    #set visualizer type
    bridges.set_data_structure(my_array)

    #visualize tha array
    bridges.visualize()

if __name__ == "__main__":
    main()

