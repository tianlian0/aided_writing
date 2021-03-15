# 辅助写作工具
本项目为一个基于c#和c++开发的中文写作辅助工具。可在写作时实现千万级字次的实时检索匹配，推荐后文内容。让写作像写代码一样可以“自动补全”。【2021年注：这个是几年前写着玩的项目，现在已经不维护了。】  

#### 灵感来源
之前做了查重系统（参见项目：https://github.com/tianlian0/paper_checking_system ），获得了一些论文数据。写材料时我想，能不能基于论文库构建一个辅助写作工具，于是这个项目诞生了。  
可以根据上文输入自动推荐后文内容，像写代码一样自动补全你的文章。项目演示demo见后方的视频链接。  

#### 操作说明
使用回车键键入候选，使用上下键选择候选。当你想输入一个回车时，需要先输入一个句号。  

#### 使用/编译/自定义数据说明
1、首先需要拥有一些特定领域的简体中文语料数据。如果这些数据分布在很多文件当中，则需要将它们追加到一个文本文件中。  
2、跑TxtPreprocessing.py这个脚本对步骤一中的数据进行处理，将其中除了汉字和个别标点符号意外的字符都去掉。其中src_path为语料的原始路径，dist_path为处理后的输出路径。不用我提供的脚本，用自己的方式来处理也可以，但需要保证最后输出的文件是GB18030编码的  
3、跑MapPreprocessing.cpp，将步骤二中得到的数据作为输入。在这一步骤中，程序会将数据生成倒排表索引存储到文件中。其中src_data_path是原始路径，res_map_path为输出路径。  
4、将“辅助写作”中的res_map_path改为步骤三输出文件的路径，并编译运行。  
注：本项目中自带一份简单的测试数据，您如果只是想进行简单体验，可以无视前三个步骤，直接编译后在文本框中输入“自动处理”四个字进行体验。  

#### 原理说明
MapPreprocessing.cpp对原始语料进行全切分，并根据频率建立倒排索引，存储到map中，再将map中的数据写入文件。  
“辅助写作”将MapPreprocessing.cpp生成的倒排索引读入内存，实现实时查找。  

#### 性能说明
内存：为了实现实时检索，其内存消耗较为巨大。预处理阶段，千万级字次的语料内存占用峰值约为5GB，产生约1GB的倒排索引文件。实际运行阶段，倒排索引文件读入约占用内存3GB。  
时间：预处理阶段，千万级字次的语料用时约10分钟。实际运行阶段，程序启动时需要读入索引文件，耗时约30秒。检索阶段为实时检索。  

#### 其它说明
1、TxtPreprocessing.py是一个python脚本；MapPreprocessing.cpp是C++编写的预处理程序；“辅助写作”是一个由C#开发的图形界面程序。  
2、“使用说明”中的步骤1、2、3其实都是数据预处理，可以根据自己的喜好自己写脚本实现，不一定非要用本项目中提供的脚本。  
3、本项目所用的语料数据不方便提供。  
4、本项目仅供个人技术交流、研究，请勿用作其它目的。  

#### 项目截图
![image](https://github.com/tianlian0/aided_writing/blob/master/images/pic1.png)  
项目运行演示视频：链接：https://pan.baidu.com/s/1QogEqIwmGTxn1NSEIjy9qQ 提取码：yq9e  

#### 欢迎打赏
![image](https://github.com/tianlian0/aided_writing/blob/master/images/shang.png)  
