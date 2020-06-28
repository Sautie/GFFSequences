#include <fstream>


#include "Gene.cpp"

using namespace std;

//============================================================================
// Name        : GeneGFF.cpp
// Author      : Miguel Sautié-Castellanos
// Version     : 2
// Description : Driver program developpé pour le traitement des fichiers en format GFF
//
//============================================================================


//elimine les groupes d'orthologues qui ont valeurs manquantes et gènes repetés


int main(int argc, char** argv) {


	    string  line;
	    Gene g;
		unsigned int L=14;
	    string	pathIn="D:/DB/48birds_ortholog.list";

	    string pathOut="D:/DB/48birds_ortholog14n.list";
	    //string p[] ={"CALAN","STRCA","PYGAD","CORBR","CHAVO","PICPU","CUCCA","ANAPL"};
		//string p[]= {"CALAN","STRCA","PYGAD","MELUN", "NIPNI","CORBR","CHAVO","PICPU","CUCCA","ANAPL"};
		string p[]= {"CALAN","STRCA","APTFO","MELUN","NIPNI","CHAPE","EGRGA","CORBR","CHAVO","PICPU","CUCCA","ANAPL","GEOFO","MANVI"};

		ifstream myfile(pathIn.c_str());
		ofstream myfileout(pathOut.c_str());//+PICPU ANAPL (inter (line , "PICPU"))&&(inter (line , "ANAPL"))	&&(inter(line,p[8]))&&(inter(line,p[9]))

	while(getline(myfile, line))
			{
		   if ((g.inter (line , p[0]))&&(g.inter (line , p[1]))&&(g.inter (line , p[2]))&&(g.inter(line,p[3]))&&(g.inter(line,p[4]))&& (g.inter(line,p[5]))&&(g.inter(line,p[6]))&&(g.inter(line,p[7]))&&(g.inter(line,p[8]))&&(g.inter(line,p[9]))&&(g.inter(line,p[10]))&&(g.inter(line,p[11]))&&(g.inter(line,p[12]))&&(g.inter(line,p[13])) )
		       {
			for (int i = 0; i < L; i++){
	                //extraccion de identificador
                    myfileout<<g.ExtString(line,p[i])<<"\t";
					                   }
				myfileout<<endl;
				}
			}
			//myfileout2.close();
	myfileout.close();
	return 0;
}


