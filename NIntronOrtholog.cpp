#include <fstream>


#include "GeneGFF.cpp"

//============================================================================
// Name        : GeneGFF.cpp
// Author      : Miguel Sautié-Castellanos
// Version     : 2
// Description : Driver program developpé pour le traitement des fichiers en format GFF
//
//============================================================================

int main(int argc, char** argv) {

	  vector<string> v;
      vector<vector<string> > vv, vvv;
      GeneGFF g;
	  string line, line1, name, name1;
	  int L=14, cc=0, rr=0, ESPECIE=1,LL;
	  string path0="D:/DB/nuevos grupos/grupo3/";
	  string path1="D:/DB/nuevos grupos/grupo3/IntOrth";
	  string ext=".intron";
	  string ext2=".list";

	  //8nstring paths[]= {"Calypte_anna","Struthio_camelus.OM.gene.20130116","Pygoscelis_adeliae","Corvus_brachyrhynchos","Charadrius_vociferus","Picoides_pubescens","Cuculus_canorus","Anas_platyrhynchos"};
    //10string paths[]= {"Calypte_anna","Struthio_camelus.OM.gene.20130116","Pygoscelis_adeliae","ap_v6.mega.fa", "Nipponia_nippon", "Corvus_brachyrhynchos","Charadrius_vociferus","Picoides_pubescens","Cuculus_canorus", "Anas_platyrhynchos"};
	      string paths[]= {"Calypte_anna","Struthio_camelus.OM.gene.20130116","Aptenodytes_forsteri","ap_v6.mega.fa", "Nipponia_nippon", "Chaetura_pelagica", "Egretta_garzetta","Corvus_brachyrhynchos","Charadrius_vociferus","Picoides_pubescens","Cuculus_canorus", "Anas_platyrhynchos","Geospiza_fortis.gene","Manacus_vitellinus"};
	  string	pathIn2=path0+paths[ESPECIE]+ext;
	  string	pathOut=path1+paths[ESPECIE]+ext2;
	  ifstream myfile("D:/DB/nuevos grupos/grupo3/MatrixExons14nID.filtrex"); //lista de ortologos con filtros de exones presencia y numero de copias
      ofstream myfileout(pathOut.c_str());
      ifstream myfile2(pathIn2.c_str());


      //string p[] = {"CALAN","STRCA","APTFO","NIPNI","MELUN","CHAPE","CUCCA","EGRGA"}; PICPU ANAPL  Picoides_pubescens2.intron  Anas_platyrhynchos.intron      //string paths[]= {"D:/DB/FICHEROS DE PARTIDA/Calypte_anna2.intron","D:/DB/FICHEROS DE PARTIDA/Struthio_camelus.OM.gene.201301162.intron","D:/DB/FICHEROS DE PARTIDA/Aptenodytes_forsteri2.intron","D:/DB/FICHEROS DE PARTIDA/Nipponia_nippon2.intron","D:/DB/FICHEROS DE PARTIDA/ap_v6.mega.fa2.intron","D:/DB/FICHEROS DE PARTIDA/Chaetura_pelagica2.intron"5,"D:/DB/FICHEROS DE PARTIDA/Cuculus_canorusOut2.intron","D:/DB/FICHEROS DE PARTIDA/Egretta_garzetta2.intron"};

    while(getline(myfile, line1))
			{
	            g.GeneSplit(v, line1, "\t" );	            //matrix orthologs
	                vector<string> row;
	             for (int j = 0; j < L; j++) {
                      row.push_back(v[j]);
                                     }
                  vv.push_back(row);
				  v.clear(); cc++;
	        }

    while(getline(myfile2, line))
			{
	        g.GeneSplit(v, line, " ");
	              vector<string> row;  //matrix .intron
	             for (int j = 0; j < v.size(); j++) {
                      row.push_back(v[j]);
                                     }
                  vvv.push_back(row);
				  v.clear();rr++;

            }
            cout<<rr<<endl;
            cout<<cc<<endl;
       for (unsigned int i = 0; i < cc; i++)
	            {
				name=vv[i][ESPECIE].substr (0,11);    //matrix orthologs

	         for (unsigned int ii = 0; ii < rr; ii++)  {
		          //cout<<name<<" "<<vvv[ii][0]<<" "<<ii<<endl;
		         if (name==vvv[ii][0])  {
		            LL=vvv[ii].size()-1;
		           for (unsigned int iii = 2; iii <LL; iii++) {
					  myfileout<<name<<"\t"<<vvv[ii][iii]<<endl;
		          }
		         break;
		            }

		          }

	            }
	myfileout.close();
	return 0;
}


		           //vvout[i][j]=vvv[ii][(vvv[ii].size()-1)];
		           //myfileout<<vvv[ii][(vvv[ii].size()-1)]<<endl;
		          //vvv[i][j]=atoi(v[v.size()-1].c_str());  //cout<<v.size()<<" "<<name<<endl;
		          // cout<<v[0]<<endl;
		          //  myfileout<<name<<" "<<v[v.size()-1]<<" ";
		          //cout<<v[0]<<endl;
