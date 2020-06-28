#include "GeneGFF.h"

//============================================================================
// Name        : GeneGFF.cpp
// Author      : Miguel Sautié-Castellanos
// Version     : 2
// Description : Class GFF parser developpé pour le traitement des fichiers en format GFF
//
//============================================================================


GeneGFF::GeneGFF(string const ID, bool Ori,unsigned int L1, unsigned int L2):
    GeneID(ID), Orient(Ori), Lim1(L1), Lim2(L2)
{
}

GeneGFF::~GeneGFF()
{
}

GeneGFF::GeneGFF( const GeneGFF& p ) :
     GeneID(p.GeneID)   //, Orient(p.Orient),Lim1(p.Lim1), Lim2(p.Lim2)
{
}
  void GeneGFF::operator=(const GeneGFF &G) {
         GeneID = G.GeneID;
         Orient = G.Orient;
         Lim1=G.Lim1;
		 Lim2=G.Lim2;
        }
void  GeneGFF::setID(string const &s)
  {
  		size_t found1 = s.find("ID");
	    size_t found2 = s.find(";",found1);
	    GeneID= s.substr (3,(found2-found1-3));
}
string  GeneGFF::getID()
    {
    	return(GeneID);
}
void  GeneGFF::setOrient(string const &s)
	{
 	 if (s=="-")Orient=false;
 	 else if (s=="+") Orient=true;

          }
bool  GeneGFF::getOrient ()
    {
    	return(Orient);
}
void  GeneGFF::setLim1(string const &L1)
 {
  Lim1= atoi (L1.c_str());
}
string  GeneGFF::getLim1s()
{
    stringstream Ls;
    Ls << Lim1;
    return Ls.str();
}
unsigned int  GeneGFF::getLim1()
{
    return Lim1;
}
void  GeneGFF::setLim2(string const &L2)
{
  Lim2= atoi (L2.c_str());
}
string  GeneGFF::getLim2s()
{
    stringstream Ls;
    Ls << Lim2;
    return Ls.str();
}
unsigned int  GeneGFF::getLim2()
{
    return Lim2;
}
string  GeneGFF::getParent(string const &s)
	{
 	    size_t found1 = s.find("Parent");
	    size_t found2 = s.find(";",found1);
         return s.substr (7,(found2-found1-7));   //get parent
          }
bool  GeneGFF::ARN(string const &r){return (r=="mRNA");}

bool  GeneGFF::CDS(string const &r){return  (r=="CDS");}


void GeneGFF::GeneSplit( vector<string> & StringVe, const  string  & String, const  string  & Delim) //get gene tokens
	{

      size_t  start = 0, end = 0;
	    while ( end != string::npos)
	    {
	        end = String.find( Delim, start);
	        StringVe.push_back( String.substr( start,
	                       (end == string::npos) ? string::npos : end - start));
	        start = (   ( end > (string::npos -Delim.size()) )
	                  ?  string::npos  :  end + Delim.size());
	    }
	}
string GeneGFF::ExtString(string const & line, string const &s)  // montrer identificateurs
{
	size_t Pstr2;
	string name1;
	Pstr2 = line.find(s);
    name1 = line.substr (Pstr2-12,17);
    if (Pstr2 == std::string::npos) {
        std::cout << "not found\n";
    } else {
         return name1;
    }
}

//member functions pour le post-traitement, a l'avenir subclass
bool GeneGFF::inter (string const &str1 , string const &str2)  //enlever copies & missing values
   {
    size_t found, found1;
	   bool interdit=true;
				found = str1.find (str2);
				  if(found!=std::string::npos){
				    found1 = str1.find (str2, found+1);
					if (found1!=std::string::npos){
					    	interdit=false;		//copie
							   }
				                           }
				 else {
				     interdit=false;       //absente
				  }
			return interdit;
	}

bool GeneGFF::FNexons (vector<string>& Strings, unsigned int K) {              //exclure gènes orthologues avec nombre inegal de exons
	   unsigned int x=1;
	   const string name=Strings[0];
       while ((x<K)&&(Strings[x]==name)) x++;
		          return (x==K) ;

	}

bool GeneGFF::Gmanquants (vector<string>& Strings, unsigned int K) {  //exclure gènes  manquants
	   unsigned int x=0;
       while ((x<K)&&(Strings[x]!="0")) x++;
		          return (x==K) ;

	}


