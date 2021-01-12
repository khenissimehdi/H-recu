#include <MLV/MLV_all.h>

#define LINE_COLOR MLV_COLOR_BLUE
#define BACKGROUND_COLOR MLV_COLOR_WHITE

void recd(int x , int y , int width){
	if (width < 8)
	{
		return;
	}
	
	MLV_draw_line(x-width/2, y, x+width/2, y, LINE_COLOR);
	MLV_draw_line(x-width/2, y-width/2, x-width/2, y+width/2, LINE_COLOR);
	MLV_draw_line(x+width/2, y-width/2, x+width/2, y+width/2, LINE_COLOR);

	
	recd( x-width/2 ,  y-width/2 , width/2);
	recd( x-width/2 ,  y+width/2 , width/2);
	recd( x+width/2 ,  y-width/2 , width/2);
	recd( x+width/2 ,  y+width/2 , width/2);
}
int main() {

	/* Create the window */
	MLV_create_window("Draw", "Draw", 500, 500);
	MLV_draw_filled_rectangle(0, 0, 499, 499, BACKGROUND_COLOR);
	int width = 300;

	/* Draw the letter A 
	
	MLV_draw_line(200-width/2, 200, 200+width/2, 200, LINE_COLOR);
	MLV_draw_line(200-width/2, 200-width/2, 200-width/2, 200+width/2, LINE_COLOR);
	MLV_draw_line(200+width/2, 200-width/2, 200+width/2, 200+width/2, LINE_COLOR);*/
	recd( 200 ,  200 , width/2);
	MLV_update_window();

	/* Wait and quit */

	MLV_wait_seconds(100000);
	MLV_free_window();

	return 0;
}