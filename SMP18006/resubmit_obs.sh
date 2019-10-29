#!/bin/bash

range=0.3
#python buildWorkspace_AC.py --config=config_TF1_wv_plain_8bin
#text2workspace.py -m 126 aC_ch1_splitted_TF1.txt -o Example_test.root -P CombinedEWKAnalysis.CommonTools.ACModel:par1_TF1_Model --PO channels=ch1_splitted_TF1  --PO poi=hfs0 --PO range_hfs0=-${range},${range}
#combine Example_test.root -M MultiDimFit -P hfs0 --floatOtherPOIs=0 --algo=grid --points=2000 --minimizerStrategy=2  
#python build1DInterval.py -${range} ${range} higgsCombineTest.MultiDimFit.mH120.root hfs0

#python buildWorkspace_AC.py --config=config_TF1_zv_plain_8bin
#text2workspace.py -m 126 aC_ch2_splitted_TF1.txt -o Example_test.root -P CombinedEWKAnalysis.CommonTools.ACModel:par1_TF1_Model --PO channels=ch2_splitted_TF1  --PO poi=hfs0 --PO range_hfs0=-${range},${range}
#combine Example_test.root -M MultiDimFit -P hfs0 --floatOtherPOIs=0 --algo=grid --points=500 --minimizerStrategy=2
#python build1DInterval.py -${range} ${range} higgsCombineTest.MultiDimFit.mH120.root hfs0

combineCards.py aC_ch1_splitted_TF1.txt aC_ch2_splitted_TF1.txt > aC_splitted_TF1.txt
text2workspace.py -m 126 aC_splitted_TF1.txt -o Example_test.root -P CombinedEWKAnalysis.CommonTools.ACModel:par1_TF1_Model --PO channels=ch1_splitted_TF1,ch2_splitted_TF1  --PO poi=hfs0 --PO range_hfs0=-${range},${range}
combine Example_test.root -M MultiDimFit -P hfs0 --floatOtherPOIs=0 --algo=grid --points=2000 --minimizerStrategy=2
python build1DInterval.py -${range} ${range} higgsCombineTest.MultiDimFit.mH120.root hfs0
