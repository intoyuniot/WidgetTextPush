/*
************************************************************************
* 作者:  IntoRobot Team
* 版本:  V1.0.0
* 日期:  03-30-15
************************************************************************
功能描述：
文本推送应用：

OLED屏    核心板
OLED_CLK    D4
OLED_MOSI   D3
OLED_DC     D2
OLED_CS     D1
OLED_RESET	D0

说明：带有“D”的为数字管脚，带有“A”的为模拟管脚，接线时请确认核心板引脚，避免接线错误。
*/

#include <WidgetTextPush.h>
#include <Adafruit_SSD1306.h>

#define OLED_CLK    D4
#define OLED_MOSI   D3
#define OLED_DC     D2
#define OLED_CS     D1
#define OLED_RESET	D0

Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);
String temp;

WidgetTextPush textPush = WidgetTextPush();

void DisplayCb(void)
{
	textPush.getText(&temp);

	display.clearDisplay();
	display.display();

	display.setTextSize(1);
	display.setTextColor(WHITE);
	display.setCursor(0,0);
	display.println(temp);
	display.display();
}

void setup()
{
	display.begin(SSD1306_SWITCHCAPVCC);
	display.setTextSize(1);
	display.setTextColor(WHITE);
	display.setCursor(0,0);
	display.println(temp);
	display.display();
	delay(1000);

	display.clearDisplay();
	display.display();

	textPush.begin(DisplayCb);
}

void loop()
{

}
