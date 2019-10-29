#!/bin/sh

if [ $# != 2 ]; then
   echo "TOO FEW PARAMETERS"
   exit
fi

if [ $1 = "exp" ]; then
  PARAM="--expectSignal=0 -t -1";
fi

MASS=$2

combine -M FitDiagnostics --expectSignal=1 limits_ww_13TeV2016.txt -m 2000 --saveShapes --saveWithUncertainties --saveNormalizations
root -l plot_wv.C\(\"wv_mlfir.root\",\"shapes_fit_b/ww13TeV2016/\",\"wv\",\"\"\)
python ../CombinedLimit/test/mlfitNormsToText.py --uncertainties wv_mlfit.root 
root -l plot_wv.C\(\"zv_mlfit.root\",\"shapes_fit_b/wzl13TeV2016/\",\"zv_signal\",\"tt\"\)
