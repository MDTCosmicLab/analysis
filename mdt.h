//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Apr 17 17:22:50 2024 by ROOT version 6.30/06
// from TTree mdt/Analysis of the MDT data
// found on file: reco_run45.root
//////////////////////////////////////////////////////////

#ifndef mdt_h
#define mdt_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include <TTreeReader.h>
#include <TTreeReaderValue.h>
#include <TTreeReaderArray.h>

#include<TH1F.h>
#include<TH2F.h>
#include<TFile.h>

// Headers needed by this particular selector
#include <vector>

class mdt : public TSelector {
public :

  /// output histograms
  TFile* m_outFile;
  
  TH1F* h_tubeDiff[9][9];
  
  TTreeReader     fReader;  //!the tree reader
  TTree          *fChain = 0;   //!pointer to the analyzed TTree or TChain
  
  // Readers to access the data (delete the ones you do not need).
  TTreeReaderValue<UInt_t> eventNumber = {fReader, "eventNumber"};
  TTreeReaderValue<UInt_t> nhits = {fReader, "nhits"};
  TTreeReaderArray<unsigned int> bcid = {fReader, "bcid"};
  TTreeReaderArray<unsigned int> tdc = {fReader, "tdc"};
  TTreeReaderArray<unsigned int> channel = {fReader, "channel"};
  TTreeReaderArray<unsigned int> coarse = {fReader, "coarse"};
  TTreeReaderArray<unsigned int> fine = {fReader, "fine"};
  TTreeReaderArray<unsigned int> chamber = {fReader, "chamber"};
  TTreeReaderArray<unsigned int> layer = {fReader, "layer"};
  TTreeReaderArray<unsigned int> tube = {fReader, "tube"};
  TTreeReaderArray<float> time = {fReader, "time"};
  TTreeReaderArray<float> charge = {fReader, "charge"};
  TTreeReaderValue<vector<bool>> leading = {fReader, "leading"};
  
  
  mdt(TTree * /*tree*/ =0) { }
  ~mdt() override { }
  Int_t   Version() const override { return 2; }
  void    Begin(TTree *tree) override;
  void    SlaveBegin(TTree *tree) override;
  void    Init(TTree *tree) override;
  Bool_t  Notify() override;
  Bool_t  Process(Long64_t entry) override;
  Int_t   GetEntry(Long64_t entry, Int_t getall = 0) override { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
  void    SetOption(const char *option) override { fOption = option; }
  void    SetObject(TObject *obj) override { fObject = obj; }
  void    SetInputList(TList *input) override { fInput = input; }
  TList  *GetOutputList() const override { return fOutput; }
  void    SlaveTerminate() override;
  void    Terminate() override;
  
  ClassDefOverride(mdt,0);
  
};

#endif

#ifdef mdt_cxx
void mdt::Init(TTree *tree)
{
  // The Init() function is called when the selector needs to initialize
  // a new tree or chain. Typically here the reader is initialized.
  // It is normally not necessary to make changes to the generated
  // code, but the routine can be extended by the user if needed.
  // Init() will be called many times when running on PROOF`
  // (once per file to be processed).
  
  fReader.SetTree(tree);
}

Bool_t mdt::Notify()
{
  // The Notify() function is called when a new file is opened. This
  // can be either for a new TTree in a TChain or when when a new TTree
  // is started when using PROOF. It is normally not necessary to make changes
  // to the generated code, but the routine can be extended by the
  // user if needed. The return value is currently not used.
  
  return kTRUE;
}


#endif // #ifdef mdt_cxx
