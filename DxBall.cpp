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
	#define Explode_Mode 15
	#define ReloadBullet 10
	#define max(a,b) (a>b?a:b)
	#define min(a,b) (a<b?a:b)
	#define BLOCK 1
	#define BOMB 2
	#define BRICK (-1*BLOCK)
	#define ScoreUp 10

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/






/*----------------------------------------------------------------------------- F U N C T I O N S -----------------------------------------------------------------------------*/

	void Initialize(int, int, char*);
	void iReset();
	void iSet();
	void iSetCustom();
	void iResetDropItems();
	void iResetBullet();
	void iLoadState();
	void iSaveState();
	void iSaveScore();
	void iDeath();
	void iLevelUp();
	void iCatch();
	void iBallMove();
	void iDirection();


	void iDrawBall(int, int);
	void iDrawBack();
	void iDrawHighScore();
	void iDrawHelp();
	void iDrawMenu();
	void iDrawBlock(int, int, double , double, double);
	void iDrawBomb(int, int);
	void iDrawBrick(int, int);
	void iDrawBullet(int, int);
	void iDrawBoard(int, int);
	void iDrawTable();
	void iDrawCustom();
	void VerticalSegment(int , int, int, int, int);
	void HorizontalSegment(int, int, int , int, int);
	void iDrawDigit(int, int, int, int);
	void iDrawScore(int, int,int,int);
	void iDrawSmallScore(int, int,int,int);
	void iDrawLevel();
	void iDrawRemaining();
	void iDrawTime();
	void iDrawWin();
	void iDrawLevelUp();
	void iDrawQuit();
	void iDrawGameOver();
	void iDrawNameEntry();
	void iDraw();


	void iMouseMove(int, int);
	void iMouseLeftButtonDownMenu(int mx, int my);
	void iCustomPlay();
	void iMouseLeftButtonDownCustom(int mx, int my);
	void iMouseLeftButtonDown(int mx, int my);
	void iMouseRightButtonDown(int mx, int my);
	void iMouse(int, int, int, int);
	void mouseOverHandleFF(int, int);
	void iMouseOver(int, int);
	int iNewMenuSelection(int,int);
	int iCustomMenuSelection(int,int);
	int iResumeMenuSelection(int,int);
	int iHighScoreMenuSelection(int,int);
	int iHelpMenuSelection(int,int);
	int iQuitMenuSelection(int,int);
	void iMenuSelection(int, int);


	void iNameEntry(unsigned char );
	void iKeyboard(unsigned char);
	void iSpecialKeyboard(unsigned char );


	void iRemoveBlock(int, int);
	void iBomb(int, int);
	void iCollision();
	int iRightSideCollision(int, int);
	int iLeftSideCollision(int, int);
	int iTopSideCollision(int, int);
	int iBottomSideCollision(int, int);
	int iTopRightCornerCollision(int, int);
	int iBottomRightCornerCollision(int, int);
	int iTopLeftCornerCollision(int, int);
	int iBottomLeftCornerCollision(int, int);
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/






/*----------------------------------------------------------------------------- S T R U C T U R E -----------------------------------------------------------------------------*/


	struct
	{
		int X, Y;
		int Strength, Type;
	} Block[TotalR][TotalC];
	struct
	{
		int X=ScreenWidth/2, Y = 10,LastX,Height = 20,WIDTH=120,Width = WIDTH ,Extension=30,Compression=30, MinWidth=30;
		int SpeedX = 25, Gun = 0, Grab = 0 , Bullets = 0 ;
	} Board;
	struct
	{
		int RADIUS=10,Radius=RADIUS, SPEEDX=3,SPEEDY=8,Fire=0;
		double X = Board.X + Board.Width / 2, Y = Board.Y + Board.Height + Radius + Ball_Board;
		double SpeedX = SPEEDX,SpeedY = SPEEDY,SpeedXUp=1.2,SpeedYUp=1.2,SpeedXDown=0.8,SpeedYDown=0.8, dirX, dirY;
	} Ball;
	struct
	{
		int Launch , Life , Score;
		int Remaining, Pause , Level , Time ;
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
		char *Button[7] =
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
		int Point = 10, Play = 0, X=134,Y=0,Mode = 2, Win = 0, GameOver = 0,Left=0,Right=0;
		int WinX = 600, WinY = 100,GameOverX=460,GameOverY=100,RemainingX=100,RemainingY=1000;
		char ImageWin[30] = "Data\\Image\\Win.bmp";
		char ImageGameOver[30]= "Data\\Image\\GameOver.bmp";
		int ButtonX1[10] = {300, 305, 325, 335, 355, 365, 445, 490, 490, 555};
		int ButtonY1[10] = {530, 585, 545, 625, 625, 660, 625, 535, 585, 530};
		int ButtonX2[10] = {325, 325, 490, 355, 445, 415, 465, 585, 525, 600};
		int ButtonY2[10] = {590, 610, 625, 645, 660, 675, 645, 585, 610, 585};
		char PlayButton[40]="Data\\Image\\PlayButton.bmp";
		char LeftButton[40]="Data\\Image\\Left.bmp";
		char RightButton[40]="Data\\Image\\Right.bmp";
		char*ImageBG="Data\\Image\\Custom.bmp";
		int Level=0;
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
		int Point = 8, Mode = 4 , X=460,Y=400 ,ScoreX=600,ScoreY=550;
		int ButtonX1[8] = {440, 470, 490, 510, 530, 565, 600, 410};
		int ButtonY1[8] = {665, 640, 625, 615, 605, 585, 650, 675};
		int ButtonX2[8] = {560, 525, 510, 605, 655, 620, 635, 440};
		int ButtonY2[8] = {705, 665, 640, 685, 645, 605, 670, 700};
		char *ImageBG="Data\\Image\\HighScore.bmp";
	} HighScore;
	struct
	{
		int Point = 3, Mode = 5 ,X=ScreenWidth/2-939,Y=ScreenHeight/2-360;
		int ButtonX1[3] = {610, 655, 660};
		int ButtonY1[3] = {520, 585, 500};
		int ButtonX2[3] = {695, 690, 715};
		int ButtonY2[3] = {585, 605, 525};
		char *ImageBG="Data\\Image\\Help.bmp";
	} Help;
	struct
	{
		int Point = 9, Mode = 6 ,X=460,Y=43,NameX=1100,NameY=300;
		int ButtonX1[9] = {460, 490, 510, 535, 525, 575, 585, 600, 600};
		int ButtonY1[9] = {290, 295, 300, 320, 335, 365, 385, 420, 490};
		int ButtonX2[9] = {505, 550, 575, 615, 640, 665, 685, 700, 655};
		int ButtonY2[9] = {315, 325, 345, 365, 385, 415, 445, 490, 505};
		char *ImageBG="Data\\Image\\GoodBye.bmp";
	} Quit;
	struct
	{
		int Mode = 7;
		char *ImageWall="Data\\Image\\Wall.bmp";
		char *ImageBullet="Data\\Image\\Bullet.bmp";
		char *ImageLife="Data\\Image\\Life.bmp";
		int LeftWallX=0,LeftWallY=0,RightWallX=Wall.X+Wall.Width,RightWallY=0;
		int BulletX=ScreenWidth-120,BulletY=20;
		int LifeX=ScreenWidth - 90,LifeY=ScreenHeight - 100 ;
	} Game;
	struct
	{
		int X = 460, Y = ScreenHeight/2-504, Mode = 8,MAX=10;
		char *ImageBG = "Data\\Image\\LevelUp.bmp";
		char *Level[11] =
		{
			"Data\\Levels\\level0.txt",
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
		int Mode=9,X=460,Y=100;
		char *ImageBG="Data\\Image\\GameOver.bmp";
	} GameOver;
	struct
	{
		int X=460,Y=0,Mode=10,Active=0;
		char *ImageActive="Data\\Image\\NameEntryActive1.bmp";
		char *ImageDeactive="Data\\Image\\NameEntryDeactive1.bmp";
		char Name[50] = "";
	} NameEntry;
	struct
	{
		int Mode=11,X=600,Y=100;
		char *ImageBG="Data\\Image\\Win.bmp";
	}Win;
	struct
	{
		char Name[40];
		int Score,Time;
	} ScoreSheet[10];
	struct
	{
		int X = ScreenWidth, Y = ScreenHeight, Click;
		char *Image = "Data\\Image\\Mouse1.bmp";
	} Mouse;
	struct
	{
		char *BallXBlock="Data\\Music\\BallBlockCollision.wav";
		char *BallXBoard="Data\\Music\\BallBoardCollision.wav";
		char *BallXWall="Data\\Music\\BallWallCollision.wav";
		char *BallXBrick="Data\\Music\\BallBrickCollision.wav";
		char *BallXBomb="Data\\Music\\BallBombCollision.wav";
		char *GameOver="Data\\Music\\GameOver.wav";
		char *LevelUp="Data\\Music\\LevelUp.wav";
		char *MouseOver="Data\\Music\\Button.wav";
		char *MouseClick="Data\\Music\\Button2.wav";
		char *Reload="Data\\Music\\Reload.wav";
		char *Gun="Data\\Music\\Gun.wav";
		char *CatchItem="Data\\Music\\CatchItem.wav";
	} Sound;
	struct
	{
		int Width=1;
		int Height=5;
		int Triangle_Height=1;
		int TimeX=20,TimeY=70,RemainingX=20,RemainingY=20,LevelX=20,LevelY=120;
		int ScoreX=220,ScoreY=1000,BulletX=ScreenWidth-170,BulletY=35,BigScoreX=920,BigScoreY=850;
	} Font;
	struct
	{
		int Speed=16;
		int Table[ScreenHeight + 1][ScreenWidth + 1];
	}Bullet;
	struct
	{
		char *Image[15]=
		{
			"Data\\Image\\DropItems\\Death.bmp",  		//1
			"Data\\Image\\DropItems\\Gun.bmp",			//2
			"Data\\Image\\DropItems\\Life+1.bmp",		//3
			"Data\\Image\\DropItems\\Extend.bmp",		//4
			"Data\\Image\\DropItems\\Shrink.bmp",		//5
			"Data\\Image\\DropItems\\Fast.bmp",			//6
			"Data\\Image\\DropItems\\Slow.bmp",			//7
			"Data\\Image\\DropItems\\Level+1.bmp",		//8
			"Data\\Image\\DropItems\\Fall.bmp",			//9
			"Data\\Image\\DropItems\\Grab.bmp",			//10
			"Data\\Image\\DropItems\\Fire.bmp",			//11
			"Data\\Image\\DropItems\\Big.bmp",			//12
			"Data\\Image\\DropItems\\Small.bmp",		//13
			"Data\\Image\\DropItems\\SuperShrink.bmp",	//14
			"Data\\Image\\DropItems\\Explode.bmp"		//15
		};
		int Table[ScreenHeight + 1][ScreenWidth + 1];
	}DropItems;
	struct
	{
		int X = 30, Y = 20, Height = 100, Width = 148, Active = 0;
		char *Image = "Data\\Image\\BackButton.bmp", *ImageDark = "Data\\Image\\BackButtonDark.bmp";
	} Back;
	struct
	{
		char *BlockType="Data\\BlockType.txt";
		char *HighScore="Data\\HighScore.txt";
		char *LastState="Data\\LastState.txt";
	} Text;

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/






/*--------------------------------------------------------------------------------- L O G I C ---------------------------------------------------------------------------------*/

	int Collide = 0;
	int MODE = Menu.Mode , ADMIN = 0 ;
	int level=10;
	int main()
	{
		srand(time(NULL));
		iReset();
		iSetTimer(0, iBallMove);
		Initialize(ScreenWidth, ScreenHeight, "Dxball");
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
	void iReset()
	{
		GameState.Score = 0;
		GameState.Launch = 0;
		GameState.Life = 3;
		GameState.Remaining = 0;
		GameState.Level = 0;
		GameState.Pause = 0;
		Custom.Level=0;
		Board.Width=Board.WIDTH;
		Board.Grab=0;
		Board.Gun=0;
		Board.Bullets=0;
		Ball.X = Board.X + Board.Width / 2;
		Ball.Y = Board.Y + Board.Height + Ball.Radius + Ball_Board;
		Ball.dirX = 0;
		Ball.dirY = 0;
		Ball.SpeedX=Ball.SPEEDX;
		Ball.SpeedY=Ball.SPEEDY;
		Ball.Radius=Ball.RADIUS;
		Ball.Fire=0;
		iResetBullet();
		iResetDropItems();
		NameEntry.Name[0]='\0';

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
		fp = fopen(Text.BlockType, "r");
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
				if (Block[i][j].Strength ) GameState.Remaining++;
			}
		}
		fclose(fp);
        Board.X=Board.LastX=Mouse.X;
        Ball.X = Board.X + Board.Width / 2;
        Ball.Y = Board.Y + Board.Height + Ball.Radius + Ball_Board;
		Ball.dirX = 0;
		Ball.dirY = 0;
		Ball.SpeedX=Ball.SPEEDX;
		Ball.SpeedY=Ball.SPEEDY;
		GameState.Launch = 0;
	}
	void iSetCustom()
	{
		GameState.Remaining=0;
		Board.X=Board.LastX=Mouse.X;
		Ball.X = Board.X + Board.Width / 2;
		Ball.Y = Board.Y + Board.Height + Ball.Radius + Ball_Board;
		Ball.dirX = 0;
		Ball.dirY = 0;
		Ball.SpeedX=Ball.SPEEDX;
		Ball.SpeedY=Ball.SPEEDY;
		GameState.Launch = 0;
		FILE *fp;
		fp = fopen(LevelUp.Level[Custom.Level], "r");
		int i, j;
		for (i = TotalC - 1; i > -1; i--)
		{
			for (j = 0; j < TotalR; j++)
			{
				fscanf(fp, "%d", &Block[i][j].Strength);
				if (Block[i][j].Strength ) GameState.Remaining++;
			}
		}
		fclose(fp);
	}
	void iResetDropItems()
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

	void iLoadState()
	{
		int i, j;
		FILE *load = fopen(Text.LastState, "r");
		fscanf(load,"%d %d %d %d %d\n",&Board.X,&Board.LastX,&Board.Gun,&Board.Bullets,&Board.Grab);
		fscanf(load,"%lf %lf %lf %lf %lf %lf %d %d\n",&Ball.X,&Ball.Y,&Ball.SpeedX,&Ball.SpeedY,&Ball.dirX,&Ball.dirY,&Ball.Radius,&Ball.Fire);
		fscanf(load,"%d %d %d %d %d %d %d\n",&GameState.Life,&GameState.Launch,&GameState.Score,&GameState.Remaining,&GameState.Level,&GameState.Pause,&GameState.Time);
		fscanf(load,"%d\n",&Wall.Y);
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
		fclose(load);
	}
	void iSaveState()
	{
		int i, j;
		FILE *save = fopen(Text.LastState, "w");
		fprintf(save,"%d %d %d %d %d\n",Board.X, Board.LastX,Board.Gun,Board.Bullets, Board.Grab);
		fprintf(save,"%lf %lf %lf %lf %lf %lf %d %d\n", Ball.X,Ball.Y,Ball.SpeedX,Ball.SpeedY,Ball.dirX,Ball.dirY, Ball.Radius,Ball.Fire);
		fprintf(save,"%d %d %d %d %d %d %d\n",GameState.Life, GameState.Launch, GameState.Score, GameState.Remaining,GameState.Level,GameState.Pause,GameState.Time);
		fprintf(save,"%d\n",Wall.Y);
		for (i = TotalC - 1; i > -1; i--)
		{
			for (j = 0; j < TotalR; j++)
			{
				fprintf(save, "%d\t", Block[i][j].Strength );
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
		fclose(save);
	}

	void iSaveScore()
	{
		int i, j, k;
		FILE *hs;
		hs = fopen(Text.HighScore, "r");
		for (i = 0; EOF != fscanf(hs, "%[^\n] %d %d\n", ScoreSheet[i].Name, &ScoreSheet[i].Score, &ScoreSheet[i].Time)&i<10; i++);
		fclose(hs);

		for(j=0;j<i;j++)
		{
			if(GameState.Score>ScoreSheet[j].Score)
			{
				break;
			}
			else if(GameState.Score==ScoreSheet[i].Score&&GameState.Time<ScoreSheet[i].Time)
			{
				break;
			}
		}
		if(j<i)
		{
			for(k=i;k>j;k--)
			{

				ScoreSheet[k].Score=ScoreSheet[k-1].Score;
				ScoreSheet[k].Time=ScoreSheet[k-1].Time;
				strcpy(ScoreSheet[k].Name,ScoreSheet[k-1].Name);
			}

			ScoreSheet[k].Score=GameState.Score;
			ScoreSheet[k].Time=GameState.Time;
			strcpy(ScoreSheet[k].Name, NameEntry.Name);
			hs = fopen(Text.HighScore, "w");
			for (j = 0; j <= i && j<10 ; j++)
			{
				fprintf(hs, "%s\n%d\n%d\n", ScoreSheet[j].Name, ScoreSheet[j].Score, ScoreSheet[j].Time);
			}
			fclose(hs);
		}

		else if(j==i && j<10)
		{
			ScoreSheet[j].Score = GameState.Score;
			ScoreSheet[j].Time = GameState.Time;
			strcpy(ScoreSheet[j].Name, NameEntry.Name);
			hs = fopen(Text.HighScore, "w");
			for (j = 0; j <=i && j < 10; j++)
			{
				fprintf(hs, "%s\n%d\n%d\n", ScoreSheet[j].Name, ScoreSheet[j].Score, ScoreSheet[j].Time);
			}
			fclose(hs);
		}
	}
	void iDeath()
	{
		
		if (GameState.Life == 1)
		{
			if(GameState.Level==0)
			{
				Custom.GameOver=1;
			}
			else
			{
				MODE = GameOver.Mode;
			}
		}
		else
		{
			iSaveState();
		}
		GameState.Life--;
		GameState.Launch = 0;	
		Board.Width=Board.WIDTH;
		Board.Grab=0;
		Board.Gun=0;
		Ball.SpeedX=Ball.SPEEDX;
		Ball.SpeedY=Ball.SPEEDY;
		Ball.dirX=0;
		Ball.dirY=0;
		Ball.Fire=0;
		Ball.Radius=Ball.RADIUS;
		Ball.X = Board.X + Board.Width / 2, Ball.Y = Board.Y + Board.Height + Ball.Radius + Ball_Board, Ball.dirX = 0, Ball.dirY = 0;
		PlaySound(Sound.GameOver, NULL, SND_ASYNC);
		iResetBullet();
		iResetDropItems();
		Sleep(1000);
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
			Board.Bullets=0;
			Board.Grab = 0;
			Board.Width = Board.WIDTH;
			Ball.Fire=0;
			Ball.Radius=Ball.RADIUS;
			iResetBullet();
			iResetDropItems();
			Wall.Y = WallY;
			Ball.SpeedX=Ball.SPEEDX;
			Ball.SpeedY=Ball.SPEEDY;
			glutWarpPointer(ScreenWidth/2,ScreenHeight/2);
			Board.X=Mouse.X;
			Ball.X = Board.X + Board.Width / 2;
			Ball.Y = Board.Y + Board.Height + Ball.Radius + Ball_Board;
			Ball.dirX = 0;
			Ball.dirY = 0;
			GameState.Level++;
			iSet();
			MODE = Game.Mode;
			iSaveState();
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
			for (j = Board.X - 49; j < Board.X + Board.Width; j++)
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
							PlaySound(Sound.Reload, NULL,SND_ASYNC);
							Board.Gun = 1;
							Board.Bullets+=ReloadBullet;
							DropItems.Table[i][j] = 0;
							break;
						case Life_Mode:
							PlaySound(Sound.CatchItem, NULL,SND_ASYNC);
							GameState.Life++;
							DropItems.Table[i][j] = 0;
							break;
						case Extend_Mode:
							PlaySound(Sound.CatchItem, NULL,SND_ASYNC);
							if (Board.WIDTH + Board.Extension <= ScreenWidth - 2 * Wall.X)
							{

								Board.Width += Board.Extension;
								if (Board.X - Board.Extension/2 >=Wall.X)
								{
									glutWarpPointer(Mouse.X- Board.Extension/2,ScreenHeight/2);
									Board.X-=Board.Extension/2;
									if(Board.X>Wall.X+Wall.Width-Board.Width)
									{
										glutWarpPointer(Mouse.X-Board.Extension/2,ScreenHeight/2);
										Board.X-=Board.Extension/2;
									}
								}
							}
							DropItems.Table[i][j] = 0;
							break;
						case Shrink_Mode:
							PlaySound(Sound.CatchItem, NULL,SND_ASYNC);
							if (Board.Width - Board.Compression >= Board.MinWidth)
							{
								glutWarpPointer(Mouse.X+ Board.Compression/2,ScreenHeight/2);
								Board.X+=Board.Compression/2;
								Board.Width -= Board.Compression;
								if(!GameState.Launch)
								{
									if(Ball.X<Board.X) Ball.X=Board.X;
									else if(Ball.X>Board.X+Board.Width) Ball.X=Board.X+Board.Width;
								}
							}
							DropItems.Table[i][j] = 0;
							break;
						case Fast_Mode:
							PlaySound(Sound.CatchItem, NULL,SND_ASYNC);
							if (abs(Ball.dirY) < 20)
							{
								Ball.dirY *= Ball.SpeedYUp;
								Ball.SpeedY*= Ball.SpeedYUp;
								Ball.dirX *=  Ball.SpeedXUp;
								Ball.SpeedX*= Ball.SpeedXUp;
							}
							DropItems.Table[i][j] = 0;
							break;
						case Slow_Mode:
							PlaySound(Sound.CatchItem, NULL,SND_ASYNC);
							if (abs(Ball.dirY) > 0)
							{
								Ball.dirY *= Ball.SpeedYDown;
								Ball.SpeedY*=Ball.SpeedYDown;
								Ball.dirX *= Ball.SpeedXDown;
								Ball.SpeedX*=Ball.SpeedXDown;
							}
							DropItems.Table[i][j] = 0;
							break;
						case LevelUp_Mode:
							PlaySound(Sound.LevelUp, NULL,SND_ASYNC);
							if (GameState.Level<LevelUp.MAX&&GameState.Level>0)
							{
								MODE = LevelUp.Mode;
							}
							else if(GameState.Level==LevelUp.MAX) iLevelUp();
							else Custom.Win = 1;
							DropItems.Table[i][j] = 0;
							break;
						case Fall_Mode:
							PlaySound(Sound.CatchItem, NULL,SND_ASYNC);
							if(Wall.Y>2*BlockHeight)
							{
								Wall.Y -= BlockHeight;
							}
							DropItems.Table[i][j] = 0;
							break;
						case Grab_Mode:
							PlaySound(Sound.CatchItem, NULL,SND_ASYNC);
							Board.Grab = 1;
							DropItems.Table[i][j] = 0;
							break;
						case Fire_Mode:
							PlaySound(Sound.CatchItem, NULL,SND_ASYNC);
							Ball.Fire = 1;
							DropItems.Table[i][j] = 0;
							break;
						case Big_Mode:
							PlaySound(Sound.CatchItem, NULL,SND_ASYNC);
							if(Ball.Radius==Ball.RADIUS)
							{
								Ball.Radius = Ball.RADIUS * 1.5;
								Ball.dirY *= 1.2;
								Ball.SpeedY*=1.2;
								Ball.dirX *= 1.2;
								Ball.SpeedX*=1.2;
								if(!GameState.Launch)
								{
									Ball.Y=Board.Y+Board.Height+ Ball_Board+Ball.Radius;

								}
							}
							
							DropItems.Table[i][j] = 0;
							break;
						case Small_Mode:
							PlaySound(Sound.CatchItem, NULL,SND_ASYNC);		
							if(Ball.Radius==Ball.RADIUS)
							{
								Ball.Radius = Ball.RADIUS * 0.6;
								Ball.dirY *= .8;
								Ball.SpeedY*=.8;
								Ball.dirX *= .8;
								Ball.SpeedX*=.8;
								if(!GameState.Launch)
								{
									Ball.Y=Board.Y+Board.Height+ Ball_Board+Ball.Radius;
								}
							}

							DropItems.Table[i][j] = 0;
							break;
						case SuperShrink_Mode:
							PlaySound(Sound.CatchItem, NULL,SND_ASYNC);
							glutWarpPointer(Mouse.X+(Board.Width-Board.MinWidth)/2,ScreenHeight/2);
							Board.X+=(Board.Width-Board.MinWidth)/2;
							Board.Width = Board.MinWidth;
							if(!GameState.Launch)
							{
								if(Ball.X<Board.X) Ball.X=Board.X;
								else if(Ball.X>Board.X+Board.Width) Ball.X=Board.X+Board.Width;
							}
							DropItems.Table[i][j] = 0;
							break;
						case Explode_Mode:

							{
								int i,j;
								for (i = 0; i < TotalC; i++)
								{
									for (j = 0; j < TotalR; j++)
									{
										if(Block[i][j].Strength == 2) iRemoveBlock( i , j );
									}
								}
							}

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

			iCatch();
			if(GameState.Launch)
			{
				Ball.X += Ball.dirX;
				Ball.Y += Ball.dirY;
			}
			if (Ball.dirY < 0 & Ball.Y >= Board.Y + Board.Height / 2 - Ball.Radius & Ball.Y <= Board.Y + Board.Height + Ball.Radius + Ball_Board )
			{
				iDirection();
			}
			else if (Ball.Y > ScreenHeight - Ball.Radius)
				{
					PlaySound(Sound.BallXWall, NULL, SND_ASYNC);
					Ball.dirY *= -1; Ball.Y = ScreenHeight - Ball.Radius;
				}
			else if (Ball.X < Wall.X + Ball.Radius)
				{
					PlaySound(Sound.BallXWall, NULL, SND_ASYNC);
					Ball.dirX *= -1; Ball.X = Wall.X + Ball.Radius;
				}
			else if (Ball.X > Wall.X + Wall.Width - Ball.Radius)
			 {
			 	PlaySound(Sound.BallXWall, NULL, SND_ASYNC);
			 	Ball.dirX *= -1; Ball.X = Wall.X + Wall.Width - Ball.Radius;
			 }
			else if (Ball.dirY < 0 & Ball.Y < Board.Y + Board.Height / 2 - Ball.Radius)
			{

				iDeath();

			}

			if (GameState.Remaining == 0)
			{
				PlaySound(Sound.LevelUp, NULL,SND_ASYNC);
				if (GameState.Level<LevelUp.MAX&&GameState.Level>0)
				{
					MODE = LevelUp.Mode;
				}
				else if(GameState.Level==LevelUp.MAX) iLevelUp();
				else
				{
					Ball.dirX=0;
					Ball.dirY=0;
					GameState.Launch = 0;
					GameState.Score += 10 * GameState.Remaining;
					iResetBullet();
					Custom.Win = 1;
				}
			}
			if (GameState.Life == 0)
			{
				if(GameState.Level==0)
				{
					Custom.GameOver=1;
				}
				else
				{
					MODE = GameOver.Mode;
				}
			}

			iCollision();

		}
		else if (MODE == LevelUp.Mode)
		{
			Sleep(1000);
			iLevelUp();
		}
	}
	void iDirection()
	{
		if (Ball.X >= Board.X && Ball.X <= Board.X + Board.Width)
		{
			if(Board.Grab)Ball.Y=Board.Y + Board.Height + Ball.Radius + Ball_Board;
			PlaySoundA(Sound.BallXBoard, NULL, SND_ASYNC);
			if(Ball.X != Board.X + Board.Width / 2)
			{
				Ball.dirX = ceil((Ball.X - Board.X - Board.Width / 2) * Ball.SpeedX * max(min(12,Ball.Radius),8) / Board.Width);
			}
			while(!Ball.dirX)
			{
				Ball.dirX=(rand()%15)-7;
			}
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
		char name[40], S[10];
		int T;
		int i;
		hs = fopen(Text.HighScore, "r");
		iShowBMP2(HighScore.X,HighScore.Y,HighScore.ImageBG, 0X00060412);
		iSetColor(166, 41, 166);
		iText(HighScore.ScoreX,HighScore.ScoreY, "POS", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(HighScore.ScoreX+70,HighScore.ScoreY, "NAME", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(HighScore.ScoreX+520,HighScore.ScoreY, "TIME", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(HighScore.ScoreX+660,HighScore.ScoreY, "SCORE", GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(255, 255, 255);
		for (i = 0; EOF != fscanf(hs, "%[^\n] %s %d\n", name,S,&T) ; i++)
		{
			{
				char Temp[5];
				iText(HighScore.ScoreX, HighScore.ScoreY-50 - 40 * i, itoa(i + 1, Temp, 10), GLUT_BITMAP_TIMES_ROMAN_24);
				iText(HighScore.ScoreX+70, HighScore.ScoreY-50 - 40 * i, name, GLUT_BITMAP_TIMES_ROMAN_24);
				sprintf(Temp,"%0.2d",(T/60) / 3600);
				iText(HighScore.ScoreX+500, HighScore.ScoreY-50-40*i,Temp, GLUT_BITMAP_TIMES_ROMAN_24);
				iText(HighScore.ScoreX+530, HighScore.ScoreY-50+2-40*i, ":", GLUT_BITMAP_TIMES_ROMAN_24);
				sprintf(Temp,"%0.2d",((T/60) / 60) % 60);
				iText(HighScore.ScoreX+540, HighScore.ScoreY-50-40*i,Temp, GLUT_BITMAP_TIMES_ROMAN_24);
				iText(HighScore.ScoreX+570, HighScore.ScoreY-50+2-40*i, ":", GLUT_BITMAP_TIMES_ROMAN_24);
				sprintf(Temp,"%0.2d",(T/60) % 60);
				iText(HighScore.ScoreX+580, HighScore.ScoreY-50-40*i,Temp, GLUT_BITMAP_TIMES_ROMAN_24);
				iText(HighScore.ScoreX+660, HighScore.ScoreY-50 - 40 * i, S, GLUT_BITMAP_TIMES_ROMAN_24);
			}
		}


		fclose(hs);
		iDrawBack();
	}
	void iDrawHelp()
	{
		iShowBMP(Help.X,Help.Y,Help.ImageBG);
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
		if((GameState.Time/10)%2)
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
		else
		{
			iSetColor(231, 231, 231);
			iFilledRectangle(x, y, BlockWidth, BlockHeight);
			iSetColor(235, 211, 187);
			iFilledRectangle(x + 3, y + 3, BlockWidth - 6, BlockHeight - 6);
			iSetColor(239, 191, 143);
			iFilledRectangle(x + 6, y + 6, BlockWidth - 12, BlockHeight - 12);
			iSetColor(239, 191, 143);
			iSetColor(243, 171, 95);
			iFilledRectangle(x + 9, y + 9, BlockWidth - 18, BlockHeight - 18);
			
			iSetColor(247, 147, 47);
			iFilledRectangle(x + 12, y + 12, BlockWidth - 24, BlockHeight - 24);
			iSetColor(255, 127, 0);
			iFilledRectangle(x + 15, y + 15, BlockWidth - 30, BlockHeight - 30);
		}
		

		iSetColor(5, 5, 5);
		iRectangle(x, y, BlockWidth, BlockHeight);
	}
	void iDrawBrick(int x, int y)
	{
		iSetColor(200, 165, 0);
		iFilledRectangle(x, y, BlockWidth, BlockHeight);
		iSetColor(205, 175, 20);
		iFilledRectangle(x + 3, y + 3, BlockWidth - 6, BlockHeight - 6);
		iSetColor(210, 185,40);
		iFilledRectangle(x + 6, y + 6, BlockWidth - 12, BlockHeight - 12);
		iSetColor(215, 195, 60);
		iFilledRectangle(x + 9, y + 9, BlockWidth - 18, BlockHeight - 18);
		iSetColor(220, 205, 80);
		iFilledRectangle(x + 12, y + 12, BlockWidth - 24, BlockHeight - 24);
		iSetColor(225, 215, 100);
		iFilledRectangle(x + 15, y + 15, BlockWidth - 30, BlockHeight - 30);
		iSetColor(5, 5, 5);
		iRectangle(x, y, BlockWidth, BlockHeight);
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
		int i,j;
		for (i = 0; i < TotalC; i++)
		{
			for (j = 0; j < TotalR; j++)
			{
				int R=(GameState.Level%3==1?i*i:GameState.Level%3==2?i*i:i*j);  //i*i
				int G=(GameState.Level%3==1?i*j:GameState.Level%3==2?i*i:j*j);  //i*j
				int B=(GameState.Level%3==1?j*j:GameState.Level%3==2?i*i:j*i);  //j*j
				if (Block[i][j].Strength == BLOCK)
					iDrawBlock(Wall.X + Block[i][j].X, Wall.Y + Block[i][j].Y, 18 + R / 1.5, 18 + G / 1.5, 18 + B / 1.5);
				else if (Block[i][j].Strength == BOMB)
					iDrawBomb(Wall.X + Block[i][j].X, Wall.Y + Block[i][j].Y);
				else if(Block[i][j].Strength == BRICK)
					iDrawBrick(Wall.X + Block[i][j].X, Wall.Y + Block[i][j].Y);
			}
		}
	}
	void iDrawCustom()
	{
		int i,j;
		iShowBMP(Custom.X,Custom.Y,Custom.ImageBG);
		if (Custom.Play == 1) iShowBMP2(Custom.X,Custom.Y,Custom.PlayButton, 0X00ffffff);
		if (Custom.Left == 1) iShowBMP2(Custom.X,Custom.Y,Custom.LeftButton, 0X00ffffff);
		if (Custom.Right == 1) iShowBMP2(Custom.X,Custom.Y,Custom.RightButton, 0X00ffffff);
		for (i = 0; i < TotalC; i++)
		{
			for (j = 0; j < TotalR; j++)
			{
				int R=(Custom.Level%3==1?i*i:Custom.Level%3==2?i*i:i*j);  //i*i
				int G=(Custom.Level%3==1?i*j:Custom.Level%3==2?i*i:j*j);  //i*j
				int B=(Custom.Level%3==1?j*j:Custom.Level%3==2?i*i:j*i);  //j*j
				if (Block[i][j].Strength == BLOCK)
					iDrawBlock(Wall.X + Block[i][j].X, Wall.Y + Block[i][j].Y-170, 18 + R / 1.5, 18 + G / 1.5, 18 + B / 1.5);
				else if (Block[i][j].Strength == BOMB)
					iDrawBomb(Wall.X + Block[i][j].X, Wall.Y + Block[i][j].Y - 170);
				else if(Block[i][j].Strength == BRICK)
					iDrawBrick(Wall.X + Block[i][j].X, Wall.Y + Block[i][j].Y - 170);
			}
		}

		for (i = 0; i < TotalC; i++)
		{
			for (j = 0; j < TotalR; j++)
			{
				iSetColor(100, 100, 100);
				iRectangle(Wall.X + Block[i][j].X, Wall.Y + Block[i][j].Y - 170, BlockWidth, BlockHeight);
			}
		}
		iDrawBack();

		iSetColor(166, 41, 166);
		iText(260,40,"Left click and Drag - ",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(260,10,"Left click on a normal block - ",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(1440,40,"- Right click and Drag",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(1350,10,"- Right click on an empty block",GLUT_BITMAP_TIMES_ROMAN_24);

		iSetColor(146,62,241);
		iText(475,40,"Draw a normal block",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(575,10,"Draw an explosive",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(1320,40,"Erase block",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(1220,10,"Draw a brick",GLUT_BITMAP_TIMES_ROMAN_24);

		iDrawSmallScore(GameState.Remaining, 3,Custom.RemainingX,Custom.RemainingY);
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
	void iDrawScore(int S, int size, int x,int y)
	{
		int i;

		int n = floor(log10(S)) + 1;
		if (!S) iDrawDigit(x,y, S, 10);
		for (i = 0; S; i++)
		{
			iDrawDigit(x - ceil(n / 2.0) * 100 + n * 100 - i * 100, y, S % 10, size);
			S /= 10;
		}
	}
	void iDrawSmallScore(int S, int size,int x,int y)
	{
		int i;

		if (!S) iDrawDigit(x, y, S, size);
		for (i = 0; S; i++)
		{
			iDrawDigit(x - i * 30, y, S % 10, size);
			S /= 10;
		}
	}
	void iDrawLevel()
	{
		iSetColor(188, 3, 57);
		iText(Font.LevelX,Font.LevelY, "LEVEL - ", GLUT_BITMAP_TIMES_ROMAN_24);
		char temp[3];
		iText(Font.LevelX+100, Font.LevelY, itoa(GameState.Level, temp, 10), GLUT_BITMAP_TIMES_ROMAN_24);
	}
	void iDrawRemaining()
	{
		iSetColor(188, 3, 57);
		iText(Font.RemainingX,Font.RemainingY, "REMAINING - ", GLUT_BITMAP_TIMES_ROMAN_24);
		char temp[3];
		iText(Font.RemainingX+170, Font.RemainingY, itoa(GameState.Remaining, temp, 10), GLUT_BITMAP_TIMES_ROMAN_24);
	}
	void iDrawTime()
	{
		char Temp[50];
		GameState.Time++;
		iSetColor(188, 3, 57);
		sprintf(Temp,"%0.2d",(GameState.Time/60) / 3600);
		iText(Font.TimeX,Font.TimeY, Temp, GLUT_BITMAP_TIMES_ROMAN_24);
		iText(Font.TimeX+30, Font.TimeY+2, ":", GLUT_BITMAP_TIMES_ROMAN_24);
		sprintf(Temp,"%0.2d",((GameState.Time / 60) / 60) % 60);
		iText(Font.TimeX+40, Font.TimeY, Temp, GLUT_BITMAP_TIMES_ROMAN_24);
		iText(Font.TimeX+70, Font.TimeY+2, ":", GLUT_BITMAP_TIMES_ROMAN_24);
		sprintf(Temp,"%0.2d",(GameState.Time / 60) % 60);
		iText(Font.TimeX+80, Font.TimeY, Temp, GLUT_BITMAP_TIMES_ROMAN_24);
	}
	void iDrawWin()
	{
		iShowBMP(Win.X,Win.Y,Win.ImageBG);
		if (NameEntry.Active)iShowBMP2(NameEntry.X,NameEntry.Y, NameEntry.ImageActive,0X00000000);
		else iShowBMP2(NameEntry.X,NameEntry.Y, NameEntry.ImageDeactive,0X00000000);
		iSetColor(100, 100, 100);
		iText(NameEntry.X+370,NameEntry.Y+165, "ENTER YOUR NAME", GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(188, 3, 57);
		iDrawScore(GameState.Score, 10,Font.BigScoreX,Font.BigScoreY);
		iDrawBack();
	}
	void iDrawGame()
	{
		int i,j;
		for (i = 0; i < 28; i++)
		{
			for (j = 0; j < 37; j++)
			{
				iDrawBlock(i * BlockWidth - 19, j * BlockHeight - 10, 8, 8, 8);
			}
		}
		iSetColor(255, 255, 255);
		iDrawBoard(Board.X, Board.Y);
		iSetColor(180, 180, 180);
		iDrawBall(Ball.X, Ball.Y);
		iShowBMP(Game.LeftWallX,Game.LeftWallY, Game.ImageWall);
		iShowBMP(Game.RightWallX,Game.RightWallY,Game.ImageWall);
		// iSetColor(188, 3, 57);
		iSetColor(255,255,0);
		iDrawSmallScore(GameState.Score, 3,Font.ScoreX,Font.ScoreY);
		iDrawLevel();
		iDrawRemaining();
		if(Board.Gun)
		{
			iShowBMP2(Game.BulletX,Game.BulletY, Game.ImageBullet,0X00ffffff);
			iSetColor(255, 255, 0);
			iDrawSmallScore(Board.Bullets,3,Font.BulletX,Font.BulletY);
		}

		if (GameState.Pause)
		{
			iSetColor(255, 255, 0);
			iText(Font.TimeX,Font.TimeY, "PAUSED", GLUT_BITMAP_TIMES_ROMAN_24);
		}
		else
		{
			iDrawTime();
		}
		for (i = 0; i < GameState.Life - 1; i++)
		{
			iShowBMP2(Game.LifeX - (i % 3) * 80,Game.LifeY-100*((i / 3)), Game.ImageLife, 0X00000000);
		}
		for (j = 0; j < ScreenWidth; j++)
		{
			for (i = floor((ScreenHeight - Board.Y - Board.Height) / Bullet.Speed) * Bullet.Speed; i >= Board.Y + Board.Height; i--)
			{
				if (Bullet.Table[i][j])
				{
					if (i >= Wall.Y && i <= Wall.Y + Wall.Height)
					{
						if (Block[(i - Wall.Y) / BlockHeight][(j - Wall.X) / BlockWidth].Strength)
						{
							Bullet.Table[i][j] = 0;
							Block[(i - Wall.Y) / BlockHeight][(j - Wall.X) / BlockWidth].Strength=abs(Block[(i - Wall.Y) / BlockHeight][(j - Wall.X) / BlockWidth].Strength);
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

		for (i = 0; i < ScreenHeight; i++)
		{
			for (j = 0; j < ScreenWidth; j++)
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
		iShowBMP(Quit.X,Quit.Y,Quit.ImageBG);
		iSetColor(50,50,50);
		iText(Quit.NameX,Quit.NameY,"- MAHIR LABIB DIHAN",GLUT_BITMAP_TIMES_ROMAN_24);
		Menu.Quit = 1;
	}
	void iDrawGameOver()
	{
		iShowBMP(GameOver.X,GameOver.Y ,GameOver.ImageBG);
		if (NameEntry.Active)iShowBMP2(NameEntry.X,NameEntry.Y, NameEntry.ImageActive,0X00000000);
		else iShowBMP2(NameEntry.X,NameEntry.Y, NameEntry.ImageDeactive,0X00000000);
		iSetColor(100, 100, 100);
		iText(NameEntry.X+370,NameEntry.Y+165, "ENTER YOUR NAME", GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(188, 57, 133);
		iDrawScore(GameState.Score, 10,Font.BigScoreX,Font.BigScoreY);
		iDrawBack();
	}
	void iDrawNameEntry()
	{
		if(GameState.Level<=LevelUp.MAX)
			{
				iShowBMP(GameOver.X,GameOver.Y,GameOver.ImageBG);
				iSetColor(188, 57, 133);
			}
		else
			{
				iShowBMP(Win.X,Win.Y,Win.ImageBG);
				iSetColor(188, 3, 57);
			}
		iDrawScore(GameState.Score, 10,Font.BigScoreX,Font.BigScoreY);
		if (NameEntry.Active)iShowBMP2(NameEntry.X,NameEntry.Y, NameEntry.ImageActive,0X00000000);

		iSetColor(200, 200, 200);
		iText(NameEntry.X+310,NameEntry.Y+165, NameEntry.Name, GLUT_BITMAP_TIMES_ROMAN_24);
		iDrawBack();
	}
	void iDrawLevelUp()
	{

		iShowBMP(LevelUp.X, LevelUp.Y, LevelUp.ImageBG);
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
				iSetColor(188, 3, 57);
				iShowBMP(Custom.WinX, Custom.WinY, Custom.ImageWin);
				iDrawScore(GameState.Score, 10,Font.BigScoreX,Font.BigScoreY);
			}
			else if(Custom.GameOver)
			{
				iShowBMP(Custom.GameOverX, Custom.GameOverY, Custom.ImageGameOver);
				iSetColor(188, 57, 133);
				iDrawScore(GameState.Score, 10,Font.BigScoreX,Font.BigScoreY);
			}
			else iDrawGame();
		}
		else if (MODE == LevelUp.Mode)
		{
			iDrawLevelUp();
		}

		if (MODE != Game.Mode&& MODE!=LevelUp.Mode && MODE!=Quit.Mode)
			iShowBMP2(Mouse.X, Mouse.Y - 35, Mouse.Image, 0X00000000);
	}

/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/






/*--------------------------------------------------------------------------------- M O U S E ----------------------------------------------------------------------------------*/

	void iMouseMove(int mx, int my)
	{

		Mouse.X = mx, Mouse.Y = my;
		if (MODE == Custom.Mode)
		{
			int i,j;
			for (i = 0; i < TotalC; i++)
			{
				for (j = 0; j < TotalR; j++)
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
			PlaySound(Sound.MouseClick, NULL, SND_ASYNC);
			iReset();
			GameState.Level++;
			iSet();
			GameState.Time = 0;
			MODE = Game.Mode;
			Menu.Active = -1;
		}
		else if (Menu.Active == Custom.Mode)
		{
			PlaySound(Sound.MouseClick, NULL, SND_ASYNC);
			MODE = Custom.Mode;
			iReset();
			iSetCustom();
			Menu.Active = -1;
		}
		else if (Menu.Active == Resume.Mode)
		{

			PlaySound(Sound.MouseClick, NULL, SND_ASYNC);
			iLoadState();
			MODE = Game.Mode;
			Menu.Active = -1;
		}
		else if (Menu.Active == HighScore.Mode)
		{
			PlaySound(Sound.MouseClick, NULL, SND_ASYNC);
			MODE = HighScore.Mode;
			Menu.Active = -1;
		}
		else if (Menu.Active == Help.Mode)
		{
			PlaySound(Sound.MouseClick, NULL, SND_ASYNC);
			MODE = Help.Mode;
			Menu.Active = -1;
		}
		else if (Menu.Active == Quit.Mode)
		{
			PlaySound(Sound.MouseClick, NULL, SND_ASYNC);
			MODE = Quit.Mode;
			Menu.Active = -1;
		}
	}
	void iCustomPlay()
	{
		if(GameState.Remaining)
			{
				MODE = Game.Mode;
				GameState.Time = 0;
				Board.X=Board.LastX=Mouse.X-Board.Width/2;
				Ball.X = Board.X + Board.Width / 2,Ball.Y = Board.Y + Board.Height + Ball.Radius + Ball_Board;
				PlaySound(Sound.MouseClick, NULL, SND_ASYNC);
			}
			Custom.Play = 0;
	}
	void iMouseLeftButtonDownCustom(int mx, int my)
	{
		if (Custom.Play == 1)
		{
			iCustomPlay();
		}
		else if(Custom.Left==1)
		{
			if(Custom.Level>0)
			{
				PlaySound(Sound.MouseClick, NULL, SND_ASYNC);
				Custom.Level--;
				iSetCustom();
			}
			Custom.Left=0;

		}
		else if(Custom.Right==1)
		{
			if(Custom.Level<LevelUp.MAX)
			{
				PlaySound(Sound.MouseClick, NULL, SND_ASYNC);
				Custom.Level++;
				iSetCustom();
			}
			Custom.Right=0;

		}
		else
		{
			int i,j;
			for (i = 0; i < TotalC; i++)
			{
				for (j = 0; j < TotalR; j++)
				{
					if (mx >= Wall.X + Block[i][j].X && mx <= Wall.X + Block[i][j].X + BlockWidth)
					{
						if (my >= Wall.Y + Block[i][j].Y - 170 && my <= Wall.Y + Block[i][j].Y - 170 + BlockHeight)
						{
							if (Block[i][j].Strength == 1)
							{
								Block[i][j].Strength++;
							}
							else if (Block[i][j].Strength == 0)
							{
								GameState.Remaining++;
								Block[i][j].Strength++;
							}
							else if(Block[i][j].Strength==-1)
							{
								GameState.Remaining--;
								Block[i][j].Strength++;
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
			else if (Back.Active)
			{
				PlaySound(Sound.MouseClick, NULL, SND_ASYNC);
				MODE = Menu.Mode;
				Back.Active = 0;
				iReset();
			}
		}
		else if (MODE == Custom.Mode)
		{
			iMouseLeftButtonDownCustom(mx, my);
		}
		else if (MODE == Game.Mode)
		{
			if(GameState.Pause)
			{
				GameState.Pause=0;
				glutWarpPointer(Board.X,ScreenHeight-Mouse.Y);
			}
			else if (!GameState.Launch)
			{
				iDirection();
			}
			else if (Board.Gun)
			{
				if(Board.Bullets>0)
				{
					PlaySound(Sound.Gun, NULL, SND_ASYNC);
					Bullet.Table[Board.Y + Board.Height][Board.X + 4] = 1;
					Bullet.Table[Board.Y + Board.Height][Board.X + Board.Width - 4] = 1;
					Board.Bullets--;
					if(Board.Bullets==0) Board.Gun=0;
				}
			}
		}
		else if (MODE == Menu.Mode)
		{
			iMouseLeftButtonDownMenu(mx, my);
		}

		if (MODE == Custom.Mode || MODE == HighScore.Mode || MODE == Help.Mode || MODE==NameEntry.Mode)
		{
			if (Back.Active)
			{
				PlaySound(Sound.MouseClick, NULL, SND_ASYNC);
				MODE = Menu.Mode;
				Back.Active = 0;
				iReset();
			}

		}
	}
	void iMouseRightButtonDown(int mx, int my)
	{
		int i,j;
		if (MODE == Custom.Mode)
		{
			Mouse.Click = 1;
			for (i = 0; i < TotalC; i++)
			{
				for (j = 0; j < TotalR; j++)
				{
					if (mx >= Wall.X + Block[i][j].X && mx <= Wall.X + Block[i][j].X + BlockWidth)
					{
						if (my >= Wall.Y + Block[i][j].Y - 170 && my <= Wall.Y + Block[i][j].Y - 170 + BlockHeight)
						{
							if(abs(Block[i][j].Strength)==1) { Block[i][j].Strength = 0; GameState.Remaining--;}
							else if(Block[i][j].Strength==2) { Block[i][j].Strength = 0; GameState.Remaining--;}
							else { Block[i][j].Strength = -1; GameState.Remaining++ ;}
						}
					}
				}
			}
		}

		else if (MODE == Game.Mode)
		{
			if(!GameState.Pause) GameState.Pause = 1;
			else
			{
				iSaveState();
				MODE=Menu.Mode;
			}
		}

		else if(MODE==GameOver.Mode||MODE==Win.Mode||MODE==NameEntry.Mode)
		{
			MODE=Menu.Mode;
		}
	}
	void iMouse(int button, int state, int mx, int my)
	{
		if(state == GLUT_DOWN&&(Custom.GameOver||Custom.Win))
		{
			MODE = Menu.Mode;
			Custom.GameOver = 0;
			Custom.Win = 0;
		}
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

		if(MODE==Game.Mode||MODE==LevelUp.Mode)
		{
			if(mx<Wall.X)
			{
				glutWarpPointer(Wall.X,ScreenHeight/2);
				mx=Wall.X;
			}
			else if(mx>Wall.X+Wall.Width-Board.Width)
			{
				glutWarpPointer(Wall.X+Wall.Width-Board.Width,ScreenHeight/2);
				mx=Wall.X+Wall.Width-Board.Width;
			}
		}

		my = ScreenHeight - my;
		if(MODE==Game.Mode||MODE==LevelUp.Mode)  my=ScreenHeight/2;
		iMouseOver(mx, my);
	}
	void iMouseOver(int mx, int my)
	{
		if(mx<=ScreenWidth-25) Mouse.X = mx;
		else Mouse.X=ScreenWidth-25;
		if(my>=35) Mouse.Y = my;
		else Mouse.Y=35;
		if (MODE == Game.Mode)
		{
			if (GameState.Pause) return;
			Board.LastX=Board.X;
			Board.X = Mouse.X;
			if(!GameState.Launch)
			{
				Ball.X=Board.X+Ball.X-Board.LastX;
			}
			Board.LastX=Board.X;
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
			if ((mx >= Back.X && mx <= Back.X + Back.Width / 2 && my >= Back.Y && my <= Back.Y + Back.Height) || (mx >= Back.X + Back.Width / 2 && mx <= Back.X + Back.Width && my >= Back.Y + Back.Height / 2 - 10 && my <= Back.Y + Back.Height / 2 + 10))
			{
				if (!Back.Active)PlaySound(Sound.MouseOver, NULL, SND_ASYNC);
				Back.Active = 1;
			}
			else
			{
				Back.Active = 0;
			}
		}

		else if (MODE == Custom.Mode)
		{
			if (mx >= 880 && mx <= 1050 && my >= 820 && my <= 1020)
			{
				if (!Custom.Play)PlaySound(Sound.MouseOver, NULL, SND_ASYNC);
				Custom.Play = 1;
			}
			else
			{
				Custom.Play = 0;
			}

			if (mx >= 590 && mx <= 780 && my >= 870 && my <= 970)
			{
				if (!Custom.Left)PlaySound(Sound.MouseOver, NULL, SND_ASYNC);
				Custom.Left = 1;
			}
			else
			{
				Custom.Left = 0;
			}
			if (mx >= 1140 && mx <= 1330 && my >= 870 && my <= 970)
			{
				if (!Custom.Right)PlaySound(Sound.MouseOver, NULL, SND_ASYNC);
				Custom.Right = 1;
			}
			else
			{
				Custom.Right = 0;
			}

			if ((mx >= 30 && mx <= 120 && my >= 20 && my <= 120) || (mx >= 120 && mx <= 178 && my >= 60 && my <= 80))
			{
				if (!Back.Active)PlaySound(Sound.MouseOver, NULL, SND_ASYNC);
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

		else if (MODE == Help.Mode || MODE == HighScore.Mode || MODE==NameEntry.Mode)
		{
			if ((mx >= Back.X && mx <= Back.X + Back.Width / 2 && my >= Back.Y && my <= Back.Y + Back.Height) || (mx >= Back.X + Back.Width / 2 && mx <= Back.X + Back.Width && my >= Back.Y + Back.Height / 2 - 10 && my <= Back.Y + Back.Height / 2 + 10))
			{
				if (!Back.Active)PlaySound(Sound.MouseOver, NULL, SND_ASYNC);
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
			int i;
			for (i = 0; i < New.Point; i++)
			{
				if (mx >= Menu.X + New.ButtonX1[i] && mx <= Menu.X + New.ButtonX2[i] && my >= Menu.Y + New.ButtonY1[i] && my <= Menu.Y + New.ButtonY2[i])
				{
					if (Menu.Active != New.Mode) PlaySound(Sound.MouseOver, NULL, SND_ASYNC);
					Menu.Active = New.Mode;
					return 1;
				}
			}
			return 0;
		}
		int iCustomMenuSelection(int mx, int my)
		{
			int i;
			for (i = 0; i < Custom.Point; i++)
			{
				if (mx >= Menu.X + Custom.ButtonX1[i] && mx <= Menu.X + Custom.ButtonX2[i] && my >= Menu.Y + Custom.ButtonY1[i] && my <= Menu.Y + Custom.ButtonY2[i])
				{
					if (Menu.Active != Custom.Mode) PlaySound(Sound.MouseOver, NULL, SND_ASYNC);
					Menu.Active = Custom.Mode;
					return 1;
				}
			}
			return 0;
		}
		int iResumeMenuSelection(int mx, int my)
		{
			int i;
			for (i = 0; i < Resume.Point ; i++)
			{
				if (mx >= Menu.X + Resume.ButtonX1[i] && mx <= Menu.X + Resume.ButtonX2[i] && my >= Menu.Y + Resume.ButtonY1[i] && my <= Menu.Y + Resume.ButtonY2[i])
				{
					if (Menu.Active != Resume.Mode) PlaySound(Sound.MouseOver, NULL, SND_ASYNC);
					Menu.Active = Resume.Mode;
					return 1;
				}
			}
			return 0;
		}
		int iHighScoreMenuSelection(int mx, int my)
		{
			int i;
			for (i = 0; i < HighScore.Point ; i++)
			{
				if (mx >= Menu.X + HighScore.ButtonX1[i] && mx <= Menu.X + HighScore.ButtonX2[i] && my >= Menu.Y + HighScore.ButtonY1[i] && my <= Menu.Y + HighScore.ButtonY2[i])
				{
					if (Menu.Active != HighScore.Mode) PlaySound(Sound.MouseOver, NULL, SND_ASYNC);
					Menu.Active = HighScore.Mode;
					return 1;
				}
			}
			return 0;
		}
		int iHelpMenuSelection(int mx, int my)
		{
			int i;
			for (i = 0; i < Help.Point ; i++)
			{
				if (mx >= Menu.X + Help.ButtonX1[i] && mx <= Menu.X + Help.ButtonX2[i] && my >= Menu.Y + Help.ButtonY1[i] && my <= Menu.Y + Help.ButtonY2[i])
				{
					if (Menu.Active != Help.Mode) PlaySound(Sound.MouseOver, NULL, SND_ASYNC);
					Menu.Active = Help.Mode;
					return 1;
				}
			}
			return 0;
		}
		int iQuitMenuSelection(int mx, int my)
		{
			int i;
			for (i = 0; i < Quit.Point; i++)
			{
				if (mx >= Menu.X + Quit.ButtonX1[i] && mx <= Menu.X + Quit.ButtonX2[i] && my >= Menu.Y + Quit.ButtonY1[i] && my <= Menu.Y + Quit.ButtonY2[i])
				{
					if (Menu.Active != Quit.Mode) PlaySound(Sound.MouseOver, NULL, SND_ASYNC);
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
			iSaveScore();
			NameEntry.Active = 0;
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
			else if(key==27)
			{
				MODE=Menu.Mode;
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
			if (MODE == Game.Mode) 
				{
					if(!Custom.Win&&!Custom.GameOver)
					iSaveState();
				}
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
				if(ADMIN)
				{
					int i, j;
					FILE *save = fopen(LevelUp.Level[Custom.Level], "w");
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

				else
				{
					MODE = Game.Mode;
					GameState.Time = 0;
					Custom.Play = 0;
					Board.X=Board.LastX=Mouse.X-Board.Width/2;
					Ball.X = Board.X + Board.Width / 2,Ball.Y = Board.Y + Board.Height + Ball.Radius + Ball_Board;
					PlaySound(Sound.MouseClick, NULL, SND_ASYNC);
				}
			}
		}

		else if (key == '\b'||key==27)
		{
			if (MODE)
			{
				if (MODE == Game.Mode)
				{
					if(!Custom.Win&&!Custom.GameOver)
					iSaveState();
				}
				iReset();
				MODE = Menu.Mode;
			}
		}

		else if (key == 'p')
		{
			GameState.Pause = !GameState.Pause;
			glutWarpPointer(Board.X,ScreenHeight-Mouse.Y);
		}

		else if (key == ' ')
		{
			if (MODE == Game.Mode)
			{
				if (!GameState.Launch)
				{
					iDirection();
				}
				else if(GameState.Pause)
				{
					GameState.Pause=0;
					glutWarpPointer(Board.X,ScreenHeight-Mouse.Y);
				}
				else if (Board.Gun)
				{
					if(Board.Bullets>0)
					{
						PlaySound(Sound.Gun, NULL, SND_ASYNC);
						Bullet.Table[Board.Y + Board.Height][Board.X + 4] = 1;
						Bullet.Table[Board.Y + Board.Height][Board.X + Board.Width - 4] = 1;
						Board.Bullets--;
						if(Board.Bullets==0) Board.Gun=0;
					}
				}
			}
		}
	}
	void iSpecialKeyboard(unsigned char key)
	{
		if(Custom.GameOver||Custom.Win)
        {
            MODE = Menu.Mode;
            Custom.GameOver = 0;
            Custom.Win = 0;
        }
		if(MODE==Game.Mode)
		{
			if (key == GLUT_KEY_END) {
				MODE=Quit.Mode;

			}
			else if (key == GLUT_KEY_RIGHT)
			{
				if (Board.X +  Board.SpeedX<=Wall.X + Wall.Width - Board.Width)
				{
					Board.X += Board.SpeedX;
					if(!GameState.Launch)
					{
						Ball.X+=Board.SpeedX;
					}
				}

				else
				{
					if(!GameState.Launch)
					{
						Ball.X+=(Wall.X + Wall.Width - Board.Width-Board.X);
					}
					Board.X=Wall.X + Wall.Width - Board.Width;
				}
			}
			else if (key == GLUT_KEY_LEFT)
			{
				if (Board.X - Board.SpeedX >= Wall.X)
				{
					Board.X -= Board.SpeedX;
					if(!GameState.Launch)
					{
						Ball.X-=Board.SpeedX;
					}
				}
				else
				{
					if(!GameState.Launch)
					{
						Ball.X-=(Board.X-Wall.X);
					}

					Board.X=Wall.X;
				}
			}
		}

		else if(MODE==Custom.Mode)
		{
			if (key == GLUT_KEY_RIGHT)
			{
				if(Custom.Level<LevelUp.MAX)
				{
					PlaySound(Sound.MouseClick, NULL, SND_ASYNC);
					Custom.Level++;
					iSetCustom();
				}
			}
			else if (key == GLUT_KEY_LEFT)
			{

				if(Custom.Level>0)
				{
					PlaySound(Sound.MouseClick, NULL, SND_ASYNC);
					Custom.Level--;
					iSetCustom();
				}
			}
		}
	}

/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/





/*----------------------------------------------------------------------- B L O C K 	C O L L I S I O N ----------------------------------------------------------------------*/

	void iRemoveBlock(int i, int j)
	{
		if (Block[i][j].Strength == BOMB)
		{
			Collide= BOMB;
			iBomb(i, j);
		}
		else if(Ball.Fire)
		{
			if(abs(Block[i][j].Strength)== BLOCK)
			{
				Block[i][j].Strength = 0;
				Collide = BLOCK;
				GameState.Remaining--;
				GameState.Score += 10;
				if (Block[i][j].Type)
				{
					DropItems.Table[Wall.Y + i * BlockHeight][Wall.X + j * BlockWidth] = Block[i][j].Type;
				}
			}
		}
		else if (Block[i][j].Strength == BLOCK)
		{
			Block[i][j].Strength = 0;
			Collide = BLOCK;
			GameState.Remaining--;
			GameState.Score += 10;
			// if (Block[i][j].Type)
			{
				DropItems.Table[Wall.Y + i * BlockHeight][Wall.X + j * BlockWidth] = rand()%16;//Block[i][j].Type;
			}
		}
		else if(Block[i][j].Strength == BRICK)
		{
			Block[i][j].Strength = 1;
			Collide = BRICK;
		}
	}
	void iBomb(int i, int j)
	{
		if (abs(Block[i][j].Strength) == BLOCK)
		{
			GameState.Remaining--;
			GameState.Score += 10;
			Block[i][j].Strength = 0;
		}
		else if (Block[i][j].Strength == BOMB)
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

	void iCollision()
	{
		int i,j;
		for (i = 0; i < TotalR; i++)
		{
			for (j = 0; j < TotalC; j++)
			{
				if (Block[i][j].Strength)
				{
					 if (!Collide)
					{
						if(Ball.X>Wall.X+Block[i][j].X-Ball.Radius&&Ball.X<Wall.X+Block[i][j].X+BlockWidth+Ball.Radius&&Ball.Y>Wall.Y+Block[i][j].Y-Ball.Radius&&Ball.Y<Wall.Y+Block[i][j].Y+BlockHeight+Ball.Radius)
						{
							if (Ball.X >= Wall.X + Block[i][j].X && Ball.X <= Wall.X + Block[i][j].X + BlockWidth )
							{
								if (iTopSideCollision(i, j))continue;
								if (iBottomSideCollision(i, j))continue;
							}
							if (Ball.Y >= Wall.Y + Block[i][j].Y && Ball.Y <= Wall.Y + Block[i][j].Y + BlockHeight)
							{
								if (iLeftSideCollision(i, j))continue;
								if (iRightSideCollision(i, j))continue;
							}
							if (Ball.X >= Wall.X + Block[i][j].X - Ball.Radius && Ball.X <= Wall.X + Block[i][j].X+(Ball.Radius>Ball.RADIUS?Ball.Radius:Ball.RADIUS))
							{
								if (iBottomLeftCornerCollision(i, j))continue;
								if (iTopLeftCornerCollision(i, j))continue;
							}

							if (Ball.X >= Wall.X + Block[i][j].X + BlockWidth -(Ball.Radius>Ball.RADIUS?Ball.Radius:Ball.RADIUS) && Ball.X <= Wall.X + Block[i][j].X + BlockWidth +Ball.Radius)
							{
								if (iBottomRightCornerCollision(i, j))continue;
								if (iTopRightCornerCollision(i, j))continue;
							}
							iRemoveBlock(i,j);
							if(!Ball.Fire)
							{
								Ball.dirX*=-1;
								Ball.dirY*=-1;
							}
						}
					}
				}
			}
		}
		if(Collide== BOMB) PlaySound(Sound.BallXBomb, NULL, SND_ASYNC);
		else if(Collide== BLOCK) PlaySound(Sound.BallXBlock, NULL,SND_ASYNC);
		else if(Collide== BRICK) PlaySound(Sound.BallXBrick, NULL,SND_ASYNC);
		Collide = 0;
	}
	int iRightSideCollision(int i, int j)
	{
		if (Ball.X >= Wall.X + Block[i][j].X + BlockWidth-max(Ball.Radius,Ball.RADIUS) && Ball.X < Wall.X + Block[i][j].X + BlockWidth + Ball.Radius && Ball.dirX<0 )
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
		if (Ball.X > Wall.X + Block[i][j].X - Ball.Radius && Ball.X <= Wall.X + Block[i][j].X+max(Ball.Radius,Ball.RADIUS) && Ball.dirX>0 )
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
		if (Ball.Y >= Wall.Y + Block[i][j].Y + BlockHeight-max(Ball.Radius,Ball.RADIUS) && Ball.Y < Wall.Y + Block[i][j].Y + BlockHeight + Ball.Radius  && Ball.dirY<0)
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
		if (Ball.Y > Wall.Y + Block[i][j].Y - Ball.Radius  && Ball.Y <= Wall.Y + Block[i][j].Y+max(Ball.Radius,Ball.RADIUS)&& Ball.dirY>0)
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
		if (Ball.Y >= Wall.Y + Block[i][j].Y + BlockHeight- max(Ball.Radius,Ball.RADIUS)/2 && Ball.Y <Wall.Y + Block[i][j].Y + BlockHeight + Ball.Radius  )
		{
			iRemoveBlock(i, j);
			if(!Ball.Fire)
			{
				Ball.dirY = abs(Ball.dirY);
				Ball.dirX = abs(Ball.dirX);
			}
			return 1;
		}
		return 0;
	}
	int iBottomRightCornerCollision(int i, int j)
	{
		if (Ball.Y >= Wall.Y + Block[i][j].Y -  Ball.Radius &&  Ball.Y <= Wall.Y +Block[i][j].Y + max(Ball.Radius,Ball.RADIUS)/2 )
		{
			iRemoveBlock(i, j);
			if(!Ball.Fire)
			{
				Ball.dirY = -abs(Ball.dirY);
				Ball.dirX = abs(Ball.dirX);
			}
			return 1;
		}
		return 0;
	}
	int iTopLeftCornerCollision(int i, int j)
	{
		if (Ball.Y >= Wall.Y + Block[i][j].Y + BlockHeight- max(Ball.Radius,Ball.RADIUS)/2 && Ball.Y <Wall.Y + Block[i][j].Y + BlockHeight + Ball.Radius  )
		{
			iRemoveBlock(i, j);
			if(!Ball.Fire)
			{
				Ball.dirY = abs(Ball.dirY);
				Ball.dirX = -abs(Ball.dirX);
			}
			return 1;
		}
		return 0;
	}
	int iBottomLeftCornerCollision(int i, int j)
	{
		if (Ball.Y >= Wall.Y + Block[i][j].Y -  Ball.Radius &&  Ball.Y <= Wall.Y +Block[i][j].Y + max(Ball.Radius,Ball.RADIUS)/2 )
		{
			iRemoveBlock(i, j);
			if(!Ball.Fire)
			{
				Ball.dirY = -abs(Ball.dirY);
				Ball.dirX = -abs(Ball.dirX);
			}
			return 1;
		}
	}
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
