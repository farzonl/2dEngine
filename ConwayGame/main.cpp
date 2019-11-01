#include <engine.h>

int cellDimm = 20;
int COLS, ROWS;

//cellGrid = live or dead cells
//cellCount = count of neihbors
boolean **cellGridOld, **cellGridNew;
int **cellCount;
int iter = 0;
boolean bPaused = true;
boolean bSetStepMode = false;
String runMode;

// _______ Function Headers __________\\

void setRunMode();
void writeLine(String S, int i);
void grid();
void updateGrid();
void rulesOfLife(int x, int y);
void countAllNeighbors(int x, int y);
void swapgrids();
void drawLife();
void randomGrid();
void drawLightWeightSpaceship(int x, int y);
void drawGlider(int x, int y);
void drawHeavyWeightSpaceship(int x, int y);
void drawBlinker(int x, int y); 
void drawBeacon(int x, int y);
void drawBlock(int x, int y);
int getYMinusOne(int y);
int getYPlusThree(int y);
int getYPlusTwo(int y);
int getYPlusOne(int y);
int getXPlusThree(int x);
int getXPlusTwo(int x);
int getXMinusOne(int x);
int getXPlusOne(int x);
int getRowIndex(int base, int offset);
int getColIndex(int base, int offset);
int getIndex(int base, int offset, int modBy);

// _______ Function Headers __________\\

void setRunMode() {
	if (bPaused) {
		runMode = "paused";
		if (bSetStepMode) {
			runMode += " and single step";
		}
	}
	else {
		runMode = "running";
	}
}

void WINAPI setup() {
	size(800, 600);
	//smooth(); //TODO
	setRunMode();
	//initialize rows, columns and set-up arrays
	COLS = width() / cellDimm;
	ROWS = height() / cellDimm;
	background(0,0,0); // TODO: background(black);
	cellGridOld = matAlloc<boolean>(COLS,ROWS);
	cellGridNew = matAlloc<boolean>(COLS, ROWS);
	cellCount = matAlloc<int>(COLS, ROWS);
	//textSize(18); //TODO
}

void writeLine(String S, int i) {
	// writes S at line i
	//text(S, 30, 25 + i * 40); //TODO
}

void WINAPI draw()
{
	fill(0.0f, 0.0f, 0.0f); //TODO fill(black);
	//rectMode(CORNER); //TODO
	rect(0, 0, width(), height());

	grid();
	if (!bPaused) {
		updateGrid();
		iter++;
	}
	drawLife();
	if (bSetStepMode) {
		bPaused = true;
	}

	fill(1.0f, 0.0f, 1.0f); //TODO: fill(magenta);
	int L = 0; // line counter, incremented below for ech line
	writeLine("cell count: " + COLS * ROWS, L++);
	writeLine("Iteration " + iter, L++);
	writeLine("Mode: " + runMode, L++);
}

void grid() {
  for (int c=0; c<=COLS; c++) {
    for (int r=0; r<=ROWS; r++) {
		stroke(1.0f, 1.0f, 1.0f); //TODO: stroke(white);
		noFill();
		//rectMode(CENTER); //TODO
      rect(c*cellDimm, r*cellDimm, cellDimm, cellDimm);    
    }
  }
}

void updateGrid() {
	for (int x = 0; x < COLS; x++) {
		for (int y = 0; y < ROWS; y++) {
			countAllNeighbors(x, y);
			rulesOfLife(x, y);
		}
	}
	swapgrids();
	matDel(cellCount,COLS);
	cellCount = matAlloc<int>(COLS, ROWS);
}

void rulesOfLife(int x, int y) {
  if ((cellGridOld[x][y] == true) && (cellCount[x][y] <  2)) {
    cellGridNew[x][y] = false; 
  } else if ((cellGridOld[x][y] == true) && (cellCount[x][y] >  3)) {
    cellGridNew[x][y] = false; 
  } else if ((cellGridOld[x][y] == false) && (cellCount[x][y] == 3)) { 
    cellGridNew[x][y] = true; 
  } else { 
    cellGridNew[x][y] = cellGridOld[x][y]; 
  }
}

void countAllNeighbors(int x, int y) {
  for(int xn=-1; xn <= 1; xn++) {
    for(int yn = -1; yn <= 1; yn++) {
      if(xn == 0 && yn == 0) {
        continue;
      }
      int xx = (x + xn + COLS) % COLS;
      int yy = (y + yn + ROWS) % ROWS;
      if(cellGridOld[xx][yy]) {
        cellCount[x][y] += 1;
      }
    }
  }
}

void randomGrid() 
{
  for ( int c = 0; c < COLS;c++) 
  {
    for ( int r = 0; r < ROWS;r++) 
    {
      if (random(0,1) > 0.5f) {
        cellGridNew[c][r] = true;
        cellGridOld[c][r] = true;
      } else {
        cellGridNew[c][r] = false;
        cellGridOld[c][r] = false;
      }
    }
  }
}

void drawLife() 
{
  for ( int c = 0; c < COLS;c++) 
  {
    for ( int r = 0; r < ROWS;r++) 
    {
      if (cellGridNew[c][r]) 
      {
		noStroke();
		fill(1.0f, 0.0f, 1.0f);// TODO: fill(white);
        ellipse(c*cellDimm, r*cellDimm,cellDimm/2.0f,cellDimm / 2.0f);
      }
    }
  }
}

void swapgrids() {
	matSwap(cellGridNew, cellGridOld, COLS);
}

void WINAPI keyPressed(char key) {
	if (key == 'p' || key == 'P')
	{
		bPaused = !bPaused;
		setRunMode();
	}
	if (key == 'c' || key == 'C')
	{
		matDel(cellGridOld, COLS);
		matDel(cellGridNew, COLS);
		cellGridOld = matAlloc<boolean>(COLS,ROWS);
		cellGridNew = matAlloc<boolean>(COLS,ROWS);
		bPaused = true;
		matDel(cellCount, COLS);
		cellCount = matAlloc<int>(COLS,ROWS);
	}
	if (key == 'r' || key == 'R')
	{
		randomGrid();
	}
	if (key == 'g' || key == 'G')
	{
		bSetStepMode = !bSetStepMode;
		setRunMode();
	}
	if (key == ' ') {
		bPaused = false;
	}
	if (key == '1')
	{
		bPaused = true;
		drawLightWeightSpaceship((int)random(COLS), (int)random(ROWS));
	}

	if (key == '2')
	{
		bPaused = true;
		drawHeavyWeightSpaceship((int)random(COLS), (int)random(ROWS));
	}
	if (key == '3') {
		bPaused = true;
		drawGlider((int)random(COLS), (int)random(ROWS));
	}
	if (key == '4') {
		bPaused = true;
		drawBeacon((int)random(COLS), (int)random(ROWS));
	}

	if (key == '5') {
		bPaused = true;
		drawBlinker((int)random(COLS), (int)random(ROWS));
	}
}

int getIndex(int base, int offset, int modBy) {
	return (base + offset + modBy) % modBy;
}

int getColIndex(int base, int offset) {
	return getIndex(base, offset, COLS);
}

int getRowIndex(int base, int offset) {
	return getIndex(base, offset, ROWS);
}

int getXPlusOne(int x) {
	return getColIndex(x, 1);
}

int getXMinusOne(int x) {
	return getColIndex(x, -1);
}

int getXPlusTwo(int x) {
	return getColIndex(x, 2);
}

int getXPlusThree(int x) {
	return getColIndex(x, 3);
}

int getYPlusOne(int y) {
	return getRowIndex(y, 1);
}

int getYPlusTwo(int y) {
	return getRowIndex(y, 2);
}

int getYPlusThree(int y) {
	return getRowIndex(y, 3);
}

int getYMinusOne(int y) {
	return getRowIndex(y, -1);
}

void drawBlock(int x, int y) {
	cellGridNew[x][y] = true;
	cellGridOld[x][y] = true;

	int xplusOne = getXPlusOne(x);
	cellGridNew[xplusOne][y] = true;
	cellGridOld[xplusOne][y] = true;

	int yplusOne = getYPlusOne(y);
	cellGridNew[x][yplusOne] = true;
	cellGridOld[x][yplusOne] = true;

	cellGridNew[xplusOne][yplusOne] = true;
	cellGridOld[xplusOne][yplusOne] = true;
}

void drawBeacon(int x, int y) {
	int xplustwo = getXPlusTwo(x);
	int yplustwo = getYPlusTwo(y);
	drawBlock(x, y);
	drawBlock(xplustwo, yplustwo);
}

void drawBlinker(int x, int y) {
	int xplustwo = getXPlusTwo(x);
	int xplusone = getXPlusOne(x);

	cellGridNew[x][y] = true;
	cellGridOld[x][y] = true;

	cellGridNew[xplusone][y] = true;
	cellGridOld[xplusone][y] = true;

	cellGridNew[xplustwo][y] = true;
	cellGridOld[xplustwo][y] = true;
}

void drawHeavyWeightSpaceship(int x, int y) {
  cellGridNew[x][y] = true;
  cellGridOld[x][y] = true;
  
  int xplusOne = getXPlusOne(x);
  cellGridNew[xplusOne][y] = true;
  cellGridOld[xplusOne][y] = true;
  
  int xplusThree = getXPlusThree(x);
  int yplusOne = getYPlusOne(y);
  cellGridNew[xplusThree][yplusOne] = true;
  cellGridOld[xplusThree][yplusOne] = true;
  
  int yplusThree = getYPlusThree(y);
  cellGridNew[xplusThree][yplusThree] = true;
  cellGridOld[xplusThree][yplusThree] = true;
  
  int yplusFour = getRowIndex(y,4);
  int xplusTwo = getXPlusTwo(x);
  
  cellGridNew[xplusTwo][yplusFour] = true;
  cellGridOld[xplusTwo][yplusFour] = true;
  
  cellGridNew[xplusOne][yplusFour] = true;
  cellGridOld[xplusOne][yplusFour] = true;
  
  cellGridNew[x][yplusFour] = true;
  cellGridOld[x][yplusFour] = true;
  
  int xminus1 = getXMinusOne(x);
  int xminus2 = getColIndex(x,-2);
  int xminus3 = getColIndex(x,-3);
  
  cellGridNew[xminus1][yplusFour] = true;
  cellGridOld[xminus1][yplusFour] = true;
  
  cellGridNew[xminus2][yplusFour] = true;
  cellGridOld[xminus2][yplusFour] = true;
  
  cellGridNew[xminus3][yplusFour] = true;
  cellGridOld[xminus3][yplusFour] = true;
  
  cellGridNew[xminus3][yplusThree] = true;
  cellGridOld[xminus3][yplusThree] = true;
  
  int yplusTwo = getYPlusTwo(y);
  cellGridNew[xminus3][yplusTwo] = true;
  cellGridOld[xminus3][yplusTwo] = true;
  
  cellGridNew[xminus2][yplusOne] = true;
  cellGridOld[xminus2][yplusOne] = true;
  
  
}

void drawGlider(int x, int y) {
  cellGridNew[x][y] = true;
  cellGridOld[x][y] = true;
  int xminusOne = getXMinusOne(x);
  int xplusOne = getXPlusOne(x);
  
  cellGridNew[xminusOne][y] = true;
  cellGridOld[xminusOne][y] = true;
  
  cellGridNew[xplusOne][y] = true;
  cellGridOld[xplusOne][y] = true;
  
  int yminusOne = getYMinusOne(y);
  
  cellGridNew[xplusOne][yminusOne] = true;
  cellGridOld[xplusOne][yminusOne] = true;
  
  int yminusTwo = getRowIndex(y,-2);
   cellGridNew[x][yminusTwo] = true;
  cellGridOld[x][yminusTwo] = true;
  
}

void drawLightWeightSpaceship(int x, int y) {
  cellGridNew[x][y] = true;
  cellGridOld[x][y] = true;
  int xplusThree = getXPlusThree(x);
  
  cellGridNew[xplusThree][y] = true;
  cellGridOld[xplusThree][y] = true;
  
  int xminusOne = getXMinusOne(x);
  int yplusOne = getYPlusOne(y);
  cellGridNew[xminusOne][yplusOne] = true;
  cellGridOld[xminusOne][yplusOne] = true;
  
  int yplusTwo = getYPlusTwo(y);
  int yplusThree = getYPlusThree(y);
  cellGridNew[xminusOne][yplusTwo] = true;
  cellGridOld[xminusOne][yplusTwo] = true;
  
  cellGridNew[xminusOne][yplusThree] = true;
  cellGridOld[xminusOne][yplusThree] = true;
  
  cellGridNew[x][yplusThree] = true;
  cellGridOld[x][yplusThree] = true;
  
  int xplusOne = getXPlusOne(x);
  cellGridNew[xplusOne][yplusThree] = true;
  cellGridOld[xplusOne][yplusThree] = true;
  
  int xplusTwo = getXPlusTwo(x);
  cellGridNew[xplusTwo][yplusThree] = true;
  cellGridOld[xplusTwo][yplusThree] = true;
  
  cellGridNew[xplusThree][yplusTwo] = true;
  cellGridOld[xplusThree][yplusTwo] = true;
}

void WINAPI mousePressed(int mouseX, int mouseY)
{
   if (mouseX < width() && mouseX >0 && mouseY <height() && mouseY > 0) 
   {
     int msX = mouseX/cellDimm;
     int msY = mouseY/cellDimm;
     cellGridNew[msX][msY] = !cellGridNew[msX][msY];
     cellGridOld[msX][msY] = !cellGridOld[msX][msY];
     drawLife();
  }  
}