#include "inc/chartEstimate/SWcharts.h"
#include "ui_SWcharts.h"
#include "inc/chartEstimate/qcustomplot.h"
#include <QPen>

SWcharts::SWcharts(dataCharts& dc, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SWcharts),
    m_dc(dc)
{
    ui->setupUi(this);

    ui->widget->plotLayout()->clear(); // clear default axis rect so we can start from scratch
    QCPAxisRect *wideAxisRect = new QCPAxisRect(ui->widget);
    wideAxisRect->setupFullAxesBox(true);
    wideAxisRect->axis(QCPAxis::atRight, 0)->setTickLabels(true);
    wideAxisRect->addAxis(QCPAxis::atLeft)->setTickLabelColor(QColor("#6050F8")); // add an extra axis on the left and color its numbers
    QCPLayoutGrid *subLayout = new QCPLayoutGrid;
    ui->widget->plotLayout()->addElement(0, 0, wideAxisRect); // insert axis rect in first row
    ui->widget->plotLayout()->addElement(1, 0, subLayout); // sub layout in second row (grid layout will grow accordingly)
    //customPlot->plotLayout()->setRowStretchFactor(1, 2);
    // prepare axis rects that will be placed in the sublayout:
    QCPAxisRect *subRectLeft = new QCPAxisRect(ui->widget, false); // false means to not setup default axes
    QCPAxisRect *subRectRight = new QCPAxisRect(ui->widget, false);
    subLayout->addElement(0, 0, subRectLeft);
    subLayout->addElement(0, 1, subRectRight);
    subRectRight->setMaximumSize(150, 150); // make bottom right axis rect size fixed 150x150
    subRectRight->setMinimumSize(150, 150); // make bottom right axis rect size fixed 150x150
    // setup axes in sub layout axis rects:
    subRectLeft->addAxes(QCPAxis::atBottom | QCPAxis::atLeft);
    subRectRight->addAxes(QCPAxis::atBottom | QCPAxis::atRight);
    subRectLeft->axis(QCPAxis::atLeft)->ticker()->setTickCount(2);
    subRectRight->axis(QCPAxis::atRight)->ticker()->setTickCount(2);
    subRectRight->axis(QCPAxis::atBottom)->ticker()->setTickCount(2);
    subRectLeft->axis(QCPAxis::atBottom)->grid()->setVisible(true);
    // synchronize the left and right margins of the top and bottom axis rects:
    QCPMarginGroup *marginGroup = new QCPMarginGroup(ui->widget);
    subRectLeft->setMarginGroup(QCP::msLeft, marginGroup);
    subRectRight->setMarginGroup(QCP::msRight, marginGroup);
    wideAxisRect->setMarginGroup(QCP::msLeft | QCP::msRight, marginGroup);
    // move newly created axes on "axes" layer and grids on "grid" layer:
    foreach (QCPAxisRect *rect, ui->widget->axisRects())
    {
      foreach (QCPAxis *axis, rect->axes())
      {
        axis->setLayer("axes");
        axis->grid()->setLayer("grid");
      }
    }

    // prepare data:
    QVector<QCPGraphData> dataCos(21), dataGauss(50), dataRandom(100);
    QVector<double> x3, y3;
    qsrand(3);
    for (int i=0; i<dataCos.size(); ++i)
    {
      dataCos[i].key = i/(double)(dataCos.size()-1)*10-5.0;
      dataCos[i].value = qCos(dataCos[i].key);
    }
    for (int i=0; i<dataGauss.size(); ++i)
    {
      dataGauss[i].key = i/(double)dataGauss.size()*10-5.0;
      dataGauss[i].value = qExp(-dataGauss[i].key*dataGauss[i].key*0.2)*1000;
    }
    for (int i=0; i<dataRandom.size(); ++i)
    {
      dataRandom[i].key = i/(double)dataRandom.size()*10;
      dataRandom[i].value = qrand()/(double)RAND_MAX-0.5+dataRandom[qMax(0, i-1)].value;
    }
    x3 << 1 << 2 << 3 << 4;
    y3 << 2 << 2.5 << 4 << 1.5;

    // create and configure plottables:
    QCPGraph *mainGraphCos = ui->widget->addGraph(wideAxisRect->axis(QCPAxis::atBottom), wideAxisRect->axis(QCPAxis::atLeft));
    mainGraphCos->data()->set(dataCos);
    mainGraphCos->valueAxis()->setRange(-1, 1);
    mainGraphCos->rescaleKeyAxis();
    mainGraphCos->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, QPen(Qt::black), QBrush(Qt::white), 6));
    mainGraphCos->setPen(QPen(QColor(120, 120, 120), 2));
    QCPGraph *mainGraphGauss = ui->widget->addGraph(wideAxisRect->axis(QCPAxis::atBottom), wideAxisRect->axis(QCPAxis::atLeft, 1));
    mainGraphGauss->data()->set(dataGauss);
    mainGraphGauss->setPen(QPen(QColor("#8070B8"), 2));
    mainGraphGauss->setBrush(QColor(110, 170, 110, 30));
    mainGraphCos->setChannelFillGraph(mainGraphGauss);
    mainGraphCos->setBrush(QColor(255, 161, 0, 50));
    mainGraphGauss->valueAxis()->setRange(0, 1000);
    mainGraphGauss->rescaleKeyAxis();

    QCPGraph *subGraphRandom = ui->widget->addGraph(subRectLeft->axis(QCPAxis::atBottom), subRectLeft->axis(QCPAxis::atLeft));
    subGraphRandom->data()->set(dataRandom);
    subGraphRandom->setLineStyle(QCPGraph::lsImpulse);
    subGraphRandom->setPen(QPen(QColor("#FFA100"), 1.5));
    subGraphRandom->rescaleAxes();

    QCPBars *subBars = new QCPBars(subRectRight->axis(QCPAxis::atBottom), subRectRight->axis(QCPAxis::atRight));
    subBars->setWidth(3/(double)x3.size());
    subBars->setData(x3, y3);
    subBars->setPen(QPen(Qt::black));
    subBars->setAntialiased(false);
    subBars->setAntialiasedFill(false);
    subBars->setBrush(QColor("#705BE8"));
    subBars->keyAxis()->setSubTicks(false);
    subBars->rescaleAxes();
    // setup a ticker for subBars key axis that only gives integer ticks:
    QSharedPointer<QCPAxisTickerFixed> intTicker(new QCPAxisTickerFixed);
    intTicker->setTickStep(1.0);
    intTicker->setScaleStrategy(QCPAxisTickerFixed::ssMultiples);
    subBars->keyAxis()->setTicker(intTicker);

//    ui->widget->legend->setVisible(true);
//        ui->widget->legend->setFont(QFont("Helvetica", 9));
//        ui->widget->legend->setRowSpacing(-3);
//        QVector<QCPScatterStyle::ScatterShape> shapes;
//        shapes << QCPScatterStyle::ssCross;
//        shapes << QCPScatterStyle::ssPlus;
//        shapes << QCPScatterStyle::ssCircle;
//        shapes << QCPScatterStyle::ssDisc;
//        shapes << QCPScatterStyle::ssSquare;
//        shapes << QCPScatterStyle::ssDiamond;
//        shapes << QCPScatterStyle::ssDot;       ///< \enumimage{ssDot.png} a single pixel (use \ref ssDisc or \ref ssCircle if you want a round shape with a certain radius)
//        shapes << QCPScatterStyle::ssCrossSquare;      ///< \enumimage{ssCrossSquare.png} a square with a cross inside
//        shapes << QCPScatterStyle::ssPlusSquare;       ///< \enumimage{ssPlusSquare.png} a square with a plus inside
//        shapes << QCPScatterStyle::ssCrossCircle;      ///< \enumimage{ssCrossCircle.png} a circle with a cross inside
//        shapes << QCPScatterStyle::ssPlusCircle;       ///< \enumimage{ssPlusCircle.png} a circle with a plus inside
//        shapes << QCPScatterStyle::ssPeace;     ///< \enumimage{ssPeace.png} a circle, with one vertical and two downward diagonal lines
//        shapes << QCPScatterStyle::ssCustom;
//        shapes << QCPScatterStyle::ssNone;
//        shapes << QCPScatterStyle::ssDisc;
//        shapes << QCPScatterStyle::ssSquare;
//        shapes << QCPScatterStyle::ssDiamond;
//        QVector<QColor> colors_list;
//        colors_list << Qt::red
//                    << Qt::black
//                    << Qt::blue
//                    << Qt::magenta
//                    << Qt::gray
//                    << Qt::yellow
//                    << Qt::green
//                    << Qt::cyan
//                    << Qt::darkBlue
//                    << Qt::darkRed
//                    << Qt::darkMagenta
//                    << Qt::darkGray
//                    << Qt::darkYellow
//                    << Qt::darkGreen
//                    << Qt::darkCyan
//                    << QColor(245, 35, 75)
//                    << QColor(45, 305, 5)
//                    << QColor(25, 350, 175);
//        QFont legendFont;// = font();
//            legendFont.setPointSize(12);
//    //        legendFont.setBold(true);
//        QPen pen2;
//        for(int w = 0; w < mart.count(); w++)
//        {
//            ui->widget->addGraph();
//            pen2.setColor(colors_list[w]);
//          ui->widget->graph()->setData(vec, mart[w]);
//          ui->widget->graph()->rescaleAxes(true);
//          ui->widget->graph()->setPen(pen2);
//          ui->widget->graph()->setName( str[0] + QString::number(vec_schrft[w]) + str[1]);
//          ui->widget->graph()->setLineStyle(QCPGraph::lsLine);
//          // set scatter style:
//          if (shapes.at(w) != QCPScatterStyle::ssCustom)
//          {
//            ui->widget->graph()->setScatterStyle(QCPScatterStyle(shapes.at(w), 10));
//          }
//          else
//          {
//            QPainterPath customScatterPath;
//            for (int i=0; i<3; ++i)
//              customScatterPath.cubicTo(qCos(2*M_PI*i/3.0)*9, qSin(2*M_PI*i/3.0)*9, qCos(2*M_PI*(i+0.9)/3.0)*9, qSin(2*M_PI*(i+0.9)/3.0)*9, 0, 0);
//            ui->widget->graph()->setScatterStyle(QCPScatterStyle(customScatterPath, QPen(Qt::black, 0), QColor(40, 70, 255, 50), 10));
//          }
//        }
//    //    utut->legend->setFont(legendFont);
//        // give the axes some labels:
//        ui->widget->xAxis->setLabelFont(legendFont);
//        ui->widget->yAxis->setLabelFont(legendFont);
//        ui->widget->xAxis->setLabel(str[2]);
//        ui->widget->yAxis->setLabel(str[3]);
//        // set axes ranges, so we see all data:
//        ui->widget->xAxis->setRange(razmer[0]/*52*/, razmer[1]/*240*/);
//        ui->widget->yAxis->setRange(razmer[2]/*-1*/, razmer[3]/*50*/);
//        ui->widget->replot();



//    ui->widget->legend->setVisible(true);
//    ui->widget->legend->setFont(QFont("Helvetica",9));
//    // set locale to english, so we get english decimal separator:
//    ui->widget->setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom));
//    // add confidence band graphs:
//    ui->widget->addGraph();
//    QPen pen;
//    pen.setStyle(Qt::DotLine);
//    pen.setWidth(1);
//    pen.setColor(QColor(180,180,180));
//    ui->widget->graph(0)->setName("Confidence Band 68%");
//    ui->widget->graph(0)->setPen(pen);
//    ui->widget->graph(0)->setBrush(QBrush(QColor(255,50,30,20)));
//    ui->widget->addGraph();
//    ui->widget->legend->removeItem(ui->widget->legend->itemCount()-1); // don't show two confidence band graphs in legend
//    ui->widget->graph(1)->setPen(pen);
//    ui->widget->graph(0)->setChannelFillGraph(ui->widget->graph(1));
//    // add theory curve graph:
//    ui->widget->addGraph();
//    pen.setStyle(Qt::DashLine);
//    pen.setWidth(2);
//    pen.setColor(Qt::red);
//    ui->widget->graph(2)->setPen(pen);
//    ui->widget->graph(2)->setName("Theory Curve");
//    // add data point graph:
//    ui->widget->addGraph();
//    ui->widget->graph(3)->setPen(QPen(Qt::blue));
//    ui->widget->graph(3)->setLineStyle(QCPGraph::lsNone);
//    ui->widget->graph(3)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCross, 4));
//    // add error bars:
//    QCPErrorBars *errorBars = new QCPErrorBars(ui->widget->xAxis, ui->widget->yAxis);
//    errorBars->removeFromLegend();
//    errorBars->setAntialiased(false);
//    errorBars->setDataPlottable(ui->widget->graph(3));
//    errorBars->setPen(QPen(QColor(180,180,180)));
//    ui->widget->graph(3)->setName("Measurement");

//    // generate ideal sinc curve data and some randomly perturbed data for scatter plot:
//    QVector<double> x0(250), y0(250);
//    QVector<double> yConfUpper(250), yConfLower(250);
//    for (int i=0; i<250; ++i)
//    {
//      x0[i] = (i/249.0-0.5)*30+0.01; // by adding a small offset we make sure not do divide by zero in next code line
//      y0[i] = qSin(x0[i])/x0[i]; // sinc function
//      yConfUpper[i] = y0[i]+0.15;
//      yConfLower[i] = y0[i]-0.15;
//      x0[i] *= 1000;
//    }
//    QVector<double> x1(50), y1(50), y1err(50);
//    for (int i=0; i<50; ++i)
//    {
//      // generate a gaussian distributed random number:
//      double tmp1 = rand()/(double)RAND_MAX;
//      double tmp2 = rand()/(double)RAND_MAX;
//      double r = qSqrt(-2*qLn(tmp1))*qCos(2*M_PI*tmp2); // box-muller transform for gaussian distribution
//      // set y1 to value of y0 plus a random gaussian pertubation:
//      x1[i] = (i/50.0-0.5)*30+0.25;
//      y1[i] = qSin(x1[i])/x1[i]+r*0.15;
//      x1[i] *= 1000;
//      y1err[i] = 0.15;
//    }
//    // pass data to graphs and let Qui->customPlot determine the axes ranges so the whole thing is visible:
//    ui->widget->graph(0)->setData(x0, yConfUpper);
//    ui->widget->graph(1)->setData(x0, yConfLower);
//    ui->widget->graph(2)->setData(x0, y0);
//    ui->widget->graph(3)->setData(x1, y1);
//    errorBars->setData(y1err);
//    ui->widget->graph(2)->rescaleAxes();
//    ui->widget->graph(3)->rescaleAxes(true);
//    // setup look of bottom tick labels:
//    ui->widget->xAxis->setTickLabelRotation(30);
//    ui->widget->xAxis->ticker()->setTickCount(9);
//    ui->widget->xAxis->setNumberFormat("ebc");
//    ui->widget->xAxis->setNumberPrecision(1);
//    ui->widget->xAxis->moveRange(-10);
//    // make top right axes clones of bottom left axes. Looks prettier:
//    ui->widget->axisRect()->setupFullAxesBox();
}

SWcharts::~SWcharts()
{
    delete ui;
}
