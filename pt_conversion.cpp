#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <iostream>

using namespace std;

int main (int argc, char *argv[])
{
    try
    {
    	boost::property_tree::ptree pt;
        boost::property_tree::read_json(argv[1], pt);

		boost::property_tree::write_xml(std::cout, pt);

		std::cout << endl;
    }
    catch (std::exception const& e)
    {
        std::cerr << e.what() << std::endl;
    }


	return 0;
}
