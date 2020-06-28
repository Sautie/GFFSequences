#include <fstream>


#include "GeneGFF.cpp"
//============================================================================
// Name        : GeneGFF.cpp
// Author      : Miguel Sauti�-Castellanos
// Version     : 2
// Description : Driver program developp� pour le traitement des fichiers en format GFF
//
//============================================================================
//programme de tamisage: g�nes manquants et tamisage par nombre d'exons
using namespace std;

int main(int argc, char** argv) {
	vector<string> v;
	vector<vector<string> > vv;
	GeneGFF g;
	string line1;

	string  path0="D:/DB/grupo3/";
	string  pathIN=path0+"MatrixExons14nIDt.matexon";
	string	pathOut=path0+"MatrixExons14n.filtrex";  // matrice tamis�e selon nombre egal d'exons et g�nes manquants dans gff/liste d'orthologues
	const unsigned int L=14;
	ifstream myfile(pathIN.c_str());
	ofstream myfileout(pathOut.c_str());

	 while(getline(myfile, line1))
			{
	            g.GeneSplit(v, line1, "\t");
				if ((g.Gmanquants (v,L))&& (g.FNexons (v,L)) ){ //

				  myfileout<<line1<<endl;
				                                   }
				  v.clear();
			}

	myfileout.close();
	return 0;
}
