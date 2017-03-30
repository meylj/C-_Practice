#include <iostream>
using namespace std;

static unsigned int  stepNum;  //步骤选择
static unsigned int  iStep;   //横坐标
static unsigned int  jStep;   //纵坐标
#define iMax 16
#define jMax 16
static char cWho[iMax][jMax];     //棋盘
static unsigned int flag = 1;  //1：走黑棋；0：走白棋
static unsigned int whiteCount[4] = {1,1,1,1};   //whiteCount[0]横向连续的白棋个数，whiteCount[1]纵向连续的白棋个数
                                           //whiteCount[2]左上角到右下角连续的白棋个数
                                           //whiteCount[3]右上角到左下角连续的白棋个数
static unsigned int blackCount[4] = {1,1,1,1};   //blackCount[0]横向连续的黑棋个数，blackCount[1]纵向连续的黑棋个数
                                           //blackCount[2]左上角到右下角连续的黑棋个数
                                           //blackCount[3]右上角到左下角连续的黑棋个数

void printPanel();   //打印棋盘
void initPanel();    //初始化棋盘，棋子全置'.'
void resetGame();    //重置棋盘，回到初始化状态
void cancelStep();   //悔棋，只能悔一步
void stopGame();     //停止游戏，退出
void blackGo();      //走黑棋
void whiteGo();      //走白棋
bool whoWon();       //判断输赢
void mainMenu();     //主菜单
void startMenu();    //游戏进行界面

int main(int argc, char const *argv[])    //主函数
{
	initPanel();  //先初始化棋盘
    mainMenu();   //进入主菜单
	return 0;
}

void printPanel()    //打印棋盘
{
	cout << "______________________________" << endl;
	cout << "\t" << "Welcome to GoBang!" << endl;
    cout << "------------------------------" << endl;
    cout << "     ";
    for (int i=0; i<iMax-1; ++i)
    {
        if(i <= 7) cout << i+1 << "  ";
        else cout << i+1 << " ";
    }
    cout << endl;
	for(int i=0; i<iMax; ++i)
    {   
       // cout << "  ";
        if(1 <= i)
        {
            if (i <= 9)  cout << i << " ";
            else cout << i;
        }
        else cout << "  ";

    	for(int j=0; j<jMax; j++)
    	{
            cout << cWho[i][j] << "  ";
    	}
    	cout << endl; 
    } 
    cout << "-----------------------------" << endl;
    cout << ".:Blank"<< "\t" << "B:Black"<< "\t" << "W:White" << endl;
    cout << "-----------------------------" << endl;
}

void initPanel()    //初始化棋盘并打印
{
	for (int i=0; i<iMax; ++i)
	{
		for (int j=0; j<jMax; ++j)
		{
			cWho[i][j] = '.';
		}
	}
    printPanel();
}

void resetGame()    //重置游戏到初始状态，回到主菜单
{
	initPanel();
	mainMenu();
}

void cancelStep()  //悔一步棋，打印棋盘，回到主菜单
{
	cout << iStep-1 << " " << jStep-1 << endl;
	cWho[iStep-1][jStep-1] = '.';
	if (flag == 1)
	{
		flag = 0;
	}
	else if (flag == 0)
	{
		flag = 1;
	}
	printPanel();
	mainMenu();
}

void stopGame()    //停止游戏，结束
{
	cout << "Game Over,bye-bye!" << endl;
}

void blackGo()    //走黑棋
{
    if(cWho[iStep-1][jStep-1] == '.')    //没有棋子
    {
        cWho[iStep-1][jStep-1] = 'B';    //放黑棋
        flag = 0;    //flag置0，因为下一步要走白棋
        if (cWho[iStep-1][jStep] == 'B' || cWho[iStep-1][jStep-2] == 'B')
        {
            blackCount[0] += 1;    //发现横向连续黑子，横向黑子计数加1
        }
        if (cWho[iStep][jStep-1] == 'B' || cWho[iStep-2][jStep-1] == 'B')
        {
            blackCount[1] += 1;    //发现竖向连续黑子，竖向黑子计数加1
        }
        if (cWho[iStep-2][jStep-2] == 'B' || cWho[iStep][jStep] == 'B')
        {
            blackCount[2] += 1;    //发现左上角到右下角连续黑子，左上角到右下角黑子计数加1
        }
        if (cWho[iStep-2][jStep] == 'B' || cWho[iStep][jStep-2] == 'B')
        {
            blackCount[3] += 1;    //发现右上角到左下角连续黑子，右上角到左下角黑子计数加1
        }
    }
    else    //被占用，重新选择路线
    {
        cout << "A chessman here,please select other location!";
        mainMenu();
    }
}

void whiteGo()
{
    if(cWho[iStep-1][jStep-1] == '.')    //没有棋子
    {
        cWho[iStep-1][jStep-1] = 'W';    //放白棋
        flag = 1;    //flag置1，因为下一步要走黑棋

        if (cWho[iStep-1][jStep] == 'W' || cWho[iStep-1][jStep-2] == 'W')
        {
            whiteCount[0] += 1;    //发现横向连续白子，横向白子计数加1
        }
        if (cWho[iStep][jStep-1] == 'W' || cWho[iStep-2][jStep-1] == 'W')
        {
            whiteCount[1] += 1;    //发现竖向连续白子，竖向白子计数加1
        }
        if (cWho[iStep-2][jStep-2] == 'W' || cWho[iStep][jStep] == 'W')
        {
            whiteCount[2] += 1;    //发现左上角到右下角连续白子，左上角到右下角白子计数加1
        }
        if (cWho[iStep-2][jStep] == 'W' || cWho[iStep][jStep-2] == 'W')
        {
            whiteCount[3] += 1;    //发现右上角到左下角连续白子，右上角到左下角白子计数加1
        }
    }
    else    //被占用，重新选择路线
    {
        cout << "A chessman here,please select other location!";
        mainMenu();
    }
}

bool whoWon()
{
    for (int i = 0; i < 4; ++i)  //打印棋子分布情况
    {
        cout << "blackCount" << i << ":" << blackCount[i] << " ";
        cout << "whiteCount" << i << ":" << whiteCount[i] << endl;
    }
    cout << "-----------------------------" << endl;

    //黑棋连续棋子数量是5，黑棋胜
    if(blackCount[0] == 5 || blackCount[1] == 5 || blackCount[2] == 5 || blackCount[3] == 5)
    {
        cout << "Well! Black won! Game is over!" << endl;
        return 1;
    }
    //白棋连续棋子数量是5，白棋胜
    if(whiteCount[0] == 5 || whiteCount[1] == 5 || whiteCount[2] == 5 || whiteCount[3] == 5)
    {
        cout << "Well! White won! Game is over!" << endl;
        return 1;
    }

    return 0;
}

void mainMenu()
{
    int notFullFlag = 0;
    for (int i = 1; i < iMax; ++i)
    {
        for (int j = 1; j < jMax; ++j)
        {
            if (cWho[i][j] == '.')    //若还有'.'的坐标，即棋盘未满
            {
                notFullFlag = 1;
            }
        }
    }
    if (notFullFlag)    //棋盘未满，可以继续游戏
    {
        cout << "Input the (i,j):";
        cin >> iStep;    //输入横坐标
        cin >> jStep;     //输入纵坐标
        iStep++;    //iStep=1时，在执行goBlack(),goWhite()函数时cWho数组会越界；所以加1，使从iStep=2开始布局
        jStep++;    //同iStep
        if (flag == 1)    //走黑棋
        {
            blackGo();
        }
        else if(flag == 0)    //走白棋
        {
            whiteGo();
        }
    }
    else    //棋盘已满，初始化棋盘，开始新游戏
    {
        cout << "The panel is full,they are all won!" << endl;
        initPanel();
    }
    startMenu();    //进入游戏进行界面
}

void startMenu()    //游戏进行界面
{
    printPanel();
    if (whoWon()) return;

	cout << "1:Continue  " << "2:Cancel  " << "3.Reset  " << "4.Stop" << endl;
	cout << "Please choose:" << endl;
	cin >> stepNum;
	switch(stepNum)
	{
	    case 1:    //继续游戏
	        mainMenu();
	        break;
	    case 2:
	        cancelStep();    //悔棋
	        break;
	    case 3:
	        resetGame();    //重置游戏
	        break;
	    case 4:
	        stopGame();    //停止游戏
	        break;
	    default:    //输入错误，重新选择
	        cout << "The wrong step,Please choose again:" << endl;
	        startMenu();
	        break;
	}
}


