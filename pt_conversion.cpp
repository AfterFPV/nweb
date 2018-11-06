#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/xml_parser.hpp>

#ifndef SIGCLD
#   define SIGCLD SIGCHLD
#endif

extern "C"

int convert_json_to_xml(char* in, char* out)
{
    int rv;
    
    try
    {
    	boost::property_tree::ptree pt;

        pt.put("root","");
        boost::property_tree::read_json(in, pt.get_child("root"));

		boost::property_tree::write_xml(out, pt);

        rv = 0;
    }
    catch (std::exception const& e)
    {
        std::cerr << e.what() << std::endl;
        rv = -1;
    }

	return rv;
}
