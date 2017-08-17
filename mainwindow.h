#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vtkSmartPointer.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkDICOMImageReader.h>
#include <vtkImageViewer2.h>
#include <vtkImageViewer.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    int pos =1;
    
private slots:
    void openDCMFolder();

    void drawFile();

    void drawDCMSeries(std::string folderDCM);

    void on_btnOpenDCMFolder_clicked();

    void on_btnOpenImage_clicked();

    void on_hSliderDCM_sliderMoved(int position);


    void on_btnRotateFile_clicked();

    void on_btnRotateDCM_clicked();

    void on_btnExportImage_clicked();

    void on_btnMoveFile_clicked();

private:
    Ui::MainWindow *ui;
    vtkSmartPointer<vtkDICOMImageReader> readerDCMSeries;
    vtkSmartPointer<vtkDICOMImageReader> readerDCMSeries_rotate;
    vtkImageReader2 *readerSingleImage;

    vtkSmartPointer<vtkImageViewer> imageViewerDCMSeriesX;
    vtkSmartPointer<vtkImageViewer> imageViewer_rotate;

    int mMinSliderX;
    int mMaxSliderX;

};

#endif // MAINWINDOW_H


