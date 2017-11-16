#include "WidgetTextPush.h"


WidgetTextPush::WidgetTextPush(uint8_t ucItem)
{
    _Item=ucItem;
    memset(pDataStatusTopic,0,sizeof(pDataStatusTopic));
    memset(pCmdTextTopic,0,sizeof(pCmdTextTopic));
    sprintf(pDataStatusTopic,"channel/textPush_%d/data/status",_Item);
    sprintf(pCmdTextTopic,"channel/textPush_%d/cmd/text",_Item);
}

WidgetTextPush::~WidgetTextPush()
{
}

void WidgetTextPush::begin(void (*UserCallBack)(void))
{
    _EventCb=UserCallBack;
    IntoRobot.subscribe(pCmdTextTopic, NULL, this);
}


void WidgetTextPush::getText(String *pValue)
{
    *pValue = _text;
}

void WidgetTextPush::widgetBaseCallBack(uint8_t *payload, uint32_t len)
{
    _text = (char *)payload;
    _EventCb();
    IntoRobot.publish(pDataStatusTopic,1);
}





