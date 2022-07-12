from bridges.bridges import *
import sys
from bridges.data_src_dependent import data_source

#how to use the USCities Dataset
def main():
    args = sys.argv[1:]

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

    # create the Bridges object, set credentials

    bridges = Bridges(int(args[0]), args[1], args[2])

    if len(args) > 3:
        bridges.connector.set_server(args[3])

    #-the function can take 6 parameters
    #-ommiting all parameters will return all results in db
    #-these parameters can be used in any combination to filter results further
    
    #int: limit - which is to limit the number of results returned
    #str: state - get only results with this state. the state must be the Acronym ex: NC, NV, CA...etc
    #int: elevation - get only results with elevation greater than this number
    #int: population - get only results with populationg greater than this number
    
    #you can pass a min lat long and max lat long parameter to get only results within a latlong bounding box:

    #list: minll - is the minimum lat and long value for bounding box ex: minll = [34.025348,-85.352783]
    #list: maxll - is the maximum lat and long value for bounding box ex: maxll = [36.800488,-75.300293]
    #

    # omitting all arguments will get all data within the database
    # cities_data = data_source.get_us_cities_data()

    #getting a limit of 5 results
    # cities_data = data_source.get_us_cities_data(limit = '5')

    #getting only results from NC
    # cities_data = data_source.get_us_cities_data(state = 'NC')

    #getting only results with elevation greater than 100
    # cities_data = data_source.get_us_cities_data(elevation = '100')

    #getting only results with population greater than 2000
    # cities_data = data_source.get_us_cities_data(population = '2000')

    #getting only results within a NC bounding box
    #cities_data = data_source.get_us_cities_data(minll = '[34.025348,-85.352783]', maxll = '[36.800488,-75.300293]')

    #cities_data = data_source.get_us_cities_data(limit = 10, min_pop=2000000)

    #combining all parameters
    cities_data = data_source.get_us_cities_data(limit = 25, state = 'NC', min_elev= -100, min_pop =  10000, max_pop = 1000000, minll = [34.025348,-85.352783], maxll = [36.800488,-75.300293])
    for c in cities_data:
       print(c.city + ", " + c.state + ": population: " + str(c.population) + ", " + "elevation: " + str(c.elevation) + ", lat/long: " + str(c.lat) + "," + str(c.lon))

    print ("\nCities with negative elevation..\n");

    cities_data2 = data_source.get_us_cities_data(limit='25', min_elev='-100', max_elev='0')
    for c in cities_data2:
       print(c.city + ", " + c.state + ": population: " + str(c.population) + ", " + "elevation: " + str(c.elevation) + ", lat/long: " + str(c.lat) + "," + str(c.lon))


if __name__ == '__main__':
    main()
