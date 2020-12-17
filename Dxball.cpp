/*------------------------------------------------------------------------------ D X    B A L L ----------------------------------------------------------------------------- */

/*-------------------------------------------------------------------- M A H I R 	L A B I B 	 D I H A N ------------------------------------------------------------------ */

# include "iGraphics.h"


/*----------------------------------------------------------------------------- C O N S T A N T -------------------------------------------------------------------------------*/

	#define ScreenHeight 1080
	#define ScreenWidth 1920
	#define TotalC 20
	#define TotalR 20
	#define BlockHeight 30
	#define BlockWidth 70
	#define Ball_Board 5
	#define WallY 350
	#define Death_Mode 1
	#define Gun_Mode 2
	#define Life_Mode 3
	#define Extend_Mode 4
	#define Shrink_Mode 5
	#define Fast_Mode 6
	#define Slow_Mode 7
	#define LevelUp_Mode 8
	#define Fall_Mode 9
	#define Grab_Mode 10
	#define Fire_Mode 11
	#define Big_Mode 12
	#define Small_Mode 13
	#define SuperShrink_Mode 14

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/






/*----------------------------------------------------------------------------- F U N C T I O N S -----------------------------------------------------------------------------*/

	void Initialize(int, int, char*);
	void iReset();
	void iSaveState();
	void iCollision();
	void iSet();
	void iDrawHighScore();
	void iDrawHelp();
	void iDrawMenu();
	void iDrawBlock(int, int, double , double, double);
	void iDrawBoard(int, int);
	void iDrawTable();
	void iDrawCustom();
	void iDrawHighScore();
	void iDrawScore(int, int);
	void iDrawSmallScore(int, int);
	void iDrawNew();
	void iDrawQuit();
	void iDrawGameOver();
	void iDrawNameEntry();
	void iDraw();
	void iMouseMove(int, int);
	void iMouse(int, int, int, int);
	void iKeyboard(unsigned char);
	void iSpecialKeyboard(unsigned char );
	void mouseOverHandleFF(int, int);
	void iMouseOver(int, int);
	void iDirection();
	void iBallMove();
	void VerticalSegment(int , int, int, int, int);
	void HorizontalSegment(int, int, int , int, int);
	void iDrawDigit(int, int, int, int);
	void iDrawBack();
	void iBomb(int, int);
	void iDrawBall(int, int);
	void iMenuSelection(int, int);
	void iBomb(int, int);
	void iDeath();
	void iDrawWin();
	void iRemoveBlock(int, int);
	int iCompare(const void*, const void*);
	int iRightSideCollision(int, int);
	int iLeftSideCollision(int, int);
	int iTopSideCollision(int, int);
	int iBottomSideCollision(int, int);
	int iTopRightCornerCollision(int, int);
	int iBottomRightCornerCollision(int, int);
	int iTopLeftCornerCollision(int, int);
	int iBottomLeftCornerCollision(int, int);
	int iNewMenuSelection(int,int);
	int iCustomMenuSelection(int,int);
	int iResumeMenuSelection(int,int);
	int iHighScoreMenuSelection(int,int);
	int iHelpMenuSelection(int,int);
	int iQuitMenuSelection(int,int);

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/






/*----------------------------------------------------------------------------- S T R U C T U R E -----------------------------------------------------------------------------*/

	
	struct
	{
		int X, Y;
		int Strength, Type;
	} Block[TotalR][TotalC];
	
	struct
	{
		int X=ScreenWidth/2, Y = 10,LastX,Height = 20,WIDTH=150,Width = WIDTH;
		int SpeedX = 25, Gun = 0, Grab = 0;
	} Board;
	struct
	{
		int RADIUS=10,Radius=RADIUS, dirX, dirY, SpeedX = 2,SpeedY = 5,Fire=0;
		double X = Board.X + Board.Width / 2, Y = Board.Y + Board.Height + Radius + Ball_Board;
	} Ball;
	struct
	{
		int Launch , Life , Score;
		int Remaining, Pause , Level , Time = 0;
	} GameState;
	
	struct
	{
		int X = 261, Y = WallY;
		int Height = TotalR * BlockHeight, Width = TotalC * BlockWidth;
	} Wall;
	

	struct
	{
		int New, Custom, Resume, HighScore, Help, Quit = 0, Mode = 0;
		int Y = 50, X = 460, Height = 999, Width = 1000;
		int Active = -1;
		char Image[30] = "Data\\Image\\DxBall.bmp";
		char Button[7][40] =
		{
			"",
			"Data\\Image\\NewButton.bmp",
			"Data\\Image\\CustomButton.bmp",
			"Data\\Image\\ResumeButton.bmp",
			"Data\\Image\\HighScoreButton.bmp",
			"Data\\Image\\HelpButton.bmp",
			"Data\\Image\\QuitButton.bmp"
		};
	} Menu;
	
	
	struct
	{
		int Point = 7, Mode = 1;
		int ButtonX1[7] = {290, 305, 320, 330, 450, 400, 350};
		int ButtonY1[7] = {455, 420, 390, 370, 435, 400, 525};
		int ButtonX2[7] = {580, 450, 400, 370, 490, 425, 525};
		int ButtonY2[7] = {525, 455, 420, 390, 455, 420, 540};
	} New;
	struct
	{
		int Point = 10, Play = 0, Mode = 2, Win = 0, GameOver = 0, WinX = 600, WinY = 100;
		char ImageWin[30] = "Data\\Image\\Win.bmp";
		char ImageGameOver[30];
		int ButtonX1[10] = {300, 305, 325, 335, 355, 365, 445, 490, 490, 555};
		int ButtonY1[10] = {530, 585, 545, 625, 625, 660, 625, 535, 585, 530};
		int ButtonX2[10] = {325, 325, 490, 355, 445, 415, 465, 585, 525, 600};
		int ButtonY2[10] = {590, 610, 625, 645, 660, 675, 645, 585, 610, 585};
	} Custom;
	struct
	{
		int Point = 7, Mode = 3;
		int ButtonX1[7] = {360, 382, 405, 480, 435, 525, 490};
		int ButtonY1[7] = {335, 320, 305, 335, 355, 375, 400};
		int ButtonX2[7] = {385, 480, 460, 505, 525, 550, 565};
		int ButtonY2[7] = {355, 382, 310, 355, 412, 400, 440};
	} Resume;
	struct
	{
		int Point = 8, Mode = 4;
		int ButtonX1[8] = {440, 470, 490, 510, 530, 565, 600, 410};
		int ButtonY1[8] = {665, 640, 625, 615, 605, 585, 650, 675};
		int ButtonX2[8] = {560, 525, 510, 605, 655, 620, 635, 440};
		int ButtonY2[8] = {705, 665, 640, 685, 645, 605, 670, 700};
	} HighScore;
	
	struct
	{
		int Point = 3, Mode = 5;
		int ButtonX1[3] = {610, 655, 660};
		int ButtonY1[3] = {520, 585, 500};
		int ButtonX2[3] = {695, 690, 715};
		int ButtonY2[3] = {585, 605, 525};
	} Help;
	struct
	{
		int Point = 9, Mode = 6;
		int ButtonX1[9] = {460, 490, 510, 535, 525, 575, 585, 600, 600};
		int ButtonY1[9] = {290, 295, 300, 320, 335, 365, 385, 420, 490};
		int ButtonX2[9] = {505, 550, 575, 615, 640, 665, 685, 700, 655};
		int ButtonY2[9] = {315, 325, 345, 365, 385, 415, 445, 490, 505};
	} Quit;
	struct
	{
		int Mode = 7;
	} Game;
	struct
	{
		int X = 460, Y = 0, Mode = 8,MAX=10;
		char Image[30] = "Data\\Image\\LevelUp.bmp";
		char Level[50][30] =
		{
			"",
			"Data\\Levels\\level1.txt",
			"Data\\Levels\\level2.txt",
			"Data\\Levels\\level3.txt",
			"Data\\Levels\\level4.txt",
			"Data\\Levels\\level5.txt",
			"Data\\Levels\\level6.txt",
			"Data\\Levels\\level7.txt",
			"Data\\Levels\\level8.txt",
			"Data\\Levels\\level9.txt",
			"Data\\Levels\\level10.txt"
		};
	} LevelUp;
	struct
	{
		int Mode=9;
	} GameOver;
	struct
	{
		int X=460,Y=0,Mode=10,Active=0;
		char ImageActive[40]="Data\\Image\\NameEntryActive1.bmp";
		char ImageDeactive[40]="Data\\Image\\NameEntryDeactive1.bmp";
		char Name[50] = "";
	} NameEntry;
	struct 
	{
		int Mode=11;
	}Win;
	
	
	
	typedef struct
	{
		char Name[40];
		int Score,Time;
	} ScoreSheet;
	struct
	{
		int X = ScreenWidth/2, Y = ScreenHeight/2, LastX, LastY, Click;
		char Image[30] = "Data\\Image\\Mouse1.bmp";
	} Mouse;
	struct
	{
		char BallXBlock[30];
		char BallXBoard[30];
		char GameOver[30];
		char MouseOver[30];
		char MouseClick[30];
	} Sound;
	struct
	{
		int Width=1;
		int Height=5;
		int Triangle_Height=1;
	} Font;
	struct
	{

		int Speed=16;
		int Table[ScreenHeight + 1][ScreenWidth + 1];
	}Bullet;
	struct
	{
		char Image[14][40]=
		{
			"Data\\Image\\DropItems\\Death.bmp",
			"Data\\Image\\DropItems\\Gun.bmp",
			"Data\\Image\\DropItems\\Life+1.bmp",
			"Data\\Image\\DropItems\\Extend.bmp",
			"Data\\Image\\DropItems\\Shrink.bmp",
			"Data\\Image\\DropItems\\Fast.bmp",
			"Data\\Image\\DropItems\\Slow.bmp",
			"Data\\Image\\DropItems\\Level+1.bmp",
			"Data\\Image\\DropItems\\Fall.bmp",
			"Data\\Image\\DropItems\\Grab.bmp",
			"Data\\Image\\DropItems\\Fire.bmp",
			"Data\\Image\\DropItems\\Big.bmp",
			"Data\\Image\\DropItems\\Small.bmp",
			"Data\\Image\\DropItems\\SuperShrink.bmp"
		};
		int Table[ScreenHeight + 1][ScreenWidth + 1];
	}DropItems;
	struct
	{
		int X = 30, Y = 20, Height = 100, Width = 148, Active = 0;
		char Image[30] = "Data\\Image\\BackButton.bmp", ImageDark[30] = "Data\\Image\\BackButtonDark.bmp";
	} Back;

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/






/*--------------------------------------------------------------------------------- L O G I C ---------------------------------------------------------------------------------*/

	int Collide = 0;
	int MODE;
	int level = 10;
	int main()
	{
		MODE = Menu.Mode;
		iReset();
		iSetTimer(0, iBallMove);
		Initialize(ScreenWidth, ScreenHeight, "DXball");
		return 0;
	}
	void Initialize(int width, int height, char* title)
	{
		iScreenHeight = height;
		iScreenWidth = width;
		glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_ALPHA) ;
		glutInitWindowSize(width , height ) ;
		glutInitWindowPosition(0, 10) ;
		glutCreateWindow(title) ;
		glClearColor( 0.0 , 0.0 , 0.0 , 0.0 ) ;
		glMatrixMode( GL_PROJECTION) ;
		glLoadIdentity() ;
		glOrtho(0.0 , width , 0.0 , height , -1.0 , 1.0) ;
		glutFullScreen();
		iClear();
		glutDisplayFunc(displayFF) ;
		glutKeyboardFunc(keyboardHandler1FF); //normal
		glutSpecialFunc(keyboardHandler2FF); //special keys
		glutMouseFunc(mouseHandlerFF);
		glutMotionFunc(mouseMoveHandlerFF);
		glutPassiveMotionFunc(mouseOverHandleFF);
		glutIdleFunc(animFF) ;
		glAlphaFunc(GL_GREATER, 0.0f);
		glEnable(GL_ALPHA_TEST);
		glutSetCursor(GLUT_CURSOR_NONE);
		glutMainLoop();
	}
	void iResetPerks()
	{
		int i, j;
		for (i = 0; i <= ScreenHeight; i++)
		{
			for (j = 0; j <= ScreenWidth; j++)
			{
				DropItems.Table[i][j] = 0;
			}
		}
	}
	void iResetBullet()
	{
		int i, j;
		for (i = 0; i <= ScreenHeight; i++)
		{
			for (j = 0; j <= ScreenWidth; j++)
			{
				Bullet.Table[i][j] = 0;
			}
		}
	}
	void iReset()
	{
		GameState.Score = 0;
		GameState.Launch = 0;
		GameState.Life = 3;
		GameState.Remaining = 0;
		GameState.Level = 0;
		GameState.Pause = 0;
		Ball.Fire=0;
		iResetBullet();
		iResetPerks();
		Ball.X = Board.X + Board.Width / 2, Ball.Y = Board.Y + Board.Height + Ball.Radius + Ball_Board, Ball.dirX = 0, Ball.dirY = 0;
		int i, j;
		for (i = TotalC - 1; i > -1; i--)
		{
			for (j = 0; j < TotalR; j++)
			{
				Block[i][j].X = j * BlockWidth;
				Block[i][j].Y = i * BlockHeight;
				Block[i][j].Strength = 0;
			}
		}
		FILE *fp;
		fp = fopen("Data\\BlockType.txt", "r");
		for (i = TotalC - 1; i > -1; i--)
		{
			for (j = 0; j < TotalR; j++)
			{
				fscanf(fp, "%d", &Block[i][j].Type);
			}
		}
		fclose(fp);
	}
	void iSet()
	{
		FILE *fp;
		fp = fopen(LevelUp.Level[GameState.Level], "r");
		int i, j;
		for (i = TotalC - 1; i > -1; i--)
		{
			for (j = 0; j < TotalR; j++)
			{
				fscanf(fp, "%d", &Block[i][j].Strength);
				if (Block[i][j].Strength > 0) GameState.Remaining++;
			}
		}
		fclose(fp);
		
		Board.X=Board.LastX=Mouse.X-Board.Width/2;
		Ball.X = Board.X + Board.Width / 2;
		Ball.Y = Board.Y + Board.Height + Ball.Radius + Ball_Board;
		Ball.dirX = 0;
		Ball.dirY = 0;
		GameState.Launch = 0;
	}
	void iLoadState()
	{
		int i, j;
		FILE *load = fopen("Data\\LastState.txt", "r");
		for (i = TotalC - 1; i > -1; i--)
		{
			for (j = 0; j < TotalR; j++)
			{
				int Num;
				fscanf(load, "%d", &Num );
				Block[i][j].Strength = Num;
			}
		}

		for(i=0;i<=ScreenHeight;i++)
		{
			for(j=0;j<=ScreenWidth;j++)
			{
				fscanf(load,"%d %d",&Bullet.Table[i][j],&DropItems.Table[i][j]);
			}
		}
		fscanf(load, "%d %lf %lf %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n", &Board.X, &Ball.X, &Ball.Y, &Ball.dirX, &Ball.dirY,&Ball.Radius,&Ball.Fire, &GameState.Life, &GameState.Launch, &GameState.Score, &GameState.Remaining, &Board.Width, &GameState.Level, &Board.LastX, &Board.Gun,&Board.Grab,&Wall.Y, &GameState.Pause,&GameState.Time);
		fclose(load);
	}
	void iSaveState()
	{
		int i, j;
		FILE *save = fopen("Data\\LastState.txt", "w");
		for (i = TotalC - 1; i > -1; i--)
		{
			for (j = 0; j < TotalR; j++)
			{
				fprintf(save, "%d ", Block[i][j].Strength );
			}
			fprintf(save, "\n") ;
		}
		for(i=0;i<=ScreenHeight;i++)
		{
			for(j=0;j<=ScreenWidth;j++)
			{
				fprintf(save,"%d %d ",Bullet.Table[i][j],DropItems.Table[i][j]);
			}
			fprintf(save, "\n") ;
		}
		fprintf(save, "%d %lf %lf %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n", Board.X, Ball.X, Ball.Y, Ball.dirX, Ball.dirY, Ball.Radius, Ball.Fire,GameState.Life, GameState.Launch, GameState.Score, GameState.Remaining, Board.Width, GameState.Level, Board.LastX, Board.Gun, Board.Grab,Wall.Y, GameState.Pause,GameState.Time);
		fclose(save);
	}

	void iDeath()
	{
		Ball.X = Board.X + Board.Width / 2, Ball.Y = Board.Y + Board.Height + Ball.Radius + Ball_Board, Ball.dirX = 0, Ball.dirY = 0;
		PlaySound("Data\\Music\\Gameover.wav", NULL, SND_ASYNC);
		GameState.Life--;
		if (GameState.Life == 0)
		{
			MODE = GameOver.Mode;
			Sleep(500);
		}
		GameState.Launch = 0;
	}
	void iLevelUp()
	{
		if(GameState.Level<LevelUp.MAX)
		{
			GameState.Launch = 0;
			GameState.Score += 10 * GameState.Remaining;
			GameState.Remaining = 0;
			GameState.Pause = 0;
			Board.Gun = 0;
			Board.Grab = 0;
			Ball.Fire=0;
			Ball.Radius=Ball.RADIUS;
			iResetBullet();
			iResetPerks();
			Board.Width = Board.WIDTH;
			Wall.Y = WallY;
			Ball.SpeedY = 5;
			Board.X=Board.LastX=Mouse.X-Board.Width/2;
			Ball.X = Board.Y + Board.Width / 2, Ball.Y = Board.Y + Board.Height + Ball.Radius + Ball_Board, Ball.dirX = 0, Ball.dirY = 0;
			GameState.Level++;
			iSet();
			MODE = Game.Mode;
		}

		else
		{
			GameState.Level++;
			MODE=Win.Mode;
		}
	}
	void iCatch()
	{
		int i, j;
		for (i = 0; i <= Board.Y + Board.Height; i++)
		{
			for (j = Board.X - 50; j < Board.X + Board.Width; j++)
			{
				if(j<0) continue;
				if (DropItems.Table[i][j])
				{
					if (i == 0) 
						{
							DropItems.Table[i][j] = 0;
							return ;
						}

					switch (DropItems.Table[i][j])
					{
						case Death_Mode:
							iDeath();
							DropItems.Table[i][j] = 0;
							break;
						case Gun_Mode:
							Board.Gun = 1;
							DropItems.Table[i][j] = 0;
							break;
						case Life_Mode:
							GameState.Life++;
							DropItems.Table[i][j] = 0;
							break;
						case Extend_Mode:
							if (Board.WIDTH + 30 <= ScreenWidth - 2 * Wall.X)
							{
								Board.Width += 30;
								if (Board.X - 15 > Wall.X)
									Board.X -= 15;
							}
							DropItems.Table[i][j] = 0;
							break;
						case Shrink_Mode:
							if (Board.Width - 30 >= 30)
							{
								Board.Width -= 30;
								Board.X += 15;
							}
							DropItems.Table[i][j] = 0;
							break;
						case Fast_Mode:
							if (abs(Ball.dirY) < 13)
								Ball.dirY *= 1.2;
							Ball.dirX *= 1.2;
							DropItems.Table[i][j] = 0;
							break;
						case Slow_Mode:
							Ball.dirY *= 0.8;
							Ball.dirX *= 0.8;
							DropItems.Table[i][j] = 0;
							break;
						case LevelUp_Mode:
							if (GameState.Level<LevelUp.MAX&&GameState.Level>0) MODE = LevelUp.Mode;
							else if(GameState.Level==LevelUp.MAX) iLevelUp();
							else Custom.Win = 1;

							DropItems.Table[i][j] = 0;
							break;
						case Fall_Mode:
							Wall.Y -= BlockHeight;
							DropItems.Table[i][j] = 0;
							break;
						case Grab_Mode:
							Board.Grab = 1;
							DropItems.Table[i][j] = 0;
							break;
						case Fire_Mode:
							Ball.Fire = 1;
							DropItems.Table[i][j] = 0;
							break;
						case Big_Mode:
							Ball.Radius = Ball.RADIUS * 1.5;
							DropItems.Table[i][j] = 0;
							break;
						case Small_Mode:
							Ball.Radius = Ball.RADIUS * 0.5;
							DropItems.Table[i][j] = 0;
							break;
						case SuperShrink_Mode:
							Board.Width = 30;
							DropItems.Table[i][j] = 0;
							break;
					}
				}
			}
		}
	}
	void iBallMove()
	{
		if (GameState.Pause) return;
		else if (MODE == Game.Mode)
		{
			iCollision();
			iCatch();
			if(GameState.Launch)
			{
				Ball.X += Ball.dirX;
				Ball.Y += Ball.dirY;
			}
			else 
			{
				Ball.X=Board.X+Ball.X-Board.LastX;			
				Board.LastX=Board.X;
				if(Ball.X<Board.X) Ball.X=Board.X;
				else if(Ball.X>Board.X+Board.Width) Ball.X=Board.X+Board.Width;
			}
							
			if (Ball.dirY < 0 & Ball.Y >= Board.Y + Board.Height / 2 - Ball.Radius & Ball.Y <= Board.Y + Board.Height + Ball.Radius + Ball_Board )
			{
				iDirection();
			}
			else if (Ball.Y > ScreenHeight - Ball.Radius) {Ball.dirY *= -1; Ball.Y = ScreenHeight - Ball.Radius;}
			else if (Ball.X < Wall.X + Ball.Radius) {Ball.dirX *= -1; Ball.X = Wall.X + Ball.Radius;}
			else if (Ball.X > Wall.X + TotalC * BlockWidth - Ball.Radius) {Ball.dirX *= -1; Ball.X = Wall.X + TotalC * BlockWidth - Ball.Radius;}
			else if (Ball.dirY < 0 & Ball.Y < Board.Y + Board.Height / 2 - Ball.Radius)
			{
				iDeath();
			}

			if (Custom.Win == 1)
			{
				Sleep(2000);
				MODE = Menu.Mode;
				Custom.Win = 0;
			}
			else if (GameState.Remaining == 0)
			{
				if (GameState.Level<LevelUp.MAX&&GameState.Level>0) MODE = LevelUp.Mode;
				else if(GameState.Level==LevelUp.MAX) iLevelUp();
				else Custom.Win = 1;
			}
		}
		else if (MODE == LevelUp.Mode)
		{
			Sleep(500);
			iLevelUp();
		}
	}
	void iDirection()
	{
		if (Ball.X >= Board.X && Ball.X <= Board.X + Board.Width)
		{
			PlaySoundA("Data\\Music\\BallBoardCollision.wav", NULL, SND_ASYNC);
			if(Ball.X!=Board.X + Board.Width / 2) Ball.dirX = ceil((Ball.X - Board.X - Board.Width / 2) * Ball.SpeedX * 9 / Board.Width);
			if(!Ball.dirX) Ball.dirX=rand()%9;
			Ball.dirY =abs(Ball.dirY);
			if(!Ball.dirY) Ball.dirY = 2*Ball.SpeedY;			
			if(GameState.Launch&&Board.Grab)
			{ 
				GameState.Launch=0;
				Ball.Y = Board.Y + Board.Height + Ball.Radius + Ball_Board;
			}
			else 
			{
				GameState.Launch=1;
			}
		}
	}
	int Compare(const void* a, const void* b)
	{
		int A = ((ScoreSheet*)a)->Score;
		int B = ((ScoreSheet*)b)->Score;
		if(B!=A) return B - A;
		A = ((ScoreSheet*)a)->Time;
		B = ((ScoreSheet*)b)->Time;
		return A - B ;
	}

/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/






/*------------------------------------------------------------------------------ D R A W I N G S -------------------------------------------------------------------------------*/

	void iDrawBall(int x, int y)
	{
		if(Ball.Fire) iSetColor(255,120,13);
		else iSetColor(100, 100, 100);
		iFilledCircle(x, y, Ball.Radius);
		if(Ball.Fire) iSetColor(255, 150,13);
		else iSetColor(150, 150, 150);
		iFilledCircle(x - 0.1*Ball.Radius, y + 0.2*Ball.Radius,0.8*Ball.Radius);
		if(Ball.Fire) iSetColor(255,170,13);
		else iSetColor(200, 200, 200);
		iFilledCircle(x - 0.3*Ball.Radius, y + 0.5*Ball.Radius,0.4*Ball.Radius);
	}
	void iDrawBack()
	{
		if (Back.Active) iShowBMP(Back.X, Back.Y, Back.Image);
		else iShowBMP(Back.X, Back.Y, Back.ImageDark);
	}
	void iDrawHighScore()
	{
		FILE *hs;
		char name[40], S[10],T[10];
		int i;
		hs = fopen("Data\\HighScore.txt", "r");
		iShowBMP2(460, 400, "Data\\Image\\HighScoreWall.bmp", 0X00060412);
		iSetColor(166, 41, 166);
		iText(600, 550, "POS", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(670, 550, "NAME", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(1100, 550 , "TIME (sec)", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(1260, 550 , "SCORE", GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(255, 255, 255);
		for (i = 0; EOF != fscanf(hs, "%[^\n] %s %s\n", name,S,T) ; i++)
		{
			{
				char Temp[3];
				iText(600, 500 - 40 * i, itoa(i + 1, Temp, 10), GLUT_BITMAP_TIMES_ROMAN_24);
				iText(670, 500 - 40 * i, name, GLUT_BITMAP_TIMES_ROMAN_24);
				iText(1100, 500 - 40 * i, T, GLUT_BITMAP_TIMES_ROMAN_24);
				iText(1260, 500 - 40 * i, S, GLUT_BITMAP_TIMES_ROMAN_24);
			}
		}
		fclose(hs);
		iDrawBack();
	}
	void iDrawHelp()
	{
		iShowBMP(0, 0, "Data\\Image\\Help.bmp");
		iDrawBack();
	}
	void iDrawMenu()
	{
		iShowBMP(Menu.X, Menu.Y, Menu.Image);
		if (Menu.Active > 0)iShowBMP2(Menu.X, Menu.Y, Menu.Button[Menu.Active], 0X00ffffff);
	}
	void iDrawBlock(int x, int y, double R, double G, double B)
	{
		iSetColor(R + 7, G + 7, B + 7);
		double a[] = {x, x, x + BlockWidth};
		double b[] = {y, y + BlockHeight, y + BlockHeight};
		double c[] = {x, x + BlockWidth, x + BlockWidth};
		double d[] = {y, y, y + BlockHeight};
		iFilledPolygon(a, b, 3);
		iSetColor(R - 8, G - 8, B - 8);
		iFilledPolygon(c, d, 3);
		iSetColor(R, G, B);
		iFilledRectangle(x + 12, y + 8, BlockWidth - 24, BlockHeight - 16);
		iSetColor(5, 5, 5);
		iRectangle(x, y, BlockWidth, BlockHeight);
	}
	void iDrawBomb(int x, int y)
	{
		iSetColor(255, 127, 0);
		iFilledRectangle(x, y, BlockWidth, BlockHeight);
		iSetColor(247, 147, 47);
		iFilledRectangle(x + 3, y + 3, BlockWidth - 6, BlockHeight - 6);
		iSetColor(243, 171, 95);
		iFilledRectangle(x + 6, y + 6, BlockWidth - 12, BlockHeight - 12);
		iSetColor(239, 191, 143);
		iFilledRectangle(x + 9, y + 9, BlockWidth - 18, BlockHeight - 18);
		iSetColor(235, 211, 187);
		iFilledRectangle(x + 12, y + 12, BlockWidth - 24, BlockHeight - 24);
		iSetColor(231, 231, 231);
		iFilledRectangle(x + 15, y + 15, BlockWidth - 30, BlockHeight - 30);
	}

	void iDrawBullet(int x, int y)
	{
		iSetColor(188, 3, 57);
		double X[] = {x - 4, x, x + 4, x + 4, x, x - 4};
		double Y[] = {y + 4, y, y + 4, y + 10 + 4, y + 10 + 4 + 4, y + 10 + 4};
		iFilledPolygon(X,Y,sizeof(X)/sizeof(X[0]));
	}
	void iDrawBoard(int x, int y)
	{
		iSetColor(100, 100, 100);
		iFilledRectangle(x + 4, y, Board.Width - 8, Board.Height / 2);
		iSetColor(120, 120, 120);
		iFilledRectangle(x + 4, y + Board.Height / 2, Board.Width - 8, Board.Height / 2);
		double c[] = {x, x + 4, x + 10, x + 10, x + 4, x};
		double d[] = {y + 3, y, y, y + Board.Height, y + Board.Height, y + Board.Height - 3};
		double e[] = {x + Board.Width - 10, x + Board.Width - 4, x + Board.Width, x + Board.Width, x + Board.Width - 4, x + Board.Width - 10};
		double f[] = {y, y, y + 3, y + Board.Height - 3, y + Board.Height, y + Board.Height};
		iSetColor(188, 3, 57);
		iFilledPolygon(c, d, 6);
		iFilledPolygon(e, f, 6);
		if (Board.Gun)
		{
			iDrawBullet(x + 4, y + Board.Height);
			iDrawBullet(x + Board.Width - 4, y + Board.Height);
		}

		iSetColor(5, 5, 5);
		iLine(x + 10, y + 1 * Board.Height / 4, x + Board.Width - 10, y +  1 * Board.Height / 4);
		iLine(x + 10, y +  2 * Board.Height / 4, x + Board.Width - 10, y + 2 * Board.Height / 4);
		iLine(x + 10, y +  3 * Board.Height / 4, x + Board.Width - 10, y +  3 * Board.Height / 4);
	}
	void iDrawTable()
	{
		for (int i = 0; i < TotalC; i++)
		{
			for (int j = 0; j < TotalR; j++)
			{
				if (Block[i][j].Strength == 1)
					iDrawBlock(Wall.X + Block[i][j].X, Wall.Y + Block[i][j].Y, 18 + i * i / 1.5, 18 + i * j / 1.5, 18 + j * j / 1.5);
				else if (Block[i][j].Strength == 2)
					iDrawBomb(Wall.X + Block[i][j].X, Wall.Y + Block[i][j].Y);
			}
		}
	}
	void iDrawCustom()
	{
		iShowBMP(134, 0, "Data\\Image\\BackWall.bmp");
		if (Custom.Play == 1) iShowBMP2(134, 0, "Data\\Image\\PlayButton1.bmp", 0X00ffffff);
		for (int i = 0; i < TotalC; i++)
		{
			for (int j = 0; j < TotalR; j++)
			{
				if (Block[i][j].Strength == 1)
					iDrawBlock(Wall.X + Block[i][j].X, Wall.Y + Block[i][j].Y - 170,  18 + i * i / 1.5, 18 + i * j / 1.5, 18 + j * j / 1.5);
				else if (Block[i][j].Strength == 2)
					iDrawBomb(Wall.X + Block[i][j].X, Wall.Y + Block[i][j].Y - 170);
			}
		}

		for (int i = 0; i < TotalC; i++)
		{
			for (int j = 0; j < TotalR; j++)
			{
				iSetColor(100, 100, 100);
				iRectangle(Wall.X + Block[i][j].X, Wall.Y + Block[i][j].Y - 170, BlockWidth, BlockHeight);
			}

		}
		iDrawBack();
		iSetColor(166, 41, 166);
		iText(260,10,"Left click and Drag -                                               Left click on a normal block -                                               Right click and Drag - ",(void*)5);  
		iSetColor(146,62,241);
		iText(260,10,"                                   Draw a normal block                                                              Draw an explosive                                                      Erase block",(void*)5);
	}
	void VerticalSegment(int X, int Y, int dx, int dy, int size)
	{
		int triangleHeight = Font.Triangle_Height * size;
		double  x[6] = { X , X - dx / 2 , X - dx / 2 , X , X + dx / 2 , X + dx / 2 },
		               y[6] = { Y , Y + triangleHeight , Y + dy + triangleHeight , Y + dy + 2 * triangleHeight , Y + dy + triangleHeight , Y + triangleHeight };

		iFilledPolygon(x, y, 6);
	}
	void HorizontalSegment(int X, int Y, int dx, int dy, int size)
	{
		int triangleHeight = Font.Triangle_Height * size;
		double  x[6] = { X , X + triangleHeight , X + dx + triangleHeight , X + dx + 2 * triangleHeight , X + dx + triangleHeight , X + triangleHeight },
		               y[6] = { Y , Y + dy / 2 , Y + dy / 2 , Y , Y - dy / 2 , Y - dy / 2 };

		iFilledPolygon(x, y, 6);
	}
	void iDrawDigit(int x, int y, int digit, int size)
	{
		if (digit == 0 || digit == 2 || digit == 6 || digit == 8)
			VerticalSegment(x, y, Font.Width * size, Font.Height * size, size);
		if (digit == 0 || digit == 4 || digit == 5 || digit == 6 || digit == 8 || digit == 9)
			VerticalSegment(x, y + Font.Height * size + 2 * Font.Triangle_Height * size, Font.Width * size, Font.Height * size, size);
		if (digit == 0 || digit == 2 || digit == 3 || digit == 5 || digit == 6 || digit == 7 || digit == 8 || digit == 9)
			HorizontalSegment(x, y + 2 * Font.Height * size + 4 * Font.Triangle_Height * size, Font.Height * size, Font.Width * size, size);
		if (digit == 2 || digit == 3 || digit == 4 || digit == 5 || digit == 6 || digit == 8 || digit == 9)
			HorizontalSegment(x, y + Font.Height * size + 2 * Font.Triangle_Height * size, Font.Height * size, Font.Width * size, size);
		if (digit == 0 || digit == 2 || digit == 3 || digit == 5 || digit == 6 || digit == 8 || digit == 9)
			HorizontalSegment(x, y, Font.Height * size, Font.Width * size, size);
		if (digit == 0 || digit == 1 || digit == 3 || digit == 4 || digit == 5 || digit == 6 || digit == 7 || digit == 8 || digit == 9)
			VerticalSegment(x + Font.Height * size + 2 * Font.Triangle_Height * size, y, Font.Width * size, Font.Height * size, size);
		if (digit == 0 || digit == 1 || digit == 2 || digit == 3 || digit == 4 || digit == 7 || digit == 8 || digit == 9)
			VerticalSegment(x + Font.Height * size + 2 * Font.Triangle_Height * size, y + Font.Height * size + 2 * Font.Triangle_Height * size, Font.Width * size, Font.Height * size, size);
	}
	void iDrawScore(int S, int size)
	{
		int i;
		
		int n = floor(log10(S)) + 1;
		if (!S) iDrawDigit(850, 800, S, 10);
		for (i = 0; S; i++)
		{
			iDrawDigit(850 - (n / 2) * 100 + n * 100 - i * 100, 850, S % 10, size);
			S /= 10;
		}
	}
	void iDrawSmallScore(int S, int size)
	{
		int i;
		iSetColor(188, 3, 57);
		if (!S) iDrawDigit(220, 1000, S, size);
		for (i = 0; S; i++)
		{
			iDrawDigit(220 - i * 30, 1000, S % 10, size);
			S /= 10;
		}
	}
	void iDrawLevel()
	{
		iSetColor(188, 3, 57);
		iText(20, 120, "LEVEL - ", (void*)5);
		char temp[3];
		iText(120, 120, itoa(GameState.Level, temp, 10), (void*)5);
	}
	void iDrawRemaining()
	{
		iSetColor(188, 3, 57);
		iText(20, 20, "REMAINING - ", (void*)5);
		char temp[3];
		iText(190, 20, itoa(GameState.Remaining, temp, 10), (void*)5);
	}
	void iDrawTime()
	{
		GameState.Time++;
		iSetColor(188, 3, 57);
		char temp[50];
		iText(20, 70, itoa((GameState.Time / 60) / 3600, temp, 10), (void*)5);
		iText(50, 72, ":", (void*)5);
		iText(60, 70, itoa(((GameState.Time / 60) / 60) % 60, temp, 10), (void*)5);
		iText(90, 72, ":", (void*)5);
		iText(100, 70, itoa((GameState.Time / 60) % 60, temp, 10), (void*)5);
	}
	void iDrawWin()
	{
		iShowBMP(600, 100, "Data\\Image\\Win.bmp");
		if (NameEntry.Active)iShowBMP2(NameEntry.X,NameEntry.Y, NameEntry.ImageActive,0X00000000);
		else iShowBMP2(NameEntry.X,NameEntry.Y, NameEntry.ImageDeactive,0X00000000);
		iSetColor(100, 100, 100);
		iText(NameEntry.X+370,NameEntry.Y+165, "ENTER YOUR NAME", (void*)5);
		iSetColor(188, 3, 57);
		iDrawScore(GameState.Score, 10);
	}
	void iDrawGame()
	{
		for (int i = 0; i < 28; i++)
		{
			for (int j = 0; j < 37; j++)
			{
				iDrawBlock(i * BlockWidth - 19, j * BlockHeight - 10, 8, 8, 8);
			}
		}
		iSetColor(255, 255, 255); 
		iDrawBoard(Board.X, Board.Y);
		iSetColor(180, 180, 180);
		if (GameState.Life)iDrawBall(Ball.X, Ball.Y);
		iShowBMP(0, 0, "Data\\Image\\Wall.bmp");
		iShowBMP(Wall.X + TotalC * BlockWidth, 0, "Data\\Image\\Wall.bmp");
		iDrawSmallScore(GameState.Score, 3);
		iDrawLevel();
		iDrawRemaining();
		if (GameState.Pause)
		{
			iSetColor(255, 255, 0);
			iText(20, 70, "PAUSED", (void*)5);
		}
		else
		{
			iDrawTime();
		}
		for (int i = 0; i < GameState.Life - 1; i++)
		{
			iShowBMP2(ScreenWidth - 90 - (i % 3) * 80, ScreenHeight - 100 * ((i / 3) + 1), "Data\\Image\\Life.bmp", 0X00000000);
		}
		for (int j = 0; j < ScreenWidth; j++)
		{
			for (int i = floor((ScreenHeight - Board.Y - Board.Height) / Bullet.Speed) * Bullet.Speed; i >= Board.Y + Board.Height; i--)
			{
				if (Bullet.Table[i][j])
				{
					if (i >= Wall.Y && i <= Wall.Y + Wall.Height)
					{
						if (Block[(i - Wall.Y) / BlockHeight][(j - Wall.X) / BlockWidth].Strength)
						{
							Bullet.Table[i][j] = 0;
							iRemoveBlock((i - Wall.Y) / BlockHeight, (j - Wall.X) / BlockWidth);
							Collide = 0;
						}
						else
						{
							iDrawBullet(j, i);
							if (!GameState.Pause)
							{
								Bullet.Table[i + Bullet.Speed][j] = Bullet.Table[i][j];
								Bullet.Table[i][j] = 0;
							}
						}
					}

					else
					{
						iDrawBullet(j, i);
						if (!GameState.Pause)
						{
							Bullet.Table[i + Bullet.Speed][j] = Bullet.Table[i][j];
							Bullet.Table[i][j] = 0;
						}
					}
				}
			}
		}
		iDrawTable();

		for (int i = 0; i < ScreenHeight; i++)
		{
			for (int j = 0; j < ScreenWidth; j++)
			{
				if (DropItems.Table[i][j])
				{
					iShowBMP(j, i, DropItems.Image[DropItems.Table[i][j] - 1]);
					if (!GameState.Pause)
					{
						if(i>=5)
						DropItems.Table[i - 5][j] = DropItems.Table[i][j];
						DropItems.Table[i][j] = 0;
					}

				}
			}
		}
	}
	void iDrawQuit()
	{
		if (Menu.Quit)
		{
			Sleep(1000);
			exit(1);
		}
		iShowBMP(460, 43, "Data\\Image\\GoodBye.bmp");
		iSetColor(50,50,50);
		iText(1100,300,"- MAHIR LABIB DIHAN",(void*)5);
		Menu.Quit = 1;
	}
	void iDrawGameOver()
	{
		iShowBMP(460, 100, "Data\\Image\\GameOver.bmp");
		if (NameEntry.Active)iShowBMP2(NameEntry.X,NameEntry.Y, NameEntry.ImageActive,0X00000000);
		else iShowBMP2(NameEntry.X,NameEntry.Y, NameEntry.ImageDeactive,0X00000000);
		iSetColor(100, 100, 100);
		iText(NameEntry.X+370,NameEntry.Y+165, "ENTER YOUR NAME", (void*)5);
		iSetColor(188, 57, 133);
		iDrawScore(GameState.Score, 10);
	}
	void iDrawNameEntry()
	{
		if(GameState.Level<=LevelUp.MAX) 
			{
				iShowBMP(460, 100, "Data\\Image\\GameOver.bmp");
				iSetColor(188, 57, 133);
			}
		else 
			{
				iShowBMP(600, 100, "Data\\Image\\Win.bmp");
				iSetColor(188, 3, 57);
			}
		iDrawScore(GameState.Score, 10);
		if (NameEntry.Active)iShowBMP2(NameEntry.X,NameEntry.Y, NameEntry.ImageActive,0X00000000);
		
		
		iSetColor(200, 200, 200);
		iText(NameEntry.X+310,NameEntry.Y+165, NameEntry.Name, (void*)5);
	}
	void iDrawLevelUp()
	{

		iShowBMP(LevelUp.X, LevelUp.Y, LevelUp.Image);
	}
	void iDraw()
	{
		iClear();
		if (MODE == Menu.Mode)
		{
			iDrawMenu();
		}
		else if (MODE == NameEntry.Mode)
		{
			iDrawNameEntry();
		}
		else if (MODE == Custom.Mode)
		{
			iDrawCustom();
		}

		else if (MODE == HighScore.Mode)
		{
			iDrawHighScore();

		}
		else if (MODE == Help.Mode)
		{
			iDrawHelp();

		}
		else if (MODE == Quit.Mode)
		{
			iDrawQuit();
		}
		else if (MODE == GameOver.Mode)
		{
			iDrawGameOver();
		}
		else if(MODE == Win.Mode)
		{
			iDrawWin();
		}
		else if (MODE == Game.Mode)
		{
			if (Custom.Win)
			{
				iShowBMP(Custom.WinX, Custom.WinY, Custom.ImageWin);
			}
			else iDrawGame();
		}
		else if (MODE == LevelUp.Mode)
		{
			iDrawLevelUp();
		}

		if (MODE != Game.Mode&& MODE!=LevelUp.Mode) iShowBMP2(Mouse.X, Mouse.Y - 35, Mouse.Image, 0X00000000);
	}

/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/






/*--------------------------------------------------------------------------------- M O U S E ----------------------------------------------------------------------------------*/

	void iMouseMove(int mx, int my)
	{
		
		Mouse.X = mx, Mouse.Y = my;
		if (MODE == Custom.Mode)
		{
			for (int i = 0; i < TotalC; i++)
			{
				for (int j = 0; j < TotalR; j++)
				{

					if (mx >= Wall.X + Block[i][j].X && mx <= Wall.X + Block[i][j].X + BlockWidth)
					{
						if (my >= Wall.Y + Block[i][j].Y - 170 && my <= Wall.Y + Block[i][j].Y - 170 + BlockHeight)
						{
							if (!Block[i][j].Strength && Mouse.Click == 0)
							{
								Block[i][j].Strength = 1;

								GameState.Remaining++;
							}
							else if (Mouse.Click == 1 && Block[i][j].Strength)
							{
								Block[i][j].Strength = 0;
								GameState.Remaining--;
							}

						}
					}
				}
			}
		}
	}
	void iMouseLeftButtonDownMenu(int mx, int my)
	{
		if (Menu.Active == New.Mode)
		{
			PlaySound("Data\\Music\\Button2.wav", NULL, SND_ASYNC);
			iReset();
			GameState.Level++;
			iSet();
			GameState.Time = 0;
			MODE = Game.Mode;
			Menu.Active = -1;
		}
		else if (Menu.Active == Custom.Mode)
		{
			PlaySound("Data\\Music\\Button2.wav", NULL, SND_ASYNC);
			MODE = Custom.Mode;
			iReset();
			Menu.Active = -1;
		}
		else if (Menu.Active == Resume.Mode)
		{

			PlaySound("Data\\Music\\Button2.wav", NULL, SND_ASYNC);
			iLoadState();
			MODE = Game.Mode;
			Menu.Active = -1;
		}
		else if (Menu.Active == HighScore.Mode)
		{
			PlaySound("Data\\Music\\Button2.wav", NULL, SND_ASYNC);
			MODE = HighScore.Mode;
			Menu.Active = -1;
		}
		else if (Menu.Active == Help.Mode)
		{
			PlaySound("Data\\Music\\Button2.wav", NULL, SND_ASYNC);
			MODE = Help.Mode;
			Menu.Active = -1;
		}
		else if (Menu.Active == Quit.Mode)
		{
			PlaySound("Data\\Music\\Button2.wav", NULL, SND_ASYNC);
			MODE = Quit.Mode;
			Menu.Active = -1;
		}
	}
	void iMouseLeftButtonDownCustom(int mx, int my)
	{
		if (Custom.Play == 1)
		{
			MODE = Game.Mode;
			GameState.Time = 0;
			Custom.Play = 0;
			PlaySound("Data\\Music\\Button2.wav", NULL, SND_ASYNC);
		}
		else
		{
			for (int i = 0; i < TotalC; i++)
			{
				for (int j = 0; j < TotalR; j++)
				{
					if (mx >= Wall.X + Block[i][j].X && mx <= Wall.X + Block[i][j].X + BlockWidth)
					{
						if (my >= Wall.Y + Block[i][j].Y - 170 && my <= Wall.Y + Block[i][j].Y - 170 + BlockHeight)
						{
							if (Block[i][j].Strength == 1)
								Block[i][j].Strength = 2;
							else if (Block[i][j].Strength == 0)
							{
								GameState.Remaining++;
								Block[i][j].Strength = 1;
							}
						}
					}
				}
			}
		}
	}
	void iMouseLeftButtonDown(int mx, int my)
	{
		Mouse.Click = 0;
		if (MODE == GameOver.Mode||MODE==Win.Mode)
		{
			if (NameEntry.Active)
			{
				MODE = NameEntry.Mode;
			}
		}
		else if (MODE == Custom.Mode)
		{
			iMouseLeftButtonDownCustom(mx, my);
		}
		else if (MODE == Game.Mode)
		{
			if (!GameState.Launch)
			{
				iDirection();
			}
			else if (Board.Gun)
			{
				PlaySound("Data\\Music\\Gun.wav", NULL, SND_ASYNC);
				Bullet.Table[Board.Y + Board.Height][Board.X + 4] = 1;
				Bullet.Table[Board.Y + Board.Height][Board.X + Board.Width - 4] = 1;
			}
		}
		else if (MODE == Menu.Mode)
		{
			iMouseLeftButtonDownMenu(mx, my);
		}

		if (MODE == Custom.Mode || MODE == HighScore.Mode || MODE == Help.Mode)
		{
			if (Back.Active)
			{
				PlaySound("Data\\Music\\Button2.wav", NULL, SND_ASYNC);
				MODE = Menu.Mode;
				Back.Active = 0;
			}

		}
	}
	void iMouseRightButtonDown(int mx, int my)
	{
		if (MODE == Custom.Mode)
		{
			Mouse.Click = 1;
			for (int i = 0; i < TotalC; i++)
			{
				for (int j = 0; j < TotalR; j++)
				{
					if (mx >= Wall.X + Block[i][j].X && mx <= Wall.X + Block[i][j].X + BlockWidth)
					{
						if (my >= Wall.Y + Block[i][j].Y - 170 && my <= Wall.Y + Block[i][j].Y - 170 + BlockHeight)
						{
							Block[i][j].Strength = 0;
							GameState.Remaining--;
						}
					}
				}
			}
		}

		else if (MODE == Game.Mode)
		{
			GameState.Pause = !GameState.Pause;
		}
	}
	void iMouse(int button, int state, int mx, int my)
	{
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			iMouseLeftButtonDown(mx, my);
		}

		else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
		{
			iMouseRightButtonDown(mx, my);
		}
	}
	void mouseOverHandleFF(int mx, int my)
	{

		my = iScreenHeight - my;
		iMouseOver(mx, my);
	}
	void iMouseOver(int mx, int my)
	{
		// printf("%d %d\n",Mouse.X,Mouse.Y);
		Mouse.LastX=Mouse.X, Mouse.LastY=Mouse.Y;
		Mouse.X = mx, Mouse.Y = my;
		if (MODE == Game.Mode)
		{
			if (GameState.Pause) return;
			// printf("%d %d\n",Board.X,Board.LastX);
			Board.LastX=Board.X;
			Board.X = Mouse.X;
			if (Board.X < Wall.X) { Board.X = Wall.X; }
			if (Board.X > Wall.X + TotalC * BlockWidth - Board.Width) { Board.X = Wall.X + TotalC * BlockWidth - Board.Width;}
		}

		else if (MODE == GameOver.Mode||MODE==Win.Mode)
		{
			if (mx >= NameEntry.X+280 && mx <= NameEntry.X+710 && my >= NameEntry.Y+130&& my <= NameEntry.Y+130+90)
			{
				NameEntry.Active = 1;
			}
			else
			{
				NameEntry.Active = 0;
			}
		}

		else if (MODE == Custom.Mode)
		{
			if (mx >= 880 && mx <= 1050 && my >= 820 && my <= 1020)
			{
				if (!Custom.Play)PlaySound("Data\\Music\\Button.wav", NULL, SND_ASYNC);
				Custom.Play = 1;
			}
			else
			{
				Custom.Play = 0;
			}
			if ((mx >= 30 && mx <= 120 && my >= 20 && my <= 120) || (mx >= 120 && mx <= 178 && my >= 60 && my <= 80))
			{
				if (!Back.Active)PlaySound("Data\\Music\\Button.wav", NULL, SND_ASYNC);
				Back.Active = 1;
			}
			else
			{
				Back.Active = 0;
			}
		}

		else if (MODE == Menu.Mode)
		{
			iMenuSelection(mx, my);

		}

		else if (MODE == Help.Mode || MODE == HighScore.Mode)
		{
			if ((mx >= Back.X && mx <= Back.X + Back.Width / 2 && my >= Back.Y && my <= Back.Y + Back.Height) || (mx >= Back.X + Back.Width / 2 && mx <= Back.X + Back.Width && my >= Back.Y + Back.Height / 2 - 10 && my <= Back.Y + Back.Height / 2 + 10))
			{
				if (!Back.Active)PlaySound("Data\\Music\\Button.wav", NULL, SND_ASYNC);
				Back.Active = 1;
			}
			else
			{
				Back.Active = 0;
			}
		}
	}


	/*------------------------------------ M E N U -----------------------------------*/
	
		int iNewMenuSelection(int mx, int my)
		{
			for (int i = 0; i < New.Point; i++)
			{
				if (mx >= Menu.X + New.ButtonX1[i] && mx <= Menu.X + New.ButtonX2[i] && my >= Menu.Y + New.ButtonY1[i] && my <= Menu.Y + New.ButtonY2[i])
				{
					if (Menu.Active != New.Mode) PlaySound("Data\\Music\\Button.wav", NULL, SND_ASYNC);
					Menu.Active = New.Mode;
					return 1;
				}
			}
			return 0;
		}
		int iCustomMenuSelection(int mx, int my)
		{
			for (int i = 0; i < Custom.Point; i++)
			{
				if (mx >= Menu.X + Custom.ButtonX1[i] && mx <= Menu.X + Custom.ButtonX2[i] && my >= Menu.Y + Custom.ButtonY1[i] && my <= Menu.Y + Custom.ButtonY2[i])
				{
					if (Menu.Active != Custom.Mode) PlaySound("Data\\Music\\Button.wav", NULL, SND_ASYNC);
					Menu.Active = Custom.Mode;
					return 1;
				}
			}
			return 0;
		}
		int iResumeMenuSelection(int mx, int my)
		{
			for (int i = 0; i < Resume.Point ; i++)
			{
				if (mx >= Menu.X + Resume.ButtonX1[i] && mx <= Menu.X + Resume.ButtonX2[i] && my >= Menu.Y + Resume.ButtonY1[i] && my <= Menu.Y + Resume.ButtonY2[i])
				{
					if (Menu.Active != Resume.Mode) PlaySound("Data\\Music\\Button.wav", NULL, SND_ASYNC);
					Menu.Active = Resume.Mode;
					return 1;
				}
			}
			return 0;
		}
		int iHighScoreMenuSelection(int mx, int my)
		{
			for (int i = 0; i < HighScore.Point ; i++)
			{
				if (mx >= Menu.X + HighScore.ButtonX1[i] && mx <= Menu.X + HighScore.ButtonX2[i] && my >= Menu.Y + HighScore.ButtonY1[i] && my <= Menu.Y + HighScore.ButtonY2[i])
				{
					if (Menu.Active != HighScore.Mode) PlaySound("Data\\Music\\Button.wav", NULL, SND_ASYNC);
					Menu.Active = HighScore.Mode;
					return 1;
				}
			}
			return 0;
		}
		int iHelpMenuSelection(int mx, int my)
		{
			for (int i = 0; i < Help.Point ; i++)
			{
				if (mx >= Menu.X + Help.ButtonX1[i] && mx <= Menu.X + Help.ButtonX2[i] && my >= Menu.Y + Help.ButtonY1[i] && my <= Menu.Y + Help.ButtonY2[i])
				{
					if (Menu.Active != Help.Mode) PlaySound("Data\\Music\\Button.wav", NULL, SND_ASYNC);
					Menu.Active = Help.Mode;
					return 1;
				}
			}
			return 0;
		}
		int iQuitMenuSelection(int mx, int my)
		{
			for (int i = 0; i < Quit.Point; i++)
			{
				if (mx >= Menu.X + Quit.ButtonX1[i] && mx <= Menu.X + Quit.ButtonX2[i] && my >= Menu.Y + Quit.ButtonY1[i] && my <= Menu.Y + Quit.ButtonY2[i])
				{
					if (Menu.Active != Quit.Mode) PlaySound("Data\\Music\\Button.wav", NULL, SND_ASYNC);
					Menu.Active = Quit.Mode;
					return 1;
				}
			}	
			return 0;
		}
		void iMenuSelection(int mx, int my)
		{
			if(iNewMenuSelection(mx,my));
			else if(iCustomMenuSelection(mx,my));
			else if(iResumeMenuSelection(mx,my));
			else if(iHighScoreMenuSelection(mx,my));
			else if(iHelpMenuSelection(mx,my));
			else if(iQuitMenuSelection(mx,my));
			else Menu.Active = -1;
		}
	
	/*--------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/






/*------------------------------------------------------------------------------ K E Y B O A R D -------------------------------------------------------------------------------*/

	void iNameEntry(unsigned char key)
	{
		if (key == '\r')
		{
			int i, j;
			FILE *hs;
			ScoreSheet HS[11];
			hs = fopen("Data\\HighScore.txt", "r");

			for (i = 0; EOF != fscanf(hs, "%[^\n] %d %d\n", HS[i].Name, &HS[i].Score,&HS[i].Time) && i < 10; i++);
			fclose(hs);
			hs = fopen("Data\\HighScore.txt", "w");

			strcpy(HS[i].Name, NameEntry.Name);

			HS[i].Score = GameState.Score;
			HS[i].Time= GameState.Time;

			qsort(HS, i + 1, sizeof(ScoreSheet), Compare);

			for (j = 0; j <= i && j < 10; j++)
			{
				fprintf(hs, "%s\n%d\n%d\n", HS[j].Name, HS[j].Score,HS[j].Time);
			}

			fclose(hs);
			MODE = Menu.Mode;
			iReset();
			NameEntry.Name[0]='\0';
		}

		else
		{
			if (key == '\b')
			{
				if (strlen(NameEntry.Name) > 0)NameEntry.Name[strlen(NameEntry.Name) - 1] = '\0';
			}
			else if (strlen(NameEntry.Name) < 32)
			{
				NameEntry.Name[strlen(NameEntry.Name) + 1] = '\0';
				NameEntry.Name[strlen(NameEntry.Name)] = key;
			}

		}
	}
	void iKeyboard(unsigned char key)
	{

		if (MODE == NameEntry.Mode)
		{
			iNameEntry(key);
		}

		else if (key == 'q')
		{
			if (MODE == Game.Mode) iSaveState();
			MODE = Quit.Mode;
		}


		else if (key == '\r')
		{
			if (MODE == GameOver.Mode)
			{
				MODE == Menu.Mode;
			}

			else if (MODE == Custom.Mode)
			{
				int i, j;
				FILE *save = fopen(LevelUp.Level[level], "w");
				for (i = TotalC - 1; i > -1; i--)
				{
					for (j = 0; j < TotalR; j++)
					{
						fprintf(save, "%d ", Block[i][j].Strength );
					}
					fprintf(save, "\n") ;
				}
				fclose(save);
				level++;
			}
		}

		else if (key == '\b')
		{
			if (MODE)
			{
				if (MODE == Game.Mode)
				{
					iSaveState();
				}
				iReset();
				MODE = Menu.Mode;
			}
		}

		else if (key == 'p')
		{
			GameState.Pause = !GameState.Pause;
		}

		else if (key == ' ')
		{
			if (MODE == Game.Mode)
			{
				if (GameState.Launch)
				{
					if (Board.Gun)
					{
						PlaySound("Data\\Music\\Gun.wav", NULL, SND_ASYNC);
						Bullet.Table[Board.Y + Board.Height][Board.X + 4] = 1;
						Bullet.Table[Board.Y + Board.Height][Board.X + Board.Width - 4] = 1;
					}
				}
				else
				{
					GameState.Launch = 1;
				}
			}

		}
		else if(key=='x')
		{
			if (MODE)
			{
				if (MODE == Game.Mode)
				{
					iSaveState();
				}
				iReset();
				MODE = Menu.Mode;
			}
		}
	}
	void iSpecialKeyboard(unsigned char key)
	{
		if (key == GLUT_KEY_END) {
			exit(1);
		}
		else if (key == GLUT_KEY_RIGHT)
		{
			Board.X += Board.SpeedX;
			if (Board.X > Wall.X + TotalC * BlockWidth - Board.Width) { Board.X = Wall.X + TotalC * BlockWidth - Board.Width;}
		}
		else if (key == GLUT_KEY_LEFT)
		{
			Board.X -= Board.SpeedX;
			if (Board.X < Wall.X) { Board.X = Wall.X; }
		}
	}

/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/






/*----------------------------------------------------------------------- B L O C K 	C O L L I S I O N ----------------------------------------------------------------------*/

	void iRemoveBlock(int i, int j)
	{
		if (Block[i][j].Strength == 2)
		{
			PlaySound("Data\\Music\\Tank.wav", NULL, SND_ASYNC);
			iBomb(i, j);
		}
		else if (Block[i][j].Strength == 1)
		{
			Block[i][j].Strength = 0;
			Collide = 1;
			GameState.Remaining--;
			GameState.Score += 10;
			if (Block[i][j].Type)
			{
				DropItems.Table[Wall.Y + i * BlockHeight][Wall.X + j * BlockWidth] = Block[i][j].Type;
			}
		}
	}
	void iBomb(int i, int j)
	{
		if (Block[i][j].Strength == 1)
		{
			GameState.Remaining--;
			GameState.Score += 10;
			Block[i][j].Strength = 0;
		}
		else if (Block[i][j].Strength == 2)
		{
			GameState.Remaining--;
			GameState.Score += 10;
			Block[i][j].Strength = 0;
			if (i > 0 & j > 0) iBomb(i - 1, j - 1);
			if (i > 0 & j < TotalR - 1) iBomb(i - 1, j + 1);
			if (i < TotalC - 1 & j > 0) iBomb(i + 1, j - 1);
			if (i < TotalC - 1 & j < TotalR - 1) iBomb(i + 1, j + 1);
			if (i > 0) iBomb(i - 1, j);
			if (j > 0) iBomb(i, j - 1);
			if (i < TotalC - 1) iBomb(i + 1, j);
			if (j < TotalR - 1) iBomb(i, j + 1);
		}
	}
	int iRightSideCollision(int i, int j)
	{
		if (Ball.X >= Wall.X + Block[i][j].X + BlockWidth && Ball.X <= Wall.X + Block[i][j].X + BlockWidth + (Ball.Radius>Ball.RADIUS?Ball.Radius:Ball.RADIUS))
		{
			
			iRemoveBlock(i, j);
			if(!Ball.Fire)
			{
				Ball.dirX = abs(Ball.dirX);
				Ball.X = Wall.X + Block[i][j].X + BlockWidth + Ball.Radius;
			}	
			return 1;
		}
		return 0;
	}
	int iLeftSideCollision(int i, int j)
	{
		if (Ball.X >= Wall.X + Block[i][j].X - (Ball.Radius>Ball.RADIUS?Ball.Radius:Ball.RADIUS) && Ball.X <= Wall.X + Block[i][j].X)
		{
			
			iRemoveBlock(i, j);
			if(!Ball.Fire)
			{
				Ball.dirX = -abs(Ball.dirX);
				Ball.X = Wall.X + Block[i][j].X - Ball.Radius;
			}		
			return 1;
		}
		return 0;
	}
	int iTopSideCollision(int i, int j)
	{
		if (Ball.Y >= Wall.Y + Block[i][j].Y + BlockHeight && Ball.Y <= Wall.Y + Block[i][j].Y + BlockHeight + (Ball.Radius>Ball.RADIUS?Ball.Radius:Ball.RADIUS))
		{
			
			iRemoveBlock(i, j);
			if(!Ball.Fire)
			{
				Ball.dirY = abs(Ball.dirY);
				Ball.Y = Wall.Y + Block[i][j].Y + BlockHeight + Ball.Radius;
			}
			
			return 1;
		}
		return 0;
	}
	int iBottomSideCollision(int i, int j)
	{
		if (Ball.Y >= Wall.Y + Block[i][j].Y - (Ball.Radius>Ball.RADIUS?Ball.Radius:Ball.RADIUS) && Ball.Y <= Wall.Y + Block[i][j].Y)
		{
			
			iRemoveBlock(i, j);
			if(!Ball.Fire)
			{
				Ball.dirY = -abs(Ball.dirY);
				Ball.Y = Wall.Y + Block[i][j].Y - Ball.Radius;
			}
			
			return 1;
		}
		return 0;
	}
	int iTopRightCornerCollision(int i, int j)
	{
		if (Ball.Y >= Wall.Y + Block[i][j].Y + BlockHeight && Ball.Y <= Wall.Y + Block[i][j].Y + BlockHeight + (Ball.Radius>Ball.RADIUS?Ball.Radius:Ball.RADIUS))
		{
			
			iRemoveBlock(i, j);
			if(!Ball.Fire)
			{
				Ball.dirY = abs(Ball.dirY);
				Ball.dirX = abs(Ball.dirX);
				Ball.X = Wall.X + Block[i][j].X + BlockWidth + Ball.Radius;
				Ball.Y = Wall.Y + Block[i][j].Y + BlockHeight + Ball.Radius;
			}
			
			return 1;
		}
		return 0;
	}
	int iBottomRightCornerCollision(int i, int j)
	{
		if (Ball.Y >= Wall.Y + Block[i][j].Y - (Ball.Radius>Ball.RADIUS?Ball.Radius:Ball.RADIUS) && Wall.Y + Ball.Y <= Block[i][j].Y)
		{
			
			iRemoveBlock(i, j);
			if(!Ball.Fire)
			{
				Ball.dirY = -abs(Ball.dirY);
				Ball.dirX = abs(Ball.dirX);
				Ball.X = Wall.X + Block[i][j].X + BlockWidth + Ball.Radius;
				Ball.Y = Wall.Y + Block[i][j].Y - Ball.Radius;
			}
			
			return 1;
		}
		return 0;
	}
	int iTopLeftCornerCollision(int i, int j)
	{
		if (Ball.Y >= Wall.Y + Block[i][j].Y + BlockHeight && Ball.Y <= Wall.Y + Block[i][j].Y + BlockHeight + (Ball.Radius>Ball.RADIUS?Ball.Radius:Ball.RADIUS))
		{
			
			iRemoveBlock(i, j);
			if(!Ball.Fire)
			{
				Ball.dirY = abs(Ball.dirY);
				Ball.dirX = -abs(Ball.dirX);
				Ball.Y = Wall.Y + Block[i][j].Y + BlockHeight + Ball.Radius;
				Ball.X = Wall.X + Block[i][j].X - Ball.Radius;
			}
			
			return 1;
		}
		return 0;
	}
	int iBottomLeftCornerCollision(int i, int j)
	{
		if (Ball.Y >= Wall.Y + Block[i][j].Y - (Ball.Radius>Ball.RADIUS?Ball.Radius:Ball.RADIUS) && Ball.Y <= Wall.Y + Block[i][j].Y)
		{
			
			iRemoveBlock(i, j);
			if(!Ball.Fire)
			{
				Ball.dirY = -abs(Ball.dirY);
				Ball.dirX = -abs(Ball.dirX);
				Ball.Y = Wall.Y + Block[i][j].Y - Ball.Radius;
				Ball.X = Wall.X + Block[i][j].X - Ball.Radius;
			}
			
			return 1;
		}
	}
	void iCollision()
	{
		for (int i = 0; i < TotalR; i++)
		{
			for (int j = 0; j < TotalC; j++)
			{
				if (Block[i][j].Strength > 0)
				{
					if (!Collide)
					{
						if (Ball.X >= Wall.X + Block[i][j].X && Ball.X <= Wall.X + Block[i][j].X + BlockWidth)
						{
							if (iTopSideCollision(i, j))continue;
							if (iBottomSideCollision(i, j))continue;
						}

						if (Ball.Y >= Wall.Y + Block[i][j].Y && Ball.Y <= Wall.Y + Block[i][j].Y + BlockHeight)
						{
							if (iLeftSideCollision(i, j))continue;
							if (iRightSideCollision(i, j))continue;
						}

						if (Ball.X >= Wall.X + Block[i][j].X - (Ball.Radius>Ball.RADIUS?Ball.Radius:Ball.RADIUS) && Ball.X <= Wall.X + Block[i][j].X)
						{
							if (iBottomLeftCornerCollision(i, j))continue;
							if (iTopLeftCornerCollision(i, j))continue;
						}

						if (Ball.X >= Wall.X + Block[i][j].X + BlockWidth && Ball.X <= Wall.X + Block[i][j].X + BlockWidth + (Ball.Radius>Ball.RADIUS?Ball.Radius:Ball.RADIUS))
						{
							if (iBottomRightCornerCollision(i, j))continue;
							if (iTopRightCornerCollision(i, j))continue;
						}
					}
				}
			}
		}
		if(Collide)PlaySound("Data\\Music\\BallBlockCollision.wav", NULL, SND_NODEFAULT | SND_ASYNC);
		Collide = 0;
	}

/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
