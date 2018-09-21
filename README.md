# CrfTagger
Crf tagger using @[Crfpp](https://github.com/taku910/crfpp) @[Windows](https://www.microsoft.com/zh-cn/windows) @[Visual Studio](https://visualstudio.microsoft.com/zh-hans/)

操作流程参考：
[中文分词入门之字标注法4@52nlp](http://www.52nlp.cn/%E4%B8%AD%E6%96%87%E5%88%86%E8%AF%8D%E5%85%A5%E9%97%A8%E4%B9%8B%E5%AD%97%E6%A0%87%E6%B3%A8%E6%B3%954)

##数据资料

###[日语小语料](https://github.com/taku910/crfpp/tree/master/example/seg)
```
数据来源：crfpp/example/seg
CrfTagger.exe -L -f 3 -c 4.0 -p 12 data/template data/train.data data/model
CrfTagger.exe -T -m data/model data/test.data
```

###[SIGHAN2005](http://sighan.cs.uchicago.edu/bakeoff2005/)
```
数据来源：icwb2-data.zip
下载地址：
http://sighan.cs.uchicago.edu/bakeoff2005/data/icwb2-data.zip
```


##Reference

[中文分词入门之字标注法4@52nlp](http://www.52nlp.cn/%E4%B8%AD%E6%96%87%E5%88%86%E8%AF%8D%E5%85%A5%E9%97%A8%E4%B9%8B%E5%AD%97%E6%A0%87%E6%B3%A8%E6%B3%954)

[GnuWin32](http://gnuwin32.sourceforge.net/packages/diffutils.htm)

===========================