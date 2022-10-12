#ifndef BASE_WIDGET_H
#define BASE_WIDGET_H

#include <QWidget>
#include <QMouseEvent>

class BaseWidget : public QWidget
{
  Q_OBJECT
public:
  explicit BaseWidget(QWidget *parent = 0);

  void setAreaMovable(const QRect rt);

protected:
  void mousePressEvent(QMouseEvent *);
  void mouseMoveEvent(QMouseEvent *);
  void mouseReleaseEvent(QMouseEvent *);

private:
  QRect m_areaMovable;
  bool m_bPressed;
  QPoint m_ptPress;
};

#endif // BASE_WIDGET_H
