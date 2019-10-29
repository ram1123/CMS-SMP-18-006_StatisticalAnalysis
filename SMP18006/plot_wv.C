#include "Plotting.h"
#include "Plotting_Style.h"

void plot_wv(TString file, TString folder, TString output, TString title) {
  ModTDRStyle();

  TFile f1("ch1_splitted_TF1_WV.root");
  TH1F *aqgc  = (TH1F*)gDirectory->Get("675");
  //TH1F *aqgc  = (TH1F*)gDirectory->Get("671");
  aqgc->SetFillStyle(0.);
  aqgc->SetLineStyle(2);
  aqgc->SetLineWidth(3.);
  aqgc->SetLineColor(kBlue);
  //TH1F *dch  = (TH1F*)gDirectory->Get("DCH_WW_M1000");
  TH1F *dch  = (TH1F*)gDirectory->Get("CH_WZToLL_M1000");
  dch->SetFillStyle(0.);
  dch->SetLineStyle(2);
  dch->SetLineWidth(3.);
  dch->SetLineColor(kMagenta);
  dch->Scale(0.25);

  TFile f(file);

  TGraphAsymmErrors *data  = (TGraphAsymmErrors*)gDirectory->Get(folder+"data"); assert(data);
  TH1F *VVjjQCD  = (TH1F*)gDirectory->Get(folder+"VVjjQCD");
  TH1F *wjet     = (TH1F*)gDirectory->Get(folder+"W1+jets");
  TH1F *diboson  = (TH1F*)gDirectory->Get(folder+"diboson");
  TH1F *top      = (TH1F*)gDirectory->Get(folder+"top");
  TH1F *bkg      = (TH1F*)gDirectory->Get(folder+"total_background");
  TH2F * cov     = (TH2F*)gDirectory->Get(folder+"total_covar");

  int NBINS = 8;
  double MINRange = 600;
  double MAXRange = 2500;
  double massLEdges[9]={600, 700, 800, 900, 1000, 1200, 1500, 2000, 2500};
  double massLEdges1[8]={650, 750, 850, 950, 1100, 1350, 1750, 2250};
  TH1F *hdata     = new TH1F("", "", NBINS, massLEdges);
  TH1F *hVVjjQCD  = new TH1F("", "", NBINS, massLEdges);
  TH1F *hwjet     = new TH1F("", "", NBINS, massLEdges);
  TH1F *hdiboson  = new TH1F("", "", NBINS, massLEdges);
  TH1F *htop      = new TH1F("", "", NBINS, massLEdges);
  TH1F *hbkg      = new TH1F("", "", NBINS, massLEdges);

  
  for(int i=1; i<=hdata->GetNbinsX(); i++){
    double x,y;
    data->GetPoint(i-1,x,y);
    hdata->SetBinContent(i,y); //hdata->SetBinError(i,data->GetErrorY(i));
    hdata->SetBinErrorOption(TH1::kPoisson);
    hVVjjQCD->SetBinContent(i, VVjjQCD->GetBinContent(i)); hVVjjQCD->SetBinError(i,VVjjQCD->GetBinError(i));
    hwjet->SetBinContent(i, wjet->GetBinContent(i)); hwjet->SetBinError(i,wjet->GetBinError(i));
    hdiboson->SetBinContent(i, diboson->GetBinContent(i)); hdiboson->SetBinError(i,diboson->GetBinError(i));
    htop->SetBinContent(i, top->GetBinContent(i)); htop->SetBinError(i,top->GetBinError(i));
    hbkg->SetBinContent(i, bkg->GetBinContent(i)); hbkg->SetBinError(i,bkg->GetBinError(i));
    }
  
  hdiboson->SetFillColor(TColor::GetColor(248,206,104));
  hVVjjQCD->SetFillColor(TColor::GetColor(250,202,255));
  htop->SetFillColor(TColor::GetColor(155,152,204));
  hwjet->SetFillColor(TColor::GetColor(222,90,106));

  double yield=0, err=0;

  std::cout << "Yields" << std::endl;
  yield = hdata->IntegralAndError(1,hdata->GetNbinsX(),err);
  for(int i =1;i<=hdata->GetNbinsX();i++)
    {
      std::cout << hdata->GetBinContent(i) << " " <<  hdata->GetBinErrorLow(i) << " " <<  hdata->GetBinErrorUp(i) << std::endl;
    }
  std::cout << "Data " << yield << " pm " << err << std::endl;
  yield = dch->IntegralAndError(1,dch->GetNbinsX(),err);
  std::cout << "Higgs " << yield << " pm " << err << std::endl;
  yield = aqgc->IntegralAndError(1,aqgc->GetNbinsX(),err);
  std::cout << "AQGC " << yield << " pm " << err << std::endl;
  yield = hdiboson->IntegralAndError(1,hdiboson->GetNbinsX(),err);
  std::cout << "SM EW " << yield << " pm " << err << std::endl;
  yield = hVVjjQCD->IntegralAndError(1,hVVjjQCD->GetNbinsX(),err);
  std::cout << "SM QCD " << yield << " pm " << err << std::endl;
  yield = htop->IntegralAndError(1,htop->GetNbinsX(),err);
  std::cout << "Top " << yield << " pm " << err << std::endl;
  yield = hwjet->IntegralAndError(1,hwjet->GetNbinsX(),err);
  std::cout << "V+jet " << yield << " pm " << err << std::endl;
  yield = hbkg->IntegralAndError(1,hbkg->GetNbinsX(),err);
  std::cout << err << std::endl;
  err=0;
  for(int i=1;i<=hbkg->GetNbinsX();i++)
    {
      for(int j=1;j<=hbkg->GetNbinsX();j++)
	{
	  err=err+cov->GetBinContent(i,j);
	}
    }
  std::cout << "Total background " << yield << " pm " << sqrt(err) << std::endl;

  TH1F *hbkg_dummy = (TH1F*)hbkg->Clone();
  hbkg_dummy ->SetLineColor(TColor::GetColor(244, 0, 8));
  hbkg_dummy ->SetFillStyle(0);
  hbkg_dummy ->SetLineWidth(2);

  int new_idx = CreateTransparentColor(12, 0.4);
  hbkg->SetFillColor(new_idx);
  hbkg->SetMarkerSize(0);

  THStack stack;
  stack.Add(hdiboson);
  stack.Add(hVVjjQCD);
  stack.Add(htop);
  stack.Add(hwjet);
 
  TCanvas * canv = new TCanvas(output, output);
  canv->cd();
  std::vector<TPad*> pads = TwoPadSplit(0.29, 0.005, 0.005);

  // Do the axis hist
  std::vector<TH1*> h = CreateAxisHists(2, hdata);
  //SetupTwoPadSplitAsRatio(pads, h[0], h[1], "Obs/Exp", true, 0.05, 1.95);
  SetupTwoPadSplitAsRatio(pads, h[0], h[1], "Obs/Exp", true, 0.05, 2.95);
  h[1]->GetXaxis()->SetTitle("m_{ZV} (GeV)");
  h[1]->GetXaxis()->SetLabelFont(62);
  h[1]->GetXaxis()->SetLabelSize(0.039);
  h[1]->GetXaxis()->SetLabelOffset(0.015);
  h[1]->GetXaxis()->SetTitleSize(0.055);
  h[1]->GetXaxis()->SetTitleFont(62);
  h[1]->GetXaxis()->SetTitleColor(1);
  h[1]->GetXaxis()->SetTitleOffset(1.02);
  TString w_label = TString::Format("%.2f", h[1]->GetXaxis()->GetBinWidth(1));
  //h[0]->GetYaxis()->SetTitle("Events / " + w_label);
  h[0]->GetYaxis()->SetTitle("Events");
  h[0]->GetYaxis()->SetLabelFont(62);
  h[0]->GetYaxis()->SetTitleFont(62);
  h[0]->GetYaxis()->SetTitleOffset(1.30);
  h[0]->GetYaxis()->SetLabelSize(0.045);

  h[0]->Draw("axis");

  // Draw the stack
  stack.Draw("HISTSAME");
  aqgc->Draw("histsame");
  dch->Draw("histsame");
  hbkg->Draw("e2same");
  //hdata->Draw("esamex0");
  hdata->Draw("E0same");

  TH1F *ratio = reinterpret_cast<TH1F *>(
      MakeRatioHist(hdata, hbkg, true, false));
  TH1F *ratio_err = reinterpret_cast<TH1F *>(
      MakeRatioHist(hbkg, hbkg, true, false));
  
  for(int i =1;i<=ratio->GetNbinsX();i++)
    {
      double x,y;
      data->GetPoint(i-1,x,y);
      std::cout << y << std::endl;
      data->SetPoint(i-1,massLEdges1[i-1],y/hbkg->GetBinContent(i));
      data->SetPointEXlow(i-1,50);
      data->SetPointEXhigh(i-1,50);
      if(i==5)
	{
	  data->SetPointEXlow(i-1,100);
	  data->SetPointEXhigh(i-1,100);
	}
      else if(i==6)
	{
	  data->SetPointEXlow(i-1,150);
	  data->SetPointEXhigh(i-1,150);
	}
      else if(i>6)
	{
	  data->SetPointEXlow(i-1,250);
	  data->SetPointEXhigh(i-1,250);
	}
	
      data->SetPointEYlow(i-1,data->GetErrorYlow(i-1)/hbkg->GetBinContent(i));
      data->SetPointEYhigh(i-1,data->GetErrorYhigh(i-1)/hbkg->GetBinContent(i));
    }
  //data->SetPointEYhigh(7,1.84102);

  //data->SetMarkerStyle(1);
  //data->SetLineWidth(2.);
  data->SetLineColor  (kBlack);
  data->SetMarkerColor(kBlack);
  

  pads[0]->SetLogy(true);
  pads[0]->SetTicks();
  h[0]->SetMinimum(0.01);

  // Fix the y-axis range
  FixTopRange(pads[0], GetPadYMax(pads[0]), 0.50);
  DrawCMSLogo(pads[0], "CMS", "", 11, 0.045, 0.05, 1.0);
  DrawTitle(pads[0], "35.9 fb^{-1} (13 TeV)", 3);

  // Make the legend
  //TLegend *leg = PositionedLegend(0.5, 0.2, 3, 0.025);
  TLegend *leg = PositionedLegend(0.72, 0.3, 3, 0.025);
  leg->SetTextSize(0.033);
  leg->AddEntry(hdata, "Observed", "LP");
  leg->AddEntry(hwjet, "V + jets", "F");
  leg->AddEntry(htop, "Top quark", "F");
  leg->AddEntry(hVVjjQCD, "QCD ZV", "F");
  leg->AddEntry(hdiboson, "SM EW ZV", "F");
  leg->AddEntry(hbkg, "Bkg. uncertainty ", "F");
  leg->AddEntry(aqgc, "f_{T2}/#Lambda^{4} = -2.5 TeV^{-4}", "L" );
  leg->AddEntry(dch, "m_{H^{#pm}} = 1000 GeV, s_{H} = 0.5", "L" );
  //leg->AddEntry(dch, "m_{H^{#pm#pm}} = 1000 GeV, s_{H}=0.5", "L" );

  leg->SetNColumns(2);
  leg->Draw();

  // Draw labels and text
  // DrawCMSLogo(pads[0], "CombineHarvester", "", 0);
  //DrawTitle(pads[0], "CombineHarvester", 1);
  //DrawTitle(pads[0], title, 3);

  // Redraw the axis
  FixOverlay();
  hbkg_dummy->Draw("HISTSAME");
  hdata->Draw("esame");

  pads[1]->cd();
  h[1]->Draw("axis");
  ratio_err->Draw("e2same");
  TLine line;
  line.SetLineStyle(2);
  DrawHorizontalLine(pads[1], &line, 1.0);
  //ratio->Draw("esame");
  data->Draw("PE0");
  
  // Print!
  canv->Print(output+".pdf");
}
