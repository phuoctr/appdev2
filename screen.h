#define UNICODE
enum COLORS{BLACK=30, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE};
#define BAR "\u2590"
#define COL 80
#define bg(c) (c+10)
void clearScreen(void);
void setColors(short fg, short bg);
void resetColors(void);
void barChart(int []);
