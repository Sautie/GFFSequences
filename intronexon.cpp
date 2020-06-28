#include <fstream>


#include "GeneGFF.cpp"

using namespace std;

//============================================================================
// Name        : GeneGFF.cpp
// Author      : Miguel Sautié-Castellanos
// Version     : 2
// Description : Driver program developpé pour le traitement des fichiers en format GFF
//
//============================================================================

int main(int argc, char** argv) {

	  vector<string> v;
	  vector<int> row,file,vec;
      vector<vector<int> > vv;
      GeneGFF g;

	  string line, line1, line3;
	  float **vvv = new float*[20000];
         for(int i = 0; i < 20000; ++i) {
              vvv[i] = new float[30];
                        }
	  	 float **veca = new float*[200];
         for(int i = 0; i < 200; ++i) {
              veca[i] = new float[30];
                        }

	  size_t found;

	  int namen,j, u, r,rr, c,k,cc, sum, L=8;

      ifstream myfile("D:/DB/Seleccion definitiva de grupos/G1/G1-IntOrth2.table"); //lista de ortologos repetidos po intron con filtros de exones presencia y numero de copias

      ifstream myfile3("D:/DB/Seleccion definitiva de grupos/G1/G1-ExonOrth.DAT");
	  ofstream myfileout("D:/DB/Seleccion definitiva de grupos/G1/results g1.dat");
      ofstream myfileout2("D:/DB/Seleccion definitiva de grupos/G1/results1 g1.dat");

         u=0;
       while(getline(myfile3, line1))  // orthologlist finale
			{
	           g.GeneSplit(v, line1, "\t" );
	           file.push_back(atoi(v[1].c_str())  );
	           cout<<file.size()<<endl;
			    u++;
			   v.clear();
	        }
//	        vec.push_back(0);
        vec.push_back(2);
	       	 for (unsigned int cc = 0; cc < u; cc++)	{
	       	 rr=0;

	       	     while ((rr<vec.size())&&(file[cc]!=vec[rr])) {rr++;	  }
	       	     if (0<rr&&rr==vec.size()) vec.push_back(file[cc]);

	       	  }




       	k=0;
       while(getline(myfile, line))
			{
			g.GeneSplit(v, line, "\t" );
			vector<int> row;
			for (unsigned int jj = 0; jj < v.size(); jj++){
                row.push_back(atoi(v[jj].c_str())  );}
            vv.push_back(row);

		    v.clear();
			k++;

			}
	    c=2;rr=0;
	    cout<<k<<endl;
	   while (c<L+2)	{
	   sum=0;
	    cc=0;rr=0;j=0;
		while (cc<k)	{
		 	   namen=vv[cc][0];
			   sum=0; rr=0;
			  // if (c==1) {vvv[j][0]=namen;	cout<<namen<<endl;}

		 	while (cc<k&&namen==vv[cc][0]) {
			        sum= sum+vv[cc][c];
		  	        cc++;rr++;
		 	         }
					  vvv[j][c-2]=(float)sum/(float)rr;
					  //vvv[j][c-2]=sum;
					 j++;

		          }

		      c++;

		 }
		 cc=0;
		  for (unsigned int c = 0; c < L; c++)	{

		   for (unsigned int cc = 0; cc < vec.size(); cc++)	{
		    namen=vec[cc];sum=0;rr=0;
		  for (unsigned int ccc = 0; ccc < u; ccc++)	{
		          if (namen==file[ccc])	{
		               sum=sum+vvv[ccc][c]; rr++;  }


		                                              }
				   if (c==0) veca [cc][c]=namen;
		           veca [cc][c]=(float) sum/ (float) rr;
		                                                 }
			 }

		 for (unsigned int cc = 0; cc < j; cc++)	{
		 for (unsigned int cu = 0; cu < L; cu++)	{
		 		myfileout<<vvv[cc][cu]<<"\t";
						 	 }
			    	myfileout<<endl;
						 	 	 }

		for (unsigned int cc = 0; cc < vec.size(); cc++)	{
		 for (unsigned int cu = 0; cu < L; cu++)	{
		 		myfileout2<<veca[cc][cu]<<"\t";
						 	 }
			    	myfileout2<<endl;
						 	 	 }

	for(int i = 0; i < 20000; ++i) {
    delete [] vvv[i];
}
delete [] vvv;
	for(int i = 0; i < 200; ++i) {
    delete [] veca[i];
}
delete [] veca;

	myfileout.close();
	return 0;





}
