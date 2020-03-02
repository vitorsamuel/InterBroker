#include "xmlprocessor/rapidxml.hpp"
#include "xmlprocessor/rapidxml_utils.hpp"
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <string>

using namespace std;
using namespace rapidxml;

extern "C" int xmlProcess(char*);


int xmlProcess(char* message)
{
	string str(message);

	printf(message);

	vector<char> xml_copy(str.begin(), str.end());
	xml_copy.push_back('\0');

	xml_document<> doc;
	doc.parse<parse_declaration_node | parse_no_data_nodes>(&xml_copy[0]);

	cout << "Name of my first node is: " << doc.first_node()->name() << "\n";

	string encoding = doc.first_node()->first_attribute("encoding")->value();
	cout << "encoding: " << encoding << endl;

	//rapidxml::xml_node<>* node = doc.allocate_node(*/

	/*for (xml_node<> *child = node->first_node(); child; child = child->next_sibling())
	{
			// do stuff with child
	}*/

	return 0;
}

