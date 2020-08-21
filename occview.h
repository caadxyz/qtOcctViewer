#ifndef OCCVIEW_H
#define OCCVIEW_H

#include <QGLWidget>
#include <QPaintEvent>
#include <QResizeEvent>

//Opencascade includes
#include <AIS_InteractiveContext.hxx>
#include <V3d_View.hxx>
#include <V3d_Viewer.hxx>

class OccView : public QGLWidget
{

public:
    explicit OccView(QWidget *parent = 0);

protected:
    virtual QPaintEngine* paintEngine() const;

    virtual void paintEvent(QPaintEvent *);
    virtual void resizeEvent(QResizeEvent *);
private:

    //Occ viewer
    Handle(V3d_Viewer) mViewer;
    Handle(V3d_View) mView;

    //Occ context
    Handle(AIS_InteractiveContext) mContext;


};

#endif // OCCVIEW_H
