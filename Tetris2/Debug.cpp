void debugStream(int INint)
  {
  bool insideLoop=0;
  for (int i=0;i<5&&!insideLoop;i++) //check if any debugs are allowed
    {
    insideLoop+=allowDbg[i];
    }
  if (insideLoop)                   //if any are...
    {
    insideLoop=true;
    while (insideLoop)              //go to the next allowed one.
      {
      if (allowDbg[viewDbg]) insideLoop=false;
      if (insideLoop==true)  viewDbg++;
      if (viewDbg>=5)        viewDbg=0;
      }
    string str1="";
    string str2="";
    string str3="";
    string str4="";
    string str5="";
    string msg1="";
    string msg2="";
    string msg3="";
    string msg4="";
    string msg5="";
    string result;
    if      (viewDbg==0)
      {
      str1=disp;
      str2=accesshigh;
      str3=NumToStr(speedup);
      str4=NumToStr(INint); //  i/wait
      msg1="  dsp ";
      msg2="  ahi ";
      msg3="  sdp ";
      msg4="    i ";
      }
    else if (viewDbg==1)
      {
      str1=NumToStr(score);
      str2=NumToStr(gametype);
      str3=NumToStr(gamespeed);
      str4=NumToStr(delaytime);
      str5=NumToStr(lockDelay);
      msg1="  sc ";
      msg2="  gt ";
      msg3="  gs ";
      msg4="  dt ";
      msg4="  lD ";
      }
    else if (viewDbg==2)
      {
      str1=NumToStr(prevWaited);
      str2=NumToStr(prevLft);
      str3=NumToStr(prevRht);
      str4=NumToStr(prevDrp);
      str5=NumToStr(prevRot);
      msg1="  pW ";
      msg2="  pL ";
      msg3="  pR ";
      msg4="  pD ";
      msg5="  pR ";
      }
    else if (viewDbg==3)
      {
      str1=NumToStr(currentPiece);
      str2=NumToStr(currentRotate);
      str3=NumToStr(tetLR);
      str4=NumToStr(tetUD);
      msg1="  cP ";
      msg2="  cR ";
      msg3="  tL ";
      msg4="  tU ";
      }
    else if (viewDbg==4)
      {
      str1=NumToStr(drop);
      str2=NumToStr(alive);
      str3=NumToStr(prevQuadClear);
      str4=NumToStr(highMade);
      msg1="  dp ";
      msg2="  lv ";
      msg3="  pQ ";
      msg4="  hM ";
      }
    result=StrCat(msg1,str1,msg2,str2,msg3,str3,msg4,str4,msg5,str5);
    SendResponseString(9,result);
    Wait(60);
    }
  }


void debug(int INmode)
  {
  prevQuadClear=false;
  prevLft=0;
  prevRht=0;
  selectGame(1);
  initArrays();
  score=Random(LONG_MAX-10000)+10000;
  ClearScreen();

  if (INmode==2) //ClearFullRows()
    {
    for (int i=0; i<height; i++)
      {
      for (int j=0; j<width; j++)
        {
        area[j][i]=(Random(8)!=0);
        }
      }
    //PlayTone(1000,800);Wait(1000);
    inputOutput(false,false,true,0);
    Wait(3000);
    int i=clearFullRows();
    ClearScreen();
    Wait(250);
    inputOutput(false,false,true,0);
    NumOut(0,48,i,0);
    while(1){}
    }

  else if (INmode==3) //displayTetromino()
    {
    int tets,angl,k;
    for (tets=0; tets<7; tets++)
      {
      for (angl=0; angl<4; angl++)
        {
        ClearScreen();
        displayTetromino(tets*4,angl,0,0,0);
        Wait(500);
        until (!ButtonPressed(3)){}
        }
      }
    }

  else if (INmode==4) //peiceSetinto()
    {
    pieceCreate();
    tetUD=10;
    pieceSetInto();
    inputOutput(false,false,true,0);
    Wait(3000);
    debugStream(0);
    ClearScreen();
    displayTetromino(currentPiece,currentRotate,tetLR*blksz,tetUD*blksz,1);
    Wait(500);
    inputOutput(false,false,true,0);
    Wait(3000);
    }
  else if (INmode==5) //peiceCreate()
    {
    while (1)
      {
      pieceCreate();
      ClearScreen();
      NumOut(0,48,currentPiece,4096);
      NumOut(0,40,nextPiece[0],4096);
      NumOut(0,32,nextPiece[1],4096);
      NumOut(0,24,nextPiece[2],4096);
      Wait(400);
      }
    }
  else if (INmode==6) //gravity
    {
    pieceCreate();
    while(1)
      {
      ClearScreen();
      inputOutput(false,false,true,0);
      Wait(1000);
      tetUD--;
      }
    }
  }
