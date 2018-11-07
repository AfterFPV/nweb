#include <iostream>
#include <fstream>

#include <string>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/foreach.hpp>

#ifndef SIGCLD
#   define SIGCLD SIGCHLD
#endif


using namespace std;
using boost::property_tree::ptree;

void traverse_tree(ptree &pt, string key)
{
    string nkey;
    string mykey;
    string val;
    ofstream myfile;
    ptree tmp_tree;


    if (!key.empty())
    {
        nkey = key + ".";
    }
    
    for (ptree::iterator pos = pt.begin(); pos != pt.end(); ++pos)
    {
        mykey = pos->first;
        if(mykey.empty()) 
        {
            myfile.open ("help.txt", ios::out | ios::app);
            myfile << key << "> " << pos->first << ": " << pos->second.data() << endl;
            //myfile << pos << " " << pos->first << ": " << pos->second.data() << endl;
            myfile.close();
            pt.insert(pos, make_pair("element", pos->second));
        }
        traverse_tree(pos->second, nkey + pos->first);
    }

    pt.erase("");
}


string convertToXml(ptree& pt, string nodeKey) {
	string xml = "";
	string elementName = nodeKey;

	xml = "<" + elementName + ">";

	if (pt.empty()) {
		xml += pt.data();
	}
	else {
		for (ptree::iterator it = pt.begin(); it != pt.end();) {
			string childKey = it->first;
			if (childKey == "") {
				childKey = nodeKey + "_child";
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

    try
    {
    	ptree pt;
		
		//pt.put("root","");
        read_json(in, pt);
        
        //traverse_tree(pt, "");

        outfile.open(out);
        outfile << convertToXml(pt, "root");
        //write_xml(out, pt);
		outfile.close();
        rv = 0;
    }
    catch (std::exception const& e)
    {
        std::cerr << e.what() << std::endl;
        rv = -1;
    }

	return rv;
}
