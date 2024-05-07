#include <TChain.h>

void plots()
{
    TChain chain("mdt");
    //    chain.Add("reco_run101.root");
    chain.Add("reco_run102.root");
    //chain.Add("reco_run988.root");
    chain.Process("mdt.C+");
}
