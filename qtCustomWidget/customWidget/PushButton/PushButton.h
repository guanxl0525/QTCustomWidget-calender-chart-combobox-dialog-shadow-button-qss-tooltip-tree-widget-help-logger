#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H

/**
* @brief: QPushButton的自定义button控件
* @author: Fu_Lin
* @date:
* @description:左icon，中文本，右icon， 可多次点击
*/



#include <QPushButton>
#include <QMouseEvent>
#include <QLabel>
#include <QHBoxLayout>

class PushButton : public QPushButton
{
    Q_OBJECT

public:
    explicit PushButton(QWidget *parent = nullptr);

    //设置是否有点击效果
    void setClickEffect(bool clickEffect);
    //设置背景图片
    void setBackgroundImage(QString imgPath, QSize size = QSize());
    //设置背景是否透明，不影响图片的设置，单纯的背景透明
    void setButtonTransparency(bool isTransparency);
    //设置背景颜色，默认颜色是蓝色
    void setBackgroundColor(QString backgroundColor);
    //设置字体颜色， 默认字体颜色是灰色
    void setFontColor(QString fontColor);
    //设置按钮文本
    void setButtonText(const QString &text);
    void setText(const QString &text);
    //设置按钮左边的图标
    void setLeftIcon(const QString &Licon, const QSize &size = QSize(0, 0));
    //设置按钮右边的图标
    void setRightIcon(const QString &Ricon, const QSize &size = QSize(0, 0));
    /**
     * @brief setHoverEnabled 是否启动鼠标悬浮改变按钮颜色
     * @param Enabled treu启动，false禁止(默认是false)
     */
    void setHoverEnabled(bool Enabled);

    /**
     * @brief setHoverColor 设置鼠标悬浮时的按钮背景颜色和字体颜色
     * @param hoverBgColor  悬浮按钮背景颜色
     * @param hoverFontColor 悬浮按钮字体颜色
     */
    void setHoverColor(const QString &hoverBgColor, const QString & hoverFontColor);

    /**
     * @brief setButtonBorderWideAndColor 设置按钮的边框线的宽度值和边框颜色
     * @param borderWide
     * @param borderColor
     */
    void setButtonBorderWideAndColor(const QString &borderWide, const QString &borderColor);
private:
    //初始化默认样式
    void setButtonStyleSheet();
    //初始化ui布局，左icon，中文本，右icon
    void initUILayout();

    //设置按钮最大值和最小值
    void setButtonMaxAndMinValue(QWidget * widget, QSize size);

protected:

    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
private:
    void pressClickStyleSheet();
    void releaseClickStyleSheet();
signals:
    //该信号可以监听单次点击效果
    void sigClick();
    //该信号可以监听点击按钮的次数，isSecondClick ---false为第一次点击，true为第二次点击，只能交替监听2次点击
    void sigClick(bool isSecondClick);
    //背景颜色改变信号
    void backgroundColorChanged(QString backgroundColor);

public slots:

private slots:


private:
    bool m_isClickSecond = false; //是否启动二次点击，启动后每点击一下触发一次信号
    bool m_isClickEffect = false;  //是否启动点击效果

    QLabel * m_buttonText = nullptr; //按钮文本
    QLabel * m_buttonLeftIcon = nullptr; //左边按钮图片
    QLabel * m_buttonRightIcon = nullptr; //右边按钮图片

    QString m_backGroundImage; //按钮的icon图标
    QString m_backgroundColor; //按钮正常背景颜色
    QString m_fontColor = "#656565";  //按钮正常字体颜色
    QString m_hoverBgColor;  //悬浮背景颜色
    QString m_hoverFontColor;  //悬浮字体颜色
    QString m_borderWide = "1px"; //边框线宽度
    QString m_borderColor = "#DEDEDE"; //边框线颜色
    QString m_leftIconSource = "" ; //左边图标的链接
    QString m_rightIconSource = "" ; //右边图标的链接

    bool m_hoverEnabled  = false; //是否使能鼠标悬浮，默认时false

    //按钮布局三神器，提供动态布局伸缩
    QHBoxLayout * m_horizontalLayout = nullptr;
    QSpacerItem * m_HspacerItemStart = nullptr;
    QSpacerItem * m_HspacerItemEnd = nullptr;
};

#endif // PUSHBUTTON_H
