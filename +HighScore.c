//High Score Template
//Programmed By Joseph Dykstra
int hsfsize;
int hshandle;
int hscount=10;


/////////////////////////////   READ   //////////////////////////////
int readHigh(string readme)
  {
  string ARead = "";
  int result = OpenFileRead(readme, hsfsize, hshandle);
  if (result == LDR_SUCCESS)
    {
    ReadLnString(hshandle, ARead);
    CloseFile(hshandle);
    result=StrToNum(ARead);
    }
  return result;
  }
  
string readHighName(string readme)
  {
  string ARead="";
  int result = OpenFileRead(readme,hsfsize,hshandle);
  if (result == LDR_SUCCESS)
    {
    ReadLnString(hshandle,ARead);
    ReadLnString(hshandle,ARead);
    CloseFile(hshandle);
    //SendResponseString(MAILBOX10,ARead);
    }
  /*
  else
    {
    string temp=NumToStr(result);
    temp=StrCat(temp," fail_readhighname");
    SendResponseString(MAILBOX10,temp);
    }
  */
  return ARead;
  }


/////////////////////////////  WRITE  ///////////////////////////////
void writeHigh(string readme, int NewHighscore)
  {
  DeleteFile(readme);
  CreateFile(readme, 64, hshandle); //changed to constant 64 instead of constant 1024
  string tempStr=NumToStr(NewHighscore);
  WriteLnString(hshandle,tempStr,hscount);
  CloseFile(hshandle);
  }

void writeHighName(string readme, int NewHighscore)
  {
  DeleteFile(readme);
  CreateFile(readme, 64, hshandle); //changed to constant 64 instead of constant 1024
  string tempStr=NumToStr(NewHighscore);
  //TextOut(16,16,tempStr,0);
  //Wait(500);
  WriteLnString(hshandle,tempStr,hscount);
  if (1)
    {tempStr=keyboard();}
  else   //Debugging
    {
    switch (Random(11))
      {
      case 0:  tempStr="Jes"; break;
      case 1:  tempStr="Set"; break;
      case 2:  tempStr="Dav"; break;
      case 3:  tempStr="Mik"; break;
      case 4:  tempStr="Reb"; break;
      case 5:  tempStr="Jos"; break;
      case 6:  tempStr="Lev"; break;
      case 7:  tempStr="Dan"; break;
      case 8:  tempStr="Nat"; break;
      case 9:  tempStr="Mom"; break;
      default: tempStr="Dad"; break;
      }
    }
  WriteLnString(hshandle,tempStr,hscount);
  CloseFile(hshandle);
  }


/////////////////////////////  OTHER  ///////////////////////////////
/*
void endGame(string readme, int myscore)
  {
  ClearScreen();
  string show;
  show=StrCat("S:  ",NumToStr(myscore));
  TextOut(0,0,show,0);
  
  TextOut(25,LCD_LINE4,"GAME OVER",0);
  if (myscore>readHigh(readme))
    {
    TextOut(0,56,"U Made Highscore",0);
    
    Wait(1500);
    writeHighName(readme,myscore);
    ClearScreen();
    }
  else
    {
    TextOut(0,56,"Yo Not Make High",0);
    Wait(1500);
    }
    
  show=StrCat("S:  ",NumToStr(myscore));
  TextOut(0,0,show,0);
  show=StrCat("HS: ",NumToStr(readHigh(readme)));
  TextOut(0,8,show,0);
  show=StrCat("HN: ",readHighName(readme));
  TextOut(0,16,show,0);
  
  while(1){}
  }

task main()
  {
  int score=Random(100);
  endGame("High.dat",score);
  }
//*/
