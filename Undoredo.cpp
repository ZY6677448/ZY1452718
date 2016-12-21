#include "Command.h"
#include <iostream>
using namespace std;
list<int > AnsList;													
list<int > AnsList1;
void IfUndoOrRedo(Commander* commander){						
	int ifur = 0;
	cout << "取消或重选？取消输入1，重选输入2，否则输入0" << endl;
	cin >> ifur;
	if (ifur == 1){
		cout << "undo" << endl;
		commander->undo();										
	}
	else if (ifur == 2){
		cout << "redo" << endl;
		commander->redo();										
	}
	else return;
	IfUndoOrRedo(commander);								
	return;
};
void showAnswer(){												
	cout << "已选的号码是" << endl;
	list<int>::iterator iter;
	for (iter = AnsList.begin(); iter != AnsList.end(); iter++){
		cout << *iter << " ";
	}
	cout << endl;
}

int getAnsNum(){												
	return AnsList.size();
}

int main(){
	Commander* cmder = new Commander();							
	cout << "大乐透" << endl;
	cout << "请选择七个数字作为号码" << endl;
	for (int Num = 0; Num < 7;){
		AnsInputCommand* acmd = new AnsInputCommand();
		cout << "第" << Num + 1 << "个号码" << endl;
		cmder->addCommand(acmd);								
		showAnswer();
		
		IfUndoOrRedo(cmder);									
		Num = AnsList.size();									
	}
	cout << "选择号码结束" << endl;
	system("pause");
	return 1;
}



