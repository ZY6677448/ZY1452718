#include "Command.h"
#include <iostream>
using namespace std;
extern list<int > AnsList;
extern list<int > AnsList1;

AnsInputCommand::AnsInputCommand(){

}
void AnsInputCommand::execute(){
	cout << "ÇëÊäÈëÑ¡ÔñºÅÂë" << endl;
	int ans;
	cin >> ans;
	AnsList.push_back(ans);
};
void AnsInputCommand::unexecute(){
	AnsList1.push_back(AnsList.back());
	AnsList.pop_back();
};
void AnsInputCommand::reexecute(){
	AnsList.push_back(AnsList1.back());
	AnsList1.pop_back();
};
Commander::Commander(){

};
Commander::Commander(Command* cmd){
	undoStk.push(cmd);
};
Commander::~Commander(){
	while (false == undoStk.empty()){
		delete undoStk.top();
		undoStk.pop();
	}
	while (false == redoStk.empty()){
		delete redoStk.top();
		redoStk.pop();
	}
};
void Commander::undo(){
	Command* cmd = undoStk.top();
	redoStk.push(cmd);
	cmd->unexecute();
	undoStk.pop();
};
void Commander::redo(){
	Command* cmd = redoStk.top();
	undoStk.push(cmd);
	cmd->reexecute();
	redoStk.pop();
};
void Commander::addCommand(Command *cmd){
	cmd->execute();
	undoStk.push(cmd);
}

