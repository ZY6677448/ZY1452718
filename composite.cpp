#include "Composite.h"
int main(int argc, char **argv)

{
    File *file1 = new Directory;
	File *file2 = new Directory;
	File *file3 = new PhysicalFile;

	file2->add(file3);
	file1->add(file2);

	File *file4 = new Directory;
	File *file5 = new Directory;
	File *file6 = new Directory;
	File *file7 = new PhysicalFile;


	file6->add(file7);
	file5->add(file6);
	file4->add(file5);
	file1->add(file4);

	file1->process();
	file1->remove(file4);

	cout << ".......É¾³ýfile4Ö®ºó........." << endl;

	file1->process();
	
	

	return 0;

}
