/****************************************************************************
 Copyright (c) 2013 cocos2d-x.org
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/


#ifndef __UILAYER_H__
#define __UILAYER_H__

#include "cocos2d.h"
#include "gui/UIRootWidget.h"
#include "gui/UIInputManager.h"

namespace gui {


class UILayer : public cocos2d::Layer
{
    
public:
    /**
     * Default constructor
     * @js ctor
     */
    UILayer();
    
    /**
     * Default destructor
     * @js NA
     * @lua NA
     */
    virtual ~UILayer();
    
    /**
     * Allocates and initializes a widget.
     */
    static UILayer *create(void);
    
    //initializes state of uilayer.
    virtual bool init() override;
    /**
     *  @js NA
     *  @lua NA
     */
    virtual void onEnter() override;
    /**
     *  @js NA
     *  @lua NA
     */
    virtual void onExit() override;
    virtual void onEnterTransitionDidFinish() override;
    /**
     *  @js NA
     *  @lua NA
     */
    virtual bool onTouchBegan(cocos2d::Touch *pTouch, cocos2d::Event *pEvent);
    /**
     *  @js NA
     *  @lua NA
     */
    virtual void onTouchMoved(cocos2d::Touch *pTouch, cocos2d::Event *pEvent);
    /**
     *  @js NA
     *  @lua NA
     */
    virtual void onTouchEnded(cocos2d::Touch *pTouch, cocos2d::Event *pEvent);
    /**
     *  @js NA
     *  @lua NA
     */
    virtual void onTouchCancelled(cocos2d::Touch *pTouch, cocos2d::Event *pEvent);
    
    /**
     * Add a widget to UILayer, for drawing.
     *
     * @param widget.
     */
    void addWidget(UIWidget* widget);
    
    /**
     * Remove a widget from UILayer.
     *
     * @param widget.
     *
     * @param cleanup true if all running actions on all children widgets should be cleanup, false otherwise.
     */
    void removeWidget(UIWidget* widget);
    
    /**
     * Sets whether the UILayer is visible
     *
     * The default value is true, a UILayer is default to visible
     *
     * @param visible   true if the UILayer is visible, false if the UILayer is hidden.
     */
    virtual void setVisible(bool visible) override;
    
    /**
     * Finds a widget whose tag is equal tag param from widget tree.
     *
     * @param tag.
     */
    UIWidget* getWidgetByTag(int tag);
    
    /**
     * Seek a widget whose name is equal name param from widget tree.
     *
     * @param name.
     */
    UIWidget* getWidgetByName(const char* name);
    
    /**
     * Gets UIInputManager.
     *
     * UIInputManager is the touch manager of UILayer.
     *
     * @return UIInputManager.
     * @js NA
     * @lua NA
     */
    UIInputManager* getInputManager();
    
    /**
     * Remove and clean up all of UILayer's widget.
     */
    virtual void clear();
    
    /**
     * Gets root widget of UILayer.
     *
     * @return UIRootWidget, "UIRootWidget" is the root widget of UILayer.
     */
    UIRootWidget* getRootWidget();

protected:
    UIRootWidget* _rootWidget;
    UIInputManager* _inputManager;
};

}



#endif /* defined(__UILAYER_H__) */