#include "Command.h"
#include <iostream>
using namespace std;
list<int > AnsList;													
list<int > AnsList1;
void IfUndoOrRedo(Commander* commander){						
	int ifur = 0;
	cout << "ȡ������ѡ��ȡ������1����ѡ����2����������0" << endl;
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
	cout << "��ѡ�ĺ�����" << endl;
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
	cout << "����͸" << endl;
	cout << "��ѡ���߸�������Ϊ����" << endl;
	for (int Num = 0; Num < 7;){
		AnsInputCommand* acmd = new AnsInputCommand();
		cout << "��" << Num + 1 << "������" << endl;
		cmder->addCommand(acmd);								
		showAnswer();
		
		IfUndoOrRedo(cmder);									
		Num = AnsList.size();									
	}
	cout << "ѡ��������" << endl;
	system("pause");
	return 1;
}



