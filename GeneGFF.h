
#include <string>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>

using namespace std;

#ifndef GENEGFF_H
#define GENEGFF_H

//============================================================================
// Name        : GeneGFF.cpp
// Author      : Miguel Sautié-Castellanos
// Version     : 2
// Description : Class GFF parser developpé pour le traitement des fichiers en format GFF
//
//============================================================================

class GeneGFF
{
    private:
    	string GeneID;
    	bool   Orient;
    	unsigned int Lim1;
    	unsigned int Lim2;

	public:
		GeneGFF(string const ID="", bool Ori=true,unsigned int L1=0, unsigned int L2=0);
		GeneGFF( const GeneGFF &obj);
		~GeneGFF();
		void operator = (const GeneGFF &D );
		void setID(string const &);
		string getID();
		void setOrient(string const &);  //obtenir orientations
		bool getOrient();
		void setLim1(string const &);    //obtenir coordonnees 1
		unsigned int getLim1();
		string getLim1s ();
		void setLim2(string const &);  //obtenir coordonnees 2
		unsigned int getLim2  () ;
		string getLim2s  ();
		string getParent(string const &);
		bool ARN(string const &);     //presence de gène
		bool CDS(string const &);     // presence de CDS
		void GeneSplit( vector<string> & , const  string  &, const  string  & ); //   to get tokens
		string ExtString(string const & , string const &); // montrer identificateurs
		bool inter (string const &, string const &);        //enlever copies & valeurs manquantes
	    bool FNexons (vector<string>& , unsigned int);      ////exclure gènes orthologues avec nombre inegal de exons
	    bool Gmanquants (vector<string>& , unsigned int);   //exclure gènes  manquants
};

#endif
