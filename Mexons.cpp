#include <fstream>


#include "GeneGFF.cpp"

//============================================================================
// Name        : GeneGFF.cpp
// Author      : Miguel Sautié-Castellanos
// Version     : 2
// Description : Driver program developpé pour le traitement des fichiers en format GFF
//
//============================================================================


using namespace std;


int main(int argc, char** argv) {
	  vector<string> v;
      vector<vector<string> > vv;

	  vector<vector<string> > vvv;
      GeneGFF g;
      string path0="D:/DB/nuevos grupos/grupo3/";

	  string ext=".intron";
      string	pathIn1=path0+"48birds_ortholog14n.list";

	  string line1, name, name1;
	  const unsigned int L=14, ESPECIE=13;

	  unsigned int cc=0, rr=0;
      ifstream myfile(pathIn1.c_str()); //liste d'gènes orthologues lista filtré par absence/presence et une copie

     string paths[]= {"Calypte_anna","Struthio_camelus.OM.gene.20130116","Aptenodytes_forsteri","ap_v6.mega.fa", "Nipponia_nippon", "Chaetura_pelagica", "Egretta_garzetta","Corvus_brachyrhynchos","Charadrius_vociferus","Picoides_pubescens","Cuculus_canorus", "Anas_platyrhynchos","Geospiza_fortis.gene","Manacus_vitellinus"};

     string	pathIn2=path0+paths[ESPECIE]+ext;
	 ifstream myfile2(pathIn2.c_str());

	 string	pathOut=path0+paths[ESPECIE]+".matexon";
	 ofstream myfileout(pathOut.c_str());


    while(getline(myfile, line1))
			{
	            g.GeneSplit(v, line1, "\t");	            //matrix orthologs
	                vector<string> row;
	             for (int j = 0; j < L; j++) {
                      row.push_back(v[j]);
                                     }
                  vv.push_back(row);
				  v.clear(); cc++;

	        }

      string line;

    while(getline(myfile2, line))
			{
	        g.GeneSplit(v, line, " ");
	              vector<string> row;  //matrix .intron
	             //for (int j = 0; j < v.size(); j++) {
                      row.push_back(v[0]);
					   row.push_back(v[(v.size()-1)]);
                                    // }
                  vvv.push_back(row);
				  v.clear();rr++;
	        }
           	myfile2.close();
            cout<<rr<<endl;
            cout<<cc<<endl;

       for (unsigned int i = 0; i < cc; i++)
	            {
				name=vv[i][ESPECIE].substr (0,11);    //matrix orthologs

	         for (unsigned int ii = 0; ii < rr; ii++)  {

		         if (name==vvv[ii][0])  {
		         cout<<name<<endl;

		           myfileout<<name<<"\t"<<vvv[ii][1]<<endl;

		         break;
		            }
		            if (ii==rr-1){ myfileout<<name<<"\t"<<"0"<<endl; cout<<ii<<endl;}

		          }

	            }

	myfile2.close();
	myfileout.close();
	return 0;
}


