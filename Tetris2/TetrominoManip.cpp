bool move(int INdir, int INud)
	{
	int canMove=0;
	int addLR  =0;
	int addUD  =0;
	int tempLR =0;
	int tempUD =0;
	if			(INdir==dwn) addUD=-1;
	else if (INdir==lft) addLR= 1;
	else if (INdir==rht) addLR=-1;
	for (int i=0; i<4; i++)
		{
		tempLR=tet[currentPiece+currentRotate][i	]+tetLR+addLR;
		tempUD=tet[currentPiece+currentRotate][i+4]+INud +addUD;
		if ((tempLR>=0)&&(tempLR<width)&&(tempUD>=0)) //&&(tempUD<height)
			{canMove+=(area[tempLR][tempUD]);}
		else canMove++;
		}
	//NumOut(0,16,canMove,0);
	//Wait(500);
	return (canMove==0); //canMove in:	0123	0123
	}										//canMove out: 1000	TFFF


bool rotate()
	{
	int canRotate=1, addRot=0, tempLR, tempUD, addUD=0, addLR=0;
	addRot=(currentRotate+1)%4;
	for (int i=0; (i<3 && canRotate>0); i++)
		{
		if (i==0) addUD= 0;	//1st	Level
		if (i==1) addUD=-1;	//2nd	D
		if (i==2) addUD= 1;	//3rd	U
		if (i==3) addUD=-2*(currentPiece*4==Itet);	//4th D if I tetromino
		if (i==4) addUD= 2*(currentPiece*4==Itet);	//5th U if I tetromino
		for (int j=0; (j<5 && canRotate>0); j++)
			{
			if (j==0) addLR= 0;	//1st	Center
			if (j==1) addLR=-1;	//2nd	L
			if (j==2) addLR= 1;	//3rd	R
			if (j==3) addLR=-2*(currentPiece*4==Itet);	//4th L if I tetromino
			if (j==4) addLR= 2*(currentPiece*4==Itet);	//5th R if I tetromino
			canRotate=0;
			for (int k=0; k<4; k++)
				{
				tempLR=tet[currentPiece+currentRotate+addRot][k	]+tetLR+addLR;
				tempUD=tet[currentPiece+currentRotate+addRot][k+4]+tetUD+addUD;
				if ((tempLR>=0)&&(tempUD>=0)&&(tempLR<width)&&(tempUD<height+2)&&(tetUD>0))
					{canRotate+=(area[tempLR][tempUD]);}
				else {canRotate++;}
				}
			}
		}
	if (canRotate==0)
		{
		//if (!(addUD>0 && floorKickUsed==true))
			//{
			tetLR+=addLR;
			tetUD+=addUD;
			//if (addUD>0) floorKickUsed=true;
			//}
		}
	return (canRotate==0);
	}
	
	
	

void pieceCreate()
	{
	int pieceToCreate=prob;
	int rndm=(rand())%(chnc[prob]);
	int add=0;
	for (int j=0; (j<=Ztet)&&(pieceToCreate==prob); j++)
		{
		add+=chnc[j];
		if (add>rndm) pieceToCreate=j*4;
		}
	if (pieceToCreate==prob)
		{
		ClearScreen();
		TextOutput(0,24,add ,0);
		TextOutput(0,16,rndm,0);
		TextOutput(0,00,0,0);
		Wait(1000);
		}
	currentPiece=nextPiece[0];
	for (int i=1; i<previewPieces; i++)
		{
		//PlayTone(1000,500);Wait(500);
		nextPiece[i-1]=nextPiece[i];
		}
	nextPiece[previewPieces-1]=pieceToCreate;
	}


void pieceSetInto(int pieceType)
	{
	int tempLR,tempUD;
	for (int i=0; i<4; i++)
		{
		tempLR=tet[currentPiece+currentRotate][i  ]+tetLR;
		tempUD=tet[currentPiece+currentRotate][i+4]+tetUD;
		area[tempLR][tempUD]=pieceType+1;
		}
	}


int clearFullRows()
	{
	int blocksInRow=0;
	int numOfFilledLines=0;
	int i,j,k;
	for (i=0; i<height+2; i++)					 //Check All Rows
		{
		blocksInRow=0;
		for (j=0; j<width; j++)						//Add up blocks in row
			{
			blocksInRow+=(area[j][i]);
			}
		if (blocksInRow==width&&i<height)	//If the row is full)
			{
			for (k=i; k<height; k++)				 //Move higher rows down
				{
				for (j=0; j<width; j++)
					{
					//int temp=area[j][k];
					//SendResponseNumber(9,temp);
					area[j][k]=area[j][k+1];
					}
				}
			i--; //redo row if it gets destroyed
			numOfFilledLines++;
			}
		else if (blocksInRow>0&&i>=height)
			{
			alive=false;
			}
		}

	//add to score
	if			(numOfFilledLines==1)		{score+=100; prevQuadClear=false; disp=1;}
	else if (numOfFilledLines==2)		{score+=300; prevQuadClear=false; disp=2;}
	else if (numOfFilledLines==3)		{score+=500; prevQuadClear=false; disp=3;}
	else if (numOfFilledLines==4)
	{if (prevQuadClear) {score+=400;} score+=800; prevQuadClear=true;	disp=4;}
	return numOfFilledLines;
	}