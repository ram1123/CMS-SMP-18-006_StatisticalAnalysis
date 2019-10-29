#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <sstream>
#include <TH1F.h>
#include <TFile.h>
#include <TROOT.h>
#include <TString.h>
#include <TSystem.h>
#include <Rtypes.h>
#include <TLatex.h>

#include <TMath.h>
#include <TAxis.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TAttLine.h>
#include <TPaveText.h>
#include <TColor.h>

#include "TGraphAsymmErrors.h"

#include "TTree.h"
#include "TCanvas.h"

//#include "HttStyles.h"
#include "HttStyles.h"
//#include "/home/arapyan/cms/cmssw/029a/CMSSW_7_1_6_patch1/src/delphes-dihiggs/Utils/CMS_lumi_v2.h"

void plot_chargedAll6()
{
  //gROOT->Macro("HttStyles.cc++");
  setTDRStyle();
  std::string xaxis = "#it{m}(H^{#pm}) (GeV)";
  //std::string xaxis = "#it{m}(H^{#pm#pm}) (GeV)";
  std::string yaxis = "#sigma_{VBF}(H^{#pm}) #times B(H^{#pm}#rightarrow W^{#pm}Z) (fb)";
  //std::string yaxis = "#sigma_{VBF} (H^{#pm#pm}) #times B(H^{#pm#pm} #rightarrow W^{#pm}W^{#pm}) (fb)";
  //std::string yaxis = "sin #theta = #frac{2#sqrt{2}v_{#chi}}{v}";
  
  // sh = 2sqrt(2)v_chi/v; v=246 GeV
  //The BR(WZ->3lnu)
  double br = 0.0328973292;

  double thp[9] = {0.6929,0.3560,0.2006,0.1203,0.07529,0.03220,0.02172,0.01487};
  double thm[9] = {0.4187,0.2022,0.1081,0.06178,0.03705,0.02301,0.01466,0.009547,0.006316};
  double th[9];


  double mass[7]={600,700,800,900,1000,1500,2000};

  /*
  double median[7] ={157.294921875, 93.36328125, 54.4921875, 37.8203125, 28.138916015625, 9.91015625, 5.38671875};
  double up68[7] ={83.3889137506485, 50.98455061018467, 29.32310950756073, 20.351707935333252, 15.25415763258934, 5.925346523523331, 3.9078481197357178};
  double low68[7] ={50.69074630737305, 30.92544722557068, 17.9151713848114, 12.398248195648193, 8.97288615256548, 3.413874626159668, 2.043691635131836};
  double up95[7] ={204.9871165752411, 126.21411269903183, 72.505964666605, 50.322774946689606, 37.988180324435234, 15.421330988407135, 10.661365509033203};
  double low95[7] ={81.10519409179688, 48.869842529296875, 28.310394287109375, 19.353363037109375, 14.179375648498535, 5.2647705078125, 3.11419677734375};
  double observed[7] = {149.70276663955676, 145.85091505257785, 84.74589839190158, 26.547219320838213, 13.127866021194368, 6.6868946434248455, 3.055407799277288};
  double observedMD[7] = {0.5083073105538338, 0.6129852463660018, 0.5365557210100836, 0.34787305314018263, 0.28535806227314986, 0.4006406008058167, 0.4642261304878798};*/
 
  /* 
  double median[7] ={417.5625, 239.85937499999997, 134.06359375, 96.34484375, 64.17345703125, 25.166757812500002, 13.274625};
  double up68[7] ={208.05275039672847, 126.2038411140442, 70.53858654737473, 50.30854454994201, 34.7885451644659, 14.746418644905091, 9.206901426315309};
  double low68[7] ={131.50772094726562, 78.2646617889404, 43.7441389274597, 30.960424947738645, 20.622146683931348, 8.4390971326828, 4.934232559204101};
  double up95[7] ={502.4408493041992, 307.8609062671661, 172.8646236240864, 122.32404100418091, 86.6356287395954, 37.344896305561065, 24.436813682556156};
  double low95[7] ={210.412353515625, 123.67749023437499, 69.12654052734374, 48.925115966796874, 32.58808364868163, 13.17322479248047, 7.51883056640625};
  double observed[7] = {389.2490573865629, 354.14100451898867, 214.4133409542145, 70.12555139520065, 30.041358993350915, 17.15102295112365, 7.555206150443968};
  double observedMD[7] = {0.9447181379326638, 0.6313018380254412, 0.9848605952316575, 0.659217764581604, 0.5031121785899841, 0.7828257775355343, 0.9235772507601091};*/
  
  
  double median[7] ={293.1125, 181.03671874999998, 126.29771484375, 96.643125, 79.38984375, 71.63746875, 95.1105};
  double up68[7] ={157.72845954895018, 98.1403381586075, 69.97650731205941, 55.08697958946229, 45.88543560743332, 43.97470405340195, 65.96593217468262};
  double low68[7] ={94.1917304992676, 58.62367622852324, 41.71894731044769, 32.40706352233886, 26.62156991958618, 24.859303502082817, 35.35296295166015};
  double up95[7] ={402.052424621582, 244.4037252426147, 174.13499603986742, 138.37653875350952, 115.74947798967362, 113.45705626106262, 177.08795851135255};
  double low95[7] ={148.84619140625003, 92.63988342285154, 65.12225921630859, 50.5866357421875, 41.55562133789062, 38.33723913574218, 53.871181640625004};
  double observed[7] = {152.77326664151454, 185.32045012560593, 181.03626516872126, 141.11964957158455, 71.12346244057856, 40.40071245936786, 134.46568298262227};
  double observedMD[7] = {0.6036886983116893, 0.7961098348234492, 0.9300992700854624, 0.9612708814451337, 0.7936705062924319, 1.1611280705250582, 3.795118225003635};  

  /*  double medianMD[7] ={0.6002928972593295, 0.414578098794425, 0.36643873123620546, 0.3329261836353518, 0.30618621784789724, 0.34161267357930386, 0.47495887979908324};
  double up68MD[7] ={0.12859694240701913, 0.09422721801010103, 0.08565988999969526, 0.07997151924558854, 0.07502164148895768, 0.09450172548541286, 0.15180761812035715};
  double low68MD[7] ={0.09991204941500575, 0.07180605241192023, 0.06401646091123647, 0.05866089393077761, 0.05533128014870342, 0.06717504513584466, 0.10373031477796263};
  double up95MD[7] ={0.27561925955592814, 0.20390568884889027, 0.1863350833609531, 0.17724293803068186, 0.16587617415671285, 0.21270266112965291, 0.3491184792458615};
  double low95MD[7] ={0.1708762567770971, 0.12142711380546062, 0.10834155767365644, 0.09935823721353834, 0.09395062867280154, 0.1116576051505046, 0.1693338198872793};*/


  /*    
	TGraphAsymmErrors* outerBand=new TGraphAsymmErrors(9,mass,medianMD,0,0,low95MD,up95MD);
	TGraphAsymmErrors* innerBand=new TGraphAsymmErrors(9,mass,medianMD,0,0,low68MD,up68MD);
	TGraph *expected = new TGraph(9,mass,medianMD);

	TGraph *observedl = new TGraph(9,mass,observedMD);
	
  */
  TGraphAsymmErrors* outerBand=new TGraphAsymmErrors(7,mass,median,0,0,low95,up95);
  TGraphAsymmErrors* innerBand=new TGraphAsymmErrors(7,mass,median,0,0,low68,up68);
  TGraph *expected = new TGraph(7,mass,median);

  TGraph *observedl = new TGraph(7,mass,observed);  
  

  int shift_label = 1.;
    
   // draw a frame to define the range
  TCanvas *canv = MakeCanvas("canv", "histograms", 800, 800);
  canv->cd();
  //TH1F* hr=canv->DrawFrame(expected->GetX()[0]-shift_label*.01, 0.1, expected->GetX()[expected->GetN()-1]+.01, 1.);

  TH1F* hr=canv->DrawFrame(expected->GetX()[0]-shift_label*.01, 0.1, expected->GetX()[expected->GetN()-1]+.01, 1500.);
  // format x axis
  hr->SetXTitle(xaxis.c_str());
  hr->GetXaxis()->SetLabelFont(62);
  hr->GetXaxis()->SetLabelSize(0.045);
  hr->GetXaxis()->SetLabelOffset(0.015);
  hr->GetXaxis()->SetTitleSize(0.055);
  hr->GetXaxis()->SetTitleFont(62);
  hr->GetXaxis()->SetTitleColor(1);
  hr->GetXaxis()->SetTitleOffset(1.05);
  // format y axis
  hr->SetYTitle(yaxis.c_str());
  hr->GetYaxis()->SetLabelFont(62);
  hr->GetYaxis()->SetTitleFont(62);
  hr->GetYaxis()->SetTitleOffset(1.30);
  hr->GetYaxis()->SetLabelSize(0.045);
  hr->SetNdivisions(505, "X");
  
   canv->SetLogy();
   hr->SetMinimum(10.);



  outerBand->SetLineWidth(1.);
  outerBand->SetLineColor(kBlack);
  outerBand->SetFillColor(TColor::GetColor(252,241,15));
  outerBand->Draw("3");
  
  innerBand->SetLineWidth(1.);
  innerBand->SetLineColor(kBlack);
  innerBand->SetFillColor(kGreen);
  innerBand->Draw("3same");
  
  expected->SetLineColor(kBlack);
  expected->SetLineWidth(3);
  expected->SetLineStyle(2);
  expected->Draw("L");

  observedl->SetLineColor(kBlack);
  observedl->SetLineWidth(3);
  observedl->SetLineStyle(1);
  observedl->SetMarkerStyle(20);
  observedl->Draw("LP");



  double mH_exclTH[6] = {700,800,900,1000,1000, 700};
  double shExclTH[6] = {1.004,0.871,0.769, 0.689, 1.,1.};

  TGraph *ExclTH = new TGraph(6,mH_exclTH,shExclTH);
  ExclTH->SetFillColor(kBlue);
  ExclTH->SetFillStyle(3001);
  //ExclTH->Draw("FL");


  //TLatex *text12 = new TLatex(0.2,0.94,"CMS #scale[0.75]{#bf{#it{Preliminary}}}");
  TLatex *text12 = new TLatex(0.2,0.94,"CMS");
  text12->SetNDC();
  text12->SetTextSize(0.045);
  text12->SetTextFont(62);
  text12->Draw();

  TLatex *text13 = new TLatex(0.7,0.94,"#bf{35.9 fb^{-1} (13 TeV)}");
  text13->SetNDC();
  text13->SetTextSize(0.035);
  text13->SetTextFont(62);
  text13->Draw();

  //TLatex *text14 = new TLatex(0.2,0.3,"H^{#pm#pm}#rightarrowW^{#pm}W^{#pm}#rightarrowq#bar{q}'l#nu");
  //TLatex *text14 = new TLatex(0.2,0.3,"H^{#pm}#rightarrowW^{#pm}Z#rightarrowq#bar{q}l#nu");
  TLatex *text14 = new TLatex(0.2,0.3,"H^{#pm}#rightarrowW^{#pm}Z#rightarrowq#bar{q}'ll");
  text14->SetNDC();
  text14->SetTextSize(0.05);
  text14->SetTextFont(62);
  text14->Draw();

  /*
  TLatex *text13 = new TLatex(0.4,0.54,"2015+2016 Model Independent");
  text13->SetNDC();
  text13->SetTextSize(0.05);
  text13->SetTextFont(62);
  text13->Draw();
  */

  TLegend* leg;
  //leg = new TLegend(0.63, 0.17,0.96, 0.425);
    leg = new TLegend(0.60, 0.60,0.95, 0.90);
  // leg = new TLegend(0.1, 0.70,0.35, 0.90);
  leg->SetTextSize(0.04);
  leg->SetBorderSize( 0 );
  leg->SetFillStyle( 1001 );
  leg->SetFillColor(kWhite); 
  leg->AddEntry( observedl , "Observed",  "LP" );
  leg->AddEntry( expected , "Expected",  "L" );
  leg->AddEntry( innerBand, "68% expected",  "F" ); 
  leg->AddEntry( outerBand, "95% expected",  "F" ); 
  //leg->AddEntry( outerBand, "#pm 2#sigma",  "F" ); 
  //leg->AddEntry( ExclTH   , "#Gamma_{H^{#pm}}/m_{H^{#pm}} > 0.15",  "F" ); 

  leg->Draw("same");
  //canv.RedrawAxis("g");
  
  canv->RedrawAxis();
  

  ///CMS_lumi_v2( canv, 14, 11 );
  
  
   //chan->Draw();
   //-------------------------------------------------------------------------
   //Save histograms
   canv->Print("limits_UnblindedModelI_62.pdf");
}
