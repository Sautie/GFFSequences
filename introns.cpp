
#include <fstream>


#include "GeneGFF.cpp"
//============================================================================
// Name        : GeneGFF.cpp
// Author      : Miguel Sautié-Castellanos
// Version     : 2
// Description : Driver program developpé pour le traitement des fichiers en format GFF
//
//============================================================================

//
// extraire introns selon coordonnées en tenant compte de leurs orientations,
//output *.intron, identificateur, orientation mise en pratique, longueur, nombre d'exons, ordre d'introns selon orientation du gène
//

int main(int argc, char** argv) {
	GeneGFF g;
	vector<string> v;
	int *diff,*diff2;
	diff = new int [100000];
	diff2 = new int [100000];
	string line, name, name1;
	string pathIN="D:/DB/nuevos grupos/grupo3/Chaetura_pelagica.exon";
	string pathOUT="D:/DB/nuevos grupos/grupo3/Chaetura_pelagica.intron";

	ifstream myfile(pathIN.c_str());      //Calypte_anna.exon Struthio_camelus.OM.gene.20130116.exon Aptenodytes_forsteri.exon ap_v6.mega.fa.exon
	ofstream myfileout(pathOUT.c_str());//Calypte_anna2.intron Struthio_camelus.OM.gene.201301162.intron Aptenodytes_forsteri2.intron
	                                                       //Chaetura_pelagica.exon Cuculus_canorusOut1.exon Egretta_garzetta2.intron Egretta_garzetta.exon Anas_platyrhynchos.exon
		                                                    //Nipponia_nippon2.intron ap_v6.mega.fa2.intron Chaetura_pelagica2.intron Picoides_pubescens2.intron Picoides_pubescens.exon

	    int  r=0, rr=0,cc=0, num;

		while(getline(myfile, line))
			{
			 g.GeneSplit(v, line, " ");r=0;

			 	for (int i = 3; i < v.size()-3; i++)	{
	 		        g.setLim1(v[i+1]);
	 		        g.setLim2(v[i]);
			 		  if (i%2==1){
					  	diff[r]=g.getLim1()-g.getLim2();
						r++;
							}
						}                       // IF INVERTED autruche budgerigar
				if (diff[0]<0){
						r=0;
				for (int i = 2; i < v.size()-3; i++)
				     {
	 		   		   g.setLim1(v[i+3]);
			 		   g.setLim2(v[i]);
				       cout<<g.getLim1()<<endl;
					   if (i%2==0){
			 		   diff[r]=g.getLim2()-g.getLim1();
						r++;
							    }
						}

					}

			  myfileout<<v[0]<<" ";
			  myfileout<<v[1]<<" ";
			  	if (v[1]=="-")	{
		          	for (int i = 0; i < r; i++)	{
			 		     diff2[i]= diff[r-i-1];
						  myfileout<<diff[r-i-1]<<" ";
				                        }
				 		 }
				else
			        {
			    	for (int i = 0; i < r; i++)	{
			 		      myfileout<<diff[i]<<" ";
				                           }
				    }

			  myfileout<<v[v.size()-1]<<endl;

		       r=0;
			   v.clear();
			   }
	delete[]diff;
	delete[]diff2;

   myfileout.close();

	return 0;
}
