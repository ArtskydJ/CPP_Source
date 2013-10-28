int readHigh(int INaccess)
	{
	return 0;
	}

int writeHigh(int INaccess, int INscore)
	{
	return 0;
	}


int writeHighName(int INaccess, int INscore)
	{
	return 0;
	}

bool ButtonPressed(int INbutton)
	{
	return 0;
	}

void ClearScreen()
	{
	//std::cout<<"cls\n";
	}

void TextOutput(int x, int y, int n, int options)
	{
	//std::cout<<"text "<<n<<"\n";
	}

void Wait(int waittime)
	{
	//std::cout<<"wait/n";
	}

void LineOut(int INx, int INy, int INlen, int INwid, int INoptions)
	{
	//0, width*blksz+1, 99, width*blksz+1, 0
	}

void RectOut(int INx, int INy, int INwidth, int INheight, int INoptions)
	{
	//std::cout<<"RectOut/n";
	}

void CircleOut(int INx, int INy, int INwidth, int INoptions)
	{
	//std::cout<<"CircleOut\n";
	}

/*int senseButton(int val, bool lr_ud, int add, int high, bool cut)
	{
	int lu,rd;
	if (lr_ud)
		{
		lu=BTNLEFT;
		rd=BTNRIGHT;
		}
	else
		{
		lu=BTNCENTER;
		rd=BTNEXIT;
		}
	if (ButtonPressed(lu)) //change to on press
		{
		val-=add;
		}
	if (ButtonPressed(rd)) //change to on press
		{
		val+=add;
		}
	if (cut)
		{
		if (val<0)		{val=0;}
		if (val>high) {val=high;}
		}
	else
		{
		if (val<0)	{val=high;}
		if (val>high)	{val=0;}
		}
	return val;
	}*/
	
	
	