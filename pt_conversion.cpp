#include <iostream>
#include <fstream>
#include <string>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/algorithm/string/replace.hpp>
#include <boost/foreach.hpp>

#ifndef SIGCLD
#   define SIGCLD SIGCHLD
#endif


using namespace std;
using boost::property_tree::ptree;

string sanitize_xml_name(string input) 
{
    string output;

    output = boost::replace_all_copy(input, "&", "&amp;");
    boost::replace_all(output, "\'", "&apos;");
    boost::replace_all(output, "\"", "&quot;");
    boost::replace_all(output, "<", "&lt;");
    boost::replace_all(output, ">'", "&gt;");
   
    if (!isalpha(output[0]))
    {
        output[0]='a';
    }

    return output;
}

string convertToXml(ptree& pt, string nodeKey)
{
	string xml = "";
	string elementName = sanitize_xml_name(nodeKey);


	xml = "<" + elementName + ">";

	if (pt.empty())
    {
		xml += pt.data();
	}
	else 
    {
		for (ptree::iterator it = pt.begin(); it != pt.end();)
        {
			string childKey = it->first;
			if (childKey == "") 
            {
				childKey = elementName + "_child";
			}

			xml += convertToXml(it->second, childKey);
			it++;
		}
	}

	xml += "</" + elementName + ">";
	return xml;
}

extern "C"
int convert_json_to_xml(char* in, char* out)
{
    ofstream outfile;
    int rv;

    outfile.open(out);
    
    try
    {
    	ptree pt;
		
        read_json(in, pt);
        
        outfile << "<?xml version=\"1.0\" encoding=\"utf-8\"?>";
        outfile << convertToXml(pt, "root");
        
        //boosts internal xml writer proved unable to reliably output valid xml 
        //sanitize_tree(pt,"");
        //write_xml(out, pt);
		outfile.close();
        rv = 0;
    }
    catch (std::exception const& e)
    {
        outfile << "<err>There was a problem parsing the given JSON file, please try another</err>";
        std::cerr << e.what() << std::endl;
        rv = -1;
    }

	return rv;
}
