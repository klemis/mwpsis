#include <iostream>
#include <vector>
#include <string>

#include "cgicc/CgiDefs.h"
#include "cgicc/Cgicc.h"
#include "cgicc/HTTPHTMLHeader.h"
#include "cgicc/HTMLClasses.h"

#include <stdio.h>
#include <stdlib.h>

using namespace std;
using namespace cgicc;   

int main(int argc, char **argv)
{
    try {
       Cgicc formData;

       cout << HTTPHTMLHeader() << endl;

       cout << HTMLDoctype(HTMLDoctype::eStrict) << endl;

       cout << html().set("lang", "EN").set("dir", "LTR") << endl;

       cout << html() << head() << title("Optical Networks") << head() << endl;
       cout << body().set("bgcolor","#FFFFCC").set("text","#000000").set("link","#0000ff").set("vlink","#000080") << endl;

       cout << h1("Results") << endl;

       form_iterator fvalue1 = formData.getElement("value1");
       form_iterator fvalue2 = formData.getElement("value2");
       form_iterator fvalue3 = formData.getElement("value3");
       
       // cout << h1(**fvalue1);
       // cout << h1(**fvalue2);
       // cout << h1(**fvalue3);


       if( !fvalue1->isEmpty() && !fvalue2->isEmpty() && !fvalue3->isEmpty()) {
	       string command = "/home/camel/MwPSiS-Projekt-swiatlowody/setup.sh";
	       command = command + " " + **fvalue1 + " " + **fvalue2 + " " + **fvalue3;
	       system(command.c_str());
       }
       else
          cout << "No text entered" << endl;

       cout << p();

       cout << body() << html();
    }
    catch(exception& e) {
       cout << "ERROR!!" << endl;
    }
    return 0;
}
      
