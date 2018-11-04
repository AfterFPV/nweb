#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/xml_parser.hpp>

#ifndef SIGCLD
#   define SIGCLD SIGCHLD
#endif

extern "C"

int convert_json_to_xml(char* in, char* out)
{
    try
    {
    	boost::property_tree::ptree pt;
        boost::property_tree::read_json(in, pt);

		boost::property_tree::write_xml(out, pt);
    }
    catch (std::exception const& e)
    {
        std::cerr << e.what() << std::endl;
    }

	return 0;
}
