set path=%path%;C:\ProgramData\Anaconda3\pkgs\python-2.7.15-he216670_0\
copy ..\Debug\CrfTagger.exe .\
python make_crf_train_data.py .\icwb2\training\msr_training.utf8 .\temp\msr_training.tagging4crf.utf8
CrfTagger.exe -L -f 3 -c 4.0 -p 12 .\data\template .\temp\msr_training.tagging4crf.utf8 .\data\model
python make_crf_test_data.py .\icwb2\testing\msr_test.utf8 .\temp\msr_test4crf.utf8
CrfTagger.exe -T -m .\data\model .\temp\msr_test4crf.utf8 > .\temp\msr_test4crf.tag.utf8
python crf_data_2_word.py .\temp\msr_test4crf.tag.utf8 .\temp\msr_test4crf.tag2word.utf8
perl .\icwb2\scripts\score.pl .\icwb2\gold\msr_training_words.utf8 .\icwb2\gold\msr_test_gold.utf8 .\temp\msr_test4crf.tag2word.utf8 > msr_crf_segment.score