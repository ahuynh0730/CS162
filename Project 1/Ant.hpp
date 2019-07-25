/*******************************************************************************
** Author:       Anthony Huynh
** Date:         10/07/2018
** Description:  header file for ant class
*******************************************************************************/

#ifndef ANT_hpp
#define ANT_hpp

enum direction {UP, LEFT, DOWN, RIGHT};

class Ant
{
private:
	direction orientation;
	int antColumn;
	int antRow;
	int maxRow;
	int maxColumn;
	bool onWhiteSpace = true;
	bool onBlackSpace = false;

public:
	Ant(int, int);
	void setMaxRow(int);
	void setMaxColumn(int);
	void moveUp();
	void moveLeft();
	void moveDown();
	void moveRight();
	direction getOrientation();
	void changeOrientation();
	int getAntColumn();
	int getAntRow();
	void onWhiteSquare();
	void onBlackSquare();

};

#endif
