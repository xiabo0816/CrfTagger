// CrfTagger.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

/*
【日语小语料】
数据来源：crfpp / example / seg
CrfTagger.exe - L - f 3 - c 4.0 data / template data / train.data data / model
CrfTagger.exe - T - m data / model data / test.data

【SIGHAN2005】
数据来源：icwb2-data.zip
下载地址：
http://sighan.cs.uchicago.edu/bakeoff2005/
http://sighan.cs.uchicago.edu/bakeoff2005/data/icwb2-data.zip

*/



#include "pch.h"
#include <iostream>
#include "crfpp/crfpp.h"
#include "crfpp/param.h"
using namespace std;

// c++ -O3 example.cpp -lcrfpp

//-L -f 3 -c 4.0 data/template data/train.data data/model
//-T -m data/model data/test.data
const CRFPP::Option main_options[] = {
  {"learn",     'L', 0,       0,
   "use CRFTagger to learn model" },
  {"test" , 'T',  0,       0,
   "use CRFTagger to test model" },
};

int main(int argc, char **argv) {
	CRFPP::Param param;
	param.open(argc, argv, main_options);
	if (param.get_conf_size() != 1) {
		param.dump_config(&cout);
		return 0;
	}else if (param.get<bool>("learn")) {
		return crfpp_learn(argc, argv);
	}else if (param.get<bool>("test")) {
		return crfpp_test(argc, argv);
	}else {
		param.dump_config(&cout);
		return 0;
	}


	// -v 3: access deep information like alpha,beta,prob
	// -nN: enable nbest output. N should be >= 2
	CRFPP::Tagger *tagger =
		CRFPP::createTagger("-m model -v 3 -n2");

	if (!tagger) {
		std::cerr << CRFPP::getTaggerError() << std::endl;
		return -1;
	}

	// clear internal context
	tagger->clear();

	// add context
	tagger->add("Confidence NN");
	tagger->add("in IN");
	tagger->add("the DT");
	tagger->add("pound NN");
	tagger->add("is VBZ");
	tagger->add("widely RB");
	tagger->add("expected VBN");
	tagger->add("to TO");
	tagger->add("take VB");
	tagger->add("another DT");
	tagger->add("sharp JJ");
	tagger->add("dive NN");
	tagger->add("if IN");
	tagger->add("trade NN");
	tagger->add("figures NNS");
	tagger->add("for IN");
	tagger->add("September NNP");

	std::cout << "column size: " << tagger->xsize() << std::endl;
	std::cout << "token size: " << tagger->size() << std::endl;
	std::cout << "tag size: " << tagger->ysize() << std::endl;

	std::cout << "tagset information:" << std::endl;
	for (size_t i = 0; i < tagger->ysize(); ++i) {
		std::cout << "tag " << i << " " << tagger->yname(i) << std::endl;
	}

	// parse and change internal stated as 'parsed'
	if (!tagger->parse()) return -1;

	std::cout << "conditional prob=" << tagger->prob()
		<< " log(Z)=" << tagger->Z() << std::endl;

	for (size_t i = 0; i < tagger->size(); ++i) {
		for (size_t j = 0; j < tagger->xsize(); ++j) {
			std::cout << tagger->x(i, j) << '\t';
		}
		std::cout << tagger->y2(i) << '\t';
		std::cout << std::endl;

		std::cout << "Details";
		for (size_t j = 0; j < tagger->ysize(); ++j) {
			std::cout << '\t' << tagger->yname(j) << "/prob=" << tagger->prob(i, j)
				<< "/alpha=" << tagger->alpha(i, j)
				<< "/beta=" << tagger->beta(i, j);
		}
		std::cout << std::endl;
	}

	// when -n20 is specified, you can access nbest outputs
	std::cout << "nbest outputs:" << std::endl;
	for (size_t n = 0; n < 10; ++n) {
		if (!tagger->next()) break;
		std::cout << "nbest n=" << n << "\tconditional prob=" << tagger->prob() << std::endl;
		// you can access any information using tagger->y()...
	}
	std::cout << "Done" << std::endl;

	delete tagger;

	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
