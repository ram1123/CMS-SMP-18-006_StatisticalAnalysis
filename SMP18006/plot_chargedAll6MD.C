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

void plot_chargedAll6MD()
{
  //gROOT->Macro("HttStyles.cc++");
  setTDRStyle();
  gStyle->SetCanvasPreferGL(true);
  std::string xaxis = "#it{m}(H_{5}) (GeV)";
  //std::string yaxis = "#sigma_{VBF} #times B(H^{#pm} #rightarrow W^{#pm}Z) [fb]";
  //std::string yaxis = "#sigma_{VBF} #times B(H^{#pm#pm} #rightarrow W^{#pm}W^{#pm}) [fb]";
  //std::string yaxis = "sin #theta = #frac{2#sqrt{2}v_{#chi}}{v}";

  std::string yaxis = "#it{s_{H}}";
  
  // sh = 2sqrt(2)v_chi/v; v=246 GeV
  //The BR(WZ->3lnu)
  double br = 0.0328973292;

  double thp[9] = {0.6929,0.3560,0.2006,0.1203,0.07529,0.03220,0.02172,0.01487};
  double thm[9] = {0.4187,0.2022,0.1081,0.06178,0.03705,0.02301,0.01466,0.009547,0.006316};
  double th[9];


  double mass[7]={600,700,800,900,1000,1500,2000};

/*WW limits

  double medianMD[7] ={0.6745947857788407, 0.47186465220442186, 0.4186800314679457, 0.3788861141556919, 0.35147568372506227, 0.38590903235088964, 0.5367363761661771};
  double up68MD[7] ={0.14672573716524673, 0.10801332721203738, 0.09787197364633066, 0.09101146791978637, 0.08668071813474199, 0.10795907574456026, 0.17317250743534363};
  double low68MD[7] ={0.11227876904684342, 0.08172823901226994, 0.07377054171196129, 0.06789791156993147, 0.06384963561195828, 0.0758855237859995, 0.11820855866837898};
  double up95MD[7] ={0.31641357247439683, 0.2343039921586766, 0.21454429828133265, 0.20171103985753652, 0.19061398629846987, 0.24315788828593404, 0.39767282024669126};
  double low95MD[7] ={0.19202664626137966, 0.1382059568284434, 0.12495055038604846, 0.11519253865979079, 0.10685896044434756, 0.12613606487947193, 0.19463271920037528};
  

  double median[7] ={248.47265625, 85.833984375, 48.90673828125, 29.572265625, 19.086181640625, 6.40380859375, 4.033203125};
  double up68[7] ={119.84114491939545, 43.79365620017052, 25.537708461284637, 15.913304328918457, 10.57488787919283, 4.084136858582497, 3.022385597229004};
  double low68[7] ={5.82783699035645, 27.158409118652344, 15.716185122728348, 9.649251222610474, 6.3045907616615295, 2.2708818316459656, 1.580885648727417};
  double up95[7] ={287.7526148557663, 106.40490210056305, 62.96474316716194, 39.86890375614166, 26.315375357866287, 10.612374603748322, 8.190484523773193};
  double low95[7] ={121.32453918457031, 42.9169921875, 24.835453033447266, 15.248199462890625, 9.841312408447266, 3.5020828247070312, 2.39471435546875};
  double observed[7] = {47.67467968597517, 90.96846633342307, 177.4815798063425, 93.15386563615374, 46.662770329956146, 12.071634522172015, 2.823659118671462};
  double observedMD[7] = {0.29549325400273807, 0.4857728577714084, 0.797580525493438, 0.6724605796947988, 0.5495674694067479, 0.529844964647339, 0.44909902810845803};

*/

/*wz
 double medianMD[7] ={1.3020416659999787, 0.864897031443628, 0.7603453162872774, 0.7029513674501245, 0.6202947887899752, 0.7368641326594747, 1.0307764064044151};
  double up68MD[7] ={0.26820592586925196, 0.19235579851132378, 0.1752810029803752, 0.1631878662559333, 0.15297673480390594, 0.19922903225454314, 0.3200865219799802};
  double low68MD[7] ={0.20998594090587197, 0.1464901043623129, 0.13169387334075078, 0.12385855373169341, 0.11209421826546351, 0.1437371586674664, 0.22042486744171363};
  double up95MD[7] ={0.5703272714906629, 0.4147484884984236, 0.37959194251356576, 0.35837013509120796, 0.336401300829991, 0.44245694791939694, 0.7265233913298306};
  double low95MD[7] ={0.36354935262409127, 0.25093816017824033, 0.22269998709711325, 0.20978827184463672, 0.190332163801804, 0.23871386765559305, 0.3643742779001613};

*/


  double medianMD[7] ={0.4645646483537033, 0.42904781930456193, 0.38590903235088964, 0.375, 0.37041467472280304, 0.426193178030808, 0.5528689379048166};
  double up68MD[7] ={0.10934809176706967, 0.10306069147061814, 0.09083431877344728, 0.08826658216032296, 0.08838090698192369, 0.11255047931171475, 0.17336177174876954};
  double low68MD[7] ={0.08005254219326585, 0.07624161786859635, 0.06857587348707789, 0.06607421195845459, 0.06615952038638578, 0.08003930742377507, 0.11732698953722048};
  double up95MD[7] ={0.237451689511129, 0.2242942748107476, 0.1980036627676131, 0.19387094343596145, 0.194839970798462, 0.25218637622867773, 0.39479562828742365};
  double low95MD[7] ={0.13735354194944804, 0.12924154131610976, 0.11624689814221628, 0.11191471499245725, 0.11054627400167, 0.13439865620294705, 0.19377002901314716};
  

  double median[7] ={710.675, 218.72890625, 120.98421875000001, 75.46515624999999, 43.44388671875, 16.2706015625, 9.919500000000001};
  double up68[7] ={322.93700790405273, 108.11100273132323, 62.21002967953682, 39.104955883026136, 24.070517844557763, 9.987717645406722, 7.117118960380553};
  double low68[7] ={210.74307174682616, 67.81877708435059, 38.2801629638672, 24.250735330581655, 14.282867175936701, 5.728574530839921, 3.7888324584960946};
  double up95[7] ={758.9418716430664, 260.0739465713501, 150.95313801407815, 96.5591605758667, 59.89895630657673, 25.406057631254196, 18.911025678634644};
  double low95[7] ={341.45712890625, 108.51004333496094, 60.492109375000005, 38.32214965820312, 22.570456771850587, 8.834428192138674, 5.773458984375001};
  double observed[7] = {134.47562232035753, 199.73682645328418, 436.5879704674258, 242.87210199800063, 104.70264809659899, 31.380679003901246, 90.94851884311248};
  double observedMD[7] = {0.40974806136202124, 0.5308384325995322, 0.4995893403612562, 0.3360880918913702, 0.25189621365089704, 0.34269036604080105, 0.4200213281102201};

  TGraphAsymmErrors* outerBand=new TGraphAsymmErrors(7,mass,medianMD,0,0,low95MD,up95MD);
  TGraphAsymmErrors* innerBand=new TGraphAsymmErrors(7,mass,medianMD,0,0,low68MD,up68MD);
  TGraph *expected = new TGraph(7,mass,medianMD);

  TGraph *observedl = new TGraph(7,mass,observedMD);
  
  /*
  TGraphAsymmErrors* outerBand=new TGraphAsymmErrors(11,mass,median,0,0,low95,up95);
  TGraphAsymmErrors* innerBand=new TGraphAsymmErrors(11,mass,median,0,0,low68,up68);
  TGraph *expected = new TGraph(11,mass,median);

  TGraph *observedl = new TGraph(11,mass,observed);  
  */

  int shift_label = 1.;
    
   // draw a frame to define the range
  TCanvas *canv = MakeCanvas("canv", "histograms", 800, 800);
  canv->cd();
  TH1F* hr=canv->DrawFrame(expected->GetX()[0]-shift_label*.01, 0.0, expected->GetX()[expected->GetN()-1]+.01, 1.);

  //TH1F* hr=canv->DrawFrame(expected->GetX()[0]-shift_label*.01, 0.1, expected->GetX()[expected->GetN()-1]+.01, 1500.);
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
  
  //canv->SetLogy();
  // hr->SetMinimum(10.);



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



  double mH_exclTH[9] = {600, 700, 800, 900, 1000, 1500, 2000, 2000, 600};
  //double shExclTH[6] = {1.004,0.871,0.769, 0.689, 1.,1.};

  double shExclTH[9] = {0.9709,0.8204,0.7113, 0.6282, 0.5628, 0.371134809512603,0.277350098112615, 1., 1.};

  TGraph *ExclTH = new TGraph(9,mH_exclTH,shExclTH);
  ExclTH->SetFillColorAlpha(kBlue-7,0.75);
  ExclTH->SetFillStyle(3001);
  ExclTH->Draw("FL");


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

  /*
  TLatex *text13 = new TLatex(0.4,0.54,"2015+2016 Model Independent");
  text13->SetNDC();
  text13->SetTextSize(0.05);
  text13->SetTextFont(62);
  text13->Draw();
  */

  TLegend* leg;
  //leg = new TLegend(0.60, 0.17,0.93, 0.425);
  leg = new TLegend(0.60, 0.60,0.95, 0.90);
  // leg = new TLegend(0.65, 0.65,0.95, 0.90);
  //  leg = new TLegend(0.1, 0.70,0.35, 0.90);
  leg->SetTextSize(0.04);
  leg->SetBorderSize( 0 );
  leg->SetFillStyle( 1001 );
  leg->SetFillColor(kWhite); 
  leg->AddEntry( observedl , "Observed",  "LP" );
  leg->AddEntry( expected , "Expected",  "L" );
  leg->AddEntry( innerBand, "68% expected",  "F" ); 
  leg->AddEntry( outerBand, "95% expected",  "F" ); 
  gStyle->SetCanvasPreferGL(false);
  leg->AddEntry( ExclTH   , "#Gamma(H)/#it{m}(H) > 0.1",  "F" ); 

  leg->Draw("same");
  //canv.RedrawAxis("g");
  
  canv->RedrawAxis();
  

  ///CMS_lumi_v2( canv, 14, 11 );
  
  
   //chan->Draw();
   //-------------------------------------------------------------------------
   //Save histograms
   canv->Print("limits_UnblindedModelInewFR_6.pdf");
}
