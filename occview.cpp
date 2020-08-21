// QMouseEvent and QRubberBand should above OpenGl_GraphicDriver.hxx
#include <QMouseEvent>
#include <QRubberBand>

//OpenGl_GraphicDriver.hxx should above occview.h
#include <OpenGl_GraphicDriver.hxx>
#include "occview.h"

#include <Aspect_DisplayConnection.hxx>
#include <Xw_Window.hxx>

static Handle(Graphic3d_GraphicDriver)& GetGraphicDriver()
{
  static Handle(Graphic3d_GraphicDriver) aGraphicDriver;
  return aGraphicDriver;
}

OccView::OccView(QWidget *parent)
    : QGLWidget(parent)
{

    setBackgroundRole(QPalette::NoRole);
    setAttribute(Qt::WA_PaintOnScreen);
    setAttribute(Qt::WA_NoSystemBackground);

    // 1. Create a 3D viewer.
    Handle(Aspect_DisplayConnection) aDisplayConnection =
            new Aspect_DisplayConnection();
    if (GetGraphicDriver().IsNull())
    {
        GetGraphicDriver() = new OpenGl_GraphicDriver(aDisplayConnection);
    }
    // Get window handle. This returns something suitable for all platforms.
    WId window_handle = (WId) winId();
    // Create appropriate window for platform
    Handle(Xw_Window) wind = new Xw_Window(aDisplayConnection, (Window) window_handle);

    mViewer = new V3d_Viewer(GetGraphicDriver() );
    mViewer->SetDefaultLights();
    mViewer->SetLightOn();
    mViewer->ActivateGrid (Aspect_GT_Rectangular, Aspect_GDM_Lines);

    // 3. Create an interactive context.
    mContext = new AIS_InteractiveContext(mViewer);
    //mContext->SetDisplayMode(AIS_Shaded);
    if ( mView.IsNull() )
        mView = mContext->CurrentViewer()->CreateView();
    mView->SetWindow (wind);

    mView->MustBeResized();
    if ( !wind->IsMapped() )
    {
        wind->Map();
    }
    mView->TriedronDisplay(Aspect_TOTP_LEFT_LOWER, Quantity_NOC_GOLD, 0.08, V3d_ZBUFFER);
}

void OccView::paintEvent(QPaintEvent *)
{
    mView->Redraw();
}

void OccView::resizeEvent(QResizeEvent *)
{
    mView->MustBeResized();
}

QPaintEngine* OccView::paintEngine() const
{
    return 0;
}
