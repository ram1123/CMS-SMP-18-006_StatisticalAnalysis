#!/bin/sh

#combine -M AsymptoticLimits --noFitAsimov limits_ww_13TeV2016.txt -m 2000
#combine -M AsymptoticLimits --noFitAsimov limits_ww_13TeV2016.txt -m 1500
#combine -M AsymptoticLimits --noFitAsimov limits_ww_13TeV2016.txt -m 1000
#combine -M AsymptoticLimits --noFitAsimov limits_ww_13TeV2016.txt -m 900
#combine -M AsymptoticLimits --noFitAsimov limits_ww_13TeV2016.txt -m 800
#combine -M AsymptoticLimits --noFitAsimov limits_ww_13TeV2016.txt -m 700
#combine -M AsymptoticLimits --noFitAsimov limits_ww_13TeV2016.txt -m 600

#combine -M AsymptoticLimits --noFitAsimov limits_wz_13TeV2016.txt -m 2000
#combine -M AsymptoticLimits --noFitAsimov limits_wz_13TeV2016.txt -m 1500
#combine -M AsymptoticLimits --noFitAsimov limits_wz_13TeV2016.txt -m 1000
#combine -M AsymptoticLimits --noFitAsimov limits_wz_13TeV2016.txt -m 900
#combine -M AsymptoticLimits --noFitAsimov limits_wz_13TeV2016.txt -m 800
#combine -M AsymptoticLimits --noFitAsimov limits_wz_13TeV2016.txt -m 700
#combine -M AsymptoticLimits --noFitAsimov limits_wz_13TeV2016.txt -m 600

#combine -M AsymptoticLimits --noFitAsimov limits_wz_ll_13TeV2016.txt -m 2000
#combine -M AsymptoticLimits --noFitAsimov limits_wz_ll_13TeV2016.txt -m 1500
#combine -M AsymptoticLimits --noFitAsimov limits_wz_ll_13TeV2016.txt -m 1000
#combine -M AsymptoticLimits --noFitAsimov limits_wz_ll_13TeV2016.txt -m 900
#combine -M AsymptoticLimits --noFitAsimov limits_wz_ll_13TeV2016.txt -m 800
#combine -M AsymptoticLimits --noFitAsimov limits_wz_ll_13TeV2016.txt -m 700
#combine -M AsymptoticLimits --noFitAsimov limits_wz_ll_13TeV2016.txt -m 600

#text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose --PO 'map=.*/Higgs1:r[1,0,10]' --PO 'map=.*/Higgs2:r' limits_comb_13TeV016.txt -o limits_wv.root -m 2000
#combine -M AsymptoticLimits --noFitAsimov limits_wv.root -m 2000
#text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose --PO 'map=.*/Higgs1:r[1,0,10]' --PO 'map=.*/Higgs2:r' limits_comb_13TeV016.txt -o limits_wv.root -m 1500
#combine -M AsymptoticLimits --noFitAsimov limits_wv.root -m 1500
#text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose --PO 'map=.*/Higgs1:r[1,0,10]' --PO 'map=.*/Higgs2:r' limits_comb_13TeV016.txt -o limits_wv.root -m 1000
#combine -M AsymptoticLimits --noFitAsimov limits_wv.root -m 1000
#text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose --PO 'map=.*/Higgs1:r[1,0,10]' --PO 'map=.*/Higgs2:r' limits_comb_13TeV016.txt -o limits_wv.root -m 900
#combine -M AsymptoticLimits --noFitAsimov limits_wv.root -m 900
#text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose --PO 'map=.*/Higgs1:r[1,0,10]' --PO 'map=.*/Higgs2:r' limits_comb_13TeV016.txt -o limits_wv.root -m 800
#combine -M AsymptoticLimits --noFitAsimov limits_wv.root -m 800
#text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose --PO 'map=.*/Higgs1:r[1,0,10]' --PO 'map=.*/Higgs2:r' limits_comb_13TeV016.txt -o limits_wv.root -m 700
#combine -M AsymptoticLimits --noFitAsimov limits_wv.root -m 700
#text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose --PO 'map=.*/Higgs1:r[1,0,10]' --PO 'map=.*/Higgs2:r' limits_comb_13TeV016.txt -o limits_wv.root -m 600
#combine -M AsymptoticLimits --noFitAsimov limits_wv.root -m 600

combine -M AsymptoticLimits  limits_ww_13TeV2016.txt -m 2000
combine -M AsymptoticLimits  limits_ww_13TeV2016.txt -m 1500
combine -M AsymptoticLimits  limits_ww_13TeV2016.txt -m 1000
combine -M AsymptoticLimits  limits_ww_13TeV2016.txt -m 900
combine -M AsymptoticLimits  limits_ww_13TeV2016.txt -m 800
combine -M AsymptoticLimits  limits_ww_13TeV2016.txt -m 700
combine -M AsymptoticLimits  limits_ww_13TeV2016.txt -m 600

#combine -M AsymptoticLimits  limits_wz_ll_13TeV2016.txt -m 2000
#combine -M AsymptoticLimits  limits_wz_ll_13TeV2016.txt -m 1500
#combine -M AsymptoticLimits  limits_wz_ll_13TeV2016.txt -m 1000
#combine -M AsymptoticLimits  limits_wz_ll_13TeV2016.txt -m 900
#combine -M AsymptoticLimits  limits_wz_ll_13TeV2016.txt -m 800
#combine -M AsymptoticLimits  limits_wz_ll_13TeV2016.txt -m 700
#combine -M AsymptoticLimits  limits_wz_ll_13TeV2016.txt -m 600

#combine -M AsymptoticLimits  limits_wz_13TeV2016.txt -m 2000
#combine -M AsymptoticLimits  limits_wz_13TeV2016.txt -m 1500
#combine -M AsymptoticLimits  limits_wz_13TeV2016.txt -m 1000
#combine -M AsymptoticLimits  limits_wz_13TeV2016.txt -m 900
#combine -M AsymptoticLimits  limits_wz_13TeV2016.txt -m 800
#combine -M AsymptoticLimits  limits_wz_13TeV2016.txt -m 700
#combine -M AsymptoticLimits  limits_wz_13TeV2016.txt -m 600

#text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose --PO 'map=.*/Higgs1:r[1,0,10]' --PO 'map=.*/Higgs2:r' limits_comb_13TeV016.txt -o limits_wv.root -m 2000
#combine -M AsymptoticLimits  limits_wv.root -m 2000
#text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose --PO 'map=.*/Higgs1:r[1,0,10]' --PO 'map=.*/Higgs2:r' limits_comb_13TeV016.txt -o limits_wv.root -m 1500
#combine -M AsymptoticLimits  limits_wv.root -m 1500
#text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose --PO 'map=.*/Higgs1:r[1,0,10]' --PO 'map=.*/Higgs2:r' limits_comb_13TeV016.txt -o limits_wv.root -m 1000
#combine -M AsymptoticLimits limits_wv.root -m 1000
#text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose --PO 'map=.*/Higgs1:r[1,0,10]' --PO 'map=.*/Higgs2:r' limits_comb_13TeV016.txt -o limits_wv.root -m 900
#combine -M AsymptoticLimits  limits_wv.root -m 900
#text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose --PO 'map=.*/Higgs1:r[1,0,10]' --PO 'map=.*/Higgs2:r' limits_comb_13TeV016.txt -o limits_wv.root -m 800
#combine -M AsymptoticLimits limits_wv.root -m 800
#text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose --PO 'map=.*/Higgs1:r[1,0,10]' --PO 'map=.*/Higgs2:r' limits_comb_13TeV016.txt -o limits_wv.root -m 700
#combine -M AsymptoticLimits  limits_wv.root -m 700
#text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose --PO 'map=.*/Higgs1:r[1,0,10]' --PO 'map=.*/Higgs2:r' limits_comb_13TeV016.txt -o limits_wv.root -m 600
#combine -M AsymptoticLimits limits_wv.root -m 600

python makeLimit3.py
