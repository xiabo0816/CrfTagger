# CrfTagger
Crf tagger using @[Crfpp](https://github.com/taku910/crfpp) @[Windows](https://www.microsoft.com/zh-cn/windows) @[Visual Studio](https://visualstudio.microsoft.com/zh-hans/)

操作流程参考：
[中文分词入门之字标注法4@52nlp](http://www.52nlp.cn/%E4%B8%AD%E6%96%87%E5%88%86%E8%AF%8D%E5%85%A5%E9%97%A8%E4%B9%8B%E5%AD%97%E6%A0%87%E6%B3%A8%E6%B3%954)

## 数据资料

### [日语小语料](https://github.com/taku910/crfpp/tree/master/example/seg)
```
数据来源：crfpp/example/seg
CrfTagger.exe -L -f 3 -c 4.0 -p 12 data/template data/train.data data/model
CrfTagger.exe -T -m data/model data/test.data
```

### [SIGHAN2005](http://sighan.cs.uchicago.edu/bakeoff2005/)
```
数据来源：icwb2-data.zip
下载地址：
http://sighan.cs.uchicago.edu/bakeoff2005/data/icwb2-data.zip
```

## VS编译选项
### 训练时的命令参数
-L -f 3 -c 4.0 -p 12 .\data\template .\temp\msr_training.tagging4crf.utf8 .\data\model

### C/C++
/JMC /permissive- /GS /W3 /Zc:wchar_t /ZI /Gm- /Od /sdl- /Fd"x64\Debug\vc141.pdb" /Zc:inline /fp:precise /D "HAVE_CONFIG_H" /D "_CRT_SECURE_NO_WARNINGS" /D "_DEBUG" /D "_CONSOLE" /D "_UNICODE" /D "UNICODE" /errorReport:prompt /WX- /Zc:forScope /RTC1 /Gd /MDd /FC /Fa"x64\Debug\" /EHsc /nologo /Fo"x64\Debug\" /Fp"x64\Debug\CrfTagger.pch" /diagnostics:classic 

### LINKER
/OUT:"\XXX\CrfTagger\x64\Debug\CrfTagger.exe" /MANIFEST /NXCOMPAT /PDB:"XXX\CrfTagger\x64\Debug\CrfTagger.pdb" /DYNAMICBASE "kernel32.lib" "user32.lib" "gdi32.lib" "winspool.lib" "comdlg32.lib" "advapi32.lib" "shell32.lib" "ole32.lib" "oleaut32.lib" "uuid.lib" "odbc32.lib" "odbccp32.lib" /DEBUG /MACHINE:X64 /INCREMENTAL /PGD:"XXX\CrfTagger\x64\Debug\CrfTagger.pgd" /SUBSYSTEM:CONSOLE /MANIFESTUAC:"level='asInvoker' uiAccess='false'" /ManifestFile:"x64\Debug\CrfTagger.exe.intermediate.manifest" /ERRORREPORT:PROMPT /NOLOGO /TLBID:1 

## Reference

[中文分词入门之字标注法4@52nlp](http://www.52nlp.cn/%E4%B8%AD%E6%96%87%E5%88%86%E8%AF%8D%E5%85%A5%E9%97%A8%E4%B9%8B%E5%AD%97%E6%A0%87%E6%B3%A8%E6%B3%954)

[GnuWin32](http://gnuwin32.sourceforge.net/packages/diffutils.htm)

===========================
