#ifndef WIDGET_TEXT_PUSH_H_
#define WIDGET_TEXT_PUSH_H_

#include "application.h"


class WidgetTextPush:public WidgetBaseClass
{
    public:
        WidgetTextPush(uint8_t ucItem = 0);
        ~WidgetTextPush();
        void begin(void (*UserCallBack)(void) = NULL);
        void getText(String *pValue);

    private:
        char pCmdTextTopic[64];
        char pDataStatusTopic[64];
        uint8_t _Item = 0;
        String _text;
        void (*_EventCb)(void);
        void widgetBaseCallBack(uint8_t *payload, uint32_t len);

};

#endif
