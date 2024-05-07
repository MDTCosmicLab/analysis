#define mdt_cxx
// The class definition in mdt.h has been generated automatically
// by the ROOT utility TTree::MakeSelector(). This class is derived
// from the ROOT class TSelector. For more information on the TSelector
// framework see $ROOTSYS/README/README.SELECTOR or the ROOT User Manual.


// The following methods are defined in this file:
//    Begin():        called every time a loop on the tree starts,
//                    a convenient place to create your histograms.
//    SlaveBegin():   called after Begin(), when on PROOF called only on the
//                    slave servers.
//    Process():      called for each event, in this function you decide what
//                    to read and fill your histograms.
//    SlaveTerminate: called at the end of the loop on the tree, when on PROOF
//                    called only on the slave servers.
//    Terminate():    called at the end of the loop on the tree,
//                    a convenient place to draw/fit your histograms.
//
// To use this file, try the following session on your Tree T:
//
// root> T->Process("mdt.C")
// root> T->Process("mdt.C","some options")
// root> T->Process("mdt.C+")
//


#include "mdt.h"
#include <TH2.h>
#include <TStyle.h>

#include <string>

void mdt::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

   /// prepare output file and book the histograms
   m_outFile = new TFile("mdt.root","RECREATE");

   std::string hname;
   for (unsigned int i=0 ; i<8 ; i++) {
     for (unsigned int j=i+1 ; j<9 ; j++ ) {
       std::string l1 = std::to_string(i+1);
       std::string l2 = std::to_string(j+1);
       hname = "tubediff_"+l1+"_"+l2;
       h_tubeDiff[i][j]=new TH1F(hname.c_str(),hname.c_str(),34,-17.,17.);
     }
   }
   

}

void mdt::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

}

Bool_t mdt::Process(Long64_t entry)
{
   // The Process() function is called for each entry in the tree (or possibly
   // keyed object in the case of PROOF) to be processed. The entry argument
   // specifies which entry in the currently loaded tree is to be processed.
   // When processing keyed objects with PROOF, the object is already loaded
   // and is available via the fObject pointer.
   //
   // This function should contain the \"body\" of the analysis. It can contain
   // simple or elaborate selection criteria, run algorithms on the data
   // of the event and typically fill histograms.
   //
   // The processing can be stopped by calling Abort().
   //
   // Use fStatus to set the return value of TTree::Process().
   //
   // The return value is currently not used.

   fReader.SetLocalEntry(entry);

   if ( entry !=0 && entry%1000==0 ) std:cout << entry << std::endl;
   
   for ( unsigned int il=1 ; il<=8 ; il++ )  {

     for ( unsigned int jl=il+1 ; jl<=9 ; jl++ )  {

       for (unsigned int ih=0 ; ih<tube.GetSize() ; ih++)  {

	 if ( (leading->at(ih)!=1) || (charge[ih]<40) ) continue;
	 
	 unsigned int layer1 = (chamber[ih]-1)*3+layer[ih];

	 //	 std::cout << "layer1 " << layer1 << std::endl;
	 
	 if (layer1==il) {

	   for (unsigned int jh=0 ; jh<tube.GetSize() ; jh++)  {

	     if ( (leading->at(jh)!=1) || (charge[jh]<40) ) continue;

	     unsigned int layer2 = (chamber[jh]-1)*3+layer[jh];

	     //	     std::cout << "layer2 " << layer2 << std::endl;

	     if (layer2==jl) {

	       //	       std::cout << "Filling for layers: " << il << " " << jl << " " << tube[ih] << " " << tube[jh]<< " "
	       //	 << ((int) tube[ih])-((int) tube[jh]) << std::endl;
	       
	       
	       h_tubeDiff[il-1][jl-1]->Fill(1.*( ((int) tube[ih])-((int) tube[jh])));
	       
	     }
	     
	   }

	 }
	 
       }
       
     }
     
   }

   
   return kTRUE;
}

void mdt::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void mdt::Terminate()
{
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.

  for (unsigned int i=0 ; i<8 ; i++) {
    for (unsigned int j=i+1 ; j<9 ; j++ ) {
      h_tubeDiff[i][j]->Write();
    }
  }

  m_outFile->Close();

}
