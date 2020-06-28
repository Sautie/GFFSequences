
#include <fstream>


#include "Gene.cpp"

//============================================================================
// Name        : GeneGFF.cpp
// Author      : Miguel Sautié-Castellanos
// Version     : 2
// Description : Driver program developpé pour le traitement des fichiers en format GFF
//
//============================================================================


// output limites d'exons,  nombre d'exons, orientation imprimée mais pas utilisée apres introns.cpp

using namespace std;

//Calypte_anna.exon Struthio_camelus.OM.gene.20130116.exon Aptenodytes_forsteri.exon ap_v6.mega.fa.exon
//Calypte_anna2.intron Struthio_camelus.OM.gene.201301162.intron Aptenodytes_forsteri2.intron
//Chaetura_pelagica.exon Cuculus_canorusOut1.exon Egretta_garzetta2.intron Egretta_garzetta.exon Anas_platyrhynchos.exon
//Nipponia_nippon2.intron ap_v6.mega.fa2.intron Chaetura_pelagica2.intron Picoides_pubescens2.intron Picoides_pubescens.exon

int main(int argc, char** argv) {

	vector<string> v;
    Gene g;
    string line;
	string pathIN="D:/DB/nuevos grupos/grupo3/Chaetura_pelagica.gff";
	string pathOUT="D:/DB/nuevos grupos/grupo3/Chaetura_pelagica.exon";

	ifstream myfile(pathIN.c_str()); //struthio_camelus.OM.gene.20130116.gff
	ofstream myfileout(pathOUT.c_str());

	int  r=0, rr=0,cc=0, num;
		while(getline(myfile, line))
			{
	          g.GeneSplit(v, line, "\t");
	          //	for (int i = 0; i < v.size(); i++) cout<<v[i]<<endl;
	          		if (g.ARN(v[2])){
	          			  g.setID(v[8]);

	          		if (rr!=0) {myfileout<<rr+1<<endl;} //numero de exones del anterior
	          		    g.setOrient(v[6]);
					  	cc=0;rr=0;
						//cout<<name<<endl;
			                         }
	          		else if (g.CDS(v[2]))  {
						if (cc==0)	{
				           g.setLim1(v[3]);
						   g.setLim2(v[4]);
			               cc++;}
				        else{

				       if ((rr==0))
				         {
				           myfileout<<g.getID()<<" ";
			               myfileout<<((g.getOrient()) ? "+":"-")<<" ";
						   myfileout<<g.getLim1s()<<" ";
				           myfileout<<g.getLim2s()<<" ";

						   }
				          myfileout<<v[3]<<" ";
				        myfileout<<v[4]<<" "; rr++;
						         }


			}
                 v.clear();

		}

	myfile.close();
	myfileout.close();

	return 0;
}




