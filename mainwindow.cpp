#define vtkRenderingCore_AUTOINIT 4(vtkInteractionStyle,vtkRenderingFreeType,vtkRenderingFreeTypeOpenGL,vtkRenderingOpenGL)
#define vtkRenderingVolume_AUTOINIT 1(vtkRenderingVolumeOpenGL)


#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <vtkSmartPointer.h>
#include <vtkObjectFactory.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkActor.h>
#include <vtkImageViewer2.h>
#include <vtkImageViewer.h>
#include <vtkDICOMImageReader.h>
#include <vtkInteractorStyleImage.h>
#include <vtkActor2D.h>
#include <vtkTextProperty.h>
#include <vtkTextMapper.h>
#include <QFileDialog>

#include <vtkImageReader2Factory.h>
#include <vtkImageReader2.h>
#include <vtkImageData.h>
#include <vtkImageActor.h>
#include <vtkImageReslice.h>
#include <vtkTransform.h>

#include <vtkImageCast.h>
#include <vtkNIFTIImageWriter.h>
#include <vtkImageMandelbrotSource.h>
#include <vtkImageMapper3D.h>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
        
    ui->setupUi(this);

    QPixmap pixmap("rotar.png");
    ui->btnRotateFile->setIcon(QIcon(pixmap));    
    ui->btnRotateFile->setIconSize(QSize(41,21));

    QPixmap pixmap3("rotar.png");
    ui->btnRotateDCM->setIcon(QIcon(pixmap3));    
    ui->btnRotateDCM->setIconSize(QSize(41,21));


    QPixmap pixmap2("mover.png");
    ui->btnMoveFile->setIcon(QIcon(pixmap2));    
    ui->btnMoveFile->setIconSize(QSize(41,21));


    QString num_slice = QString::number(0);
    ui->num_slices_edit->setText(num_slice);

    readerDCMSeries = vtkSmartPointer<vtkDICOMImageReader>::New();
    //readerSingleImage = vtkImageReader2
    readerDCMSeries_rotate = vtkSmartPointer<vtkDICOMImageReader>::New();
    
    imageViewerDCMSeriesX = vtkSmartPointer<vtkImageViewer>::New();
    imageViewer_rotate = vtkSmartPointer<vtkImageViewer>::New();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::openDCMFolder()
{
    QString folderNameDCM = QFileDialog::getExistingDirectory(this,tr("Open DCM Folder"),QDir::currentPath(),QFileDialog::ShowDirsOnly);
    std::string stdstrFolderNameDCM = folderNameDCM.toUtf8().constData();
    drawDCMSeries(stdstrFolderNameDCM);
}

void MainWindow::drawFile()
{
    
    vtkSmartPointer<vtkImageReader2Factory> readerFactory = vtkSmartPointer<vtkImageReader2Factory>::New();
    readerSingleImage = readerFactory->CreateImageReader2("vertebra.png");
    readerSingleImage->SetFileName("vertebra.png");
    readerSingleImage->Update();

    imageViewerDCMSeriesX->SetInputConnection(readerSingleImage->GetOutputPort());    
    

    mMinSliderX = imageViewerDCMSeriesX->GetWholeZMin();                //mMinSliderX = imageViewerDCMSeriesX->GetSliceMin();
    mMaxSliderX = imageViewerDCMSeriesX->GetWholeZMax();                //mMaxSliderX = imageViewerDCMSeriesX->GetSliceMax();
    cout<<"min: "<<mMinSliderX<<" max: "<<mMaxSliderX<<endl;

    ui->hSliderDCM->setMinimum(mMinSliderX);
    ui->hSliderDCM->setMaximum(mMaxSliderX);


    ui->vtkRenderer->SetRenderWindow(imageViewerDCMSeriesX->GetRenderWindow());             //imageViewerDCMSeriesX->SetRenderWindow(ui->vtkRenderer->GetRenderWindow());
    imageViewerDCMSeriesX->SetupInteractor(ui->vtkRenderer->GetInteractor());
    imageViewerDCMSeriesX->Render();


    //Adicionando
    //falta setinputconnection
    //imageViewer_rotate->SetInputConnection(readerDCMSeries->GetOutputPort());
    ui->rotateRenderer->SetRenderWindow(imageViewer_rotate->GetRenderWindow());
    imageViewer_rotate->SetupInteractor(ui->rotateRenderer->GetInteractor());
    imageViewer_rotate->Render();

}


void MainWindow::drawDCMSeries(std::string folderDCM)
{
    
    /*vtkSmartPointer<vtkImageReader2Factory> readerFactory = vtkSmartPointer<vtkImageReader2Factory>::New();
    readerDCMSeries = readerFactory->CreateImageReader2("vertebra.png");
    readerDCMSeries->SetFileName("vertebra.png");*/


    readerDCMSeries->SetDirectoryName(folderDCM.c_str());    
    readerDCMSeries->SetDataScalarTypeToUnsignedShort(); 
    readerDCMSeries->UpdateInformation();
    readerDCMSeries->UpdateWholeExtent();
    readerDCMSeries->Update();
    
    
    imageViewerDCMSeriesX->SetInputConnection(readerDCMSeries->GetOutputPort());    
    

    mMinSliderX = imageViewerDCMSeriesX->GetWholeZMin();                //mMinSliderX = imageViewerDCMSeriesX->GetSliceMin();
    mMaxSliderX = imageViewerDCMSeriesX->GetWholeZMax();                //mMaxSliderX = imageViewerDCMSeriesX->GetSliceMax();
    cout<<"min: "<<mMinSliderX<<" max: "<<mMaxSliderX<<endl;

    ui->hSliderDCM->setMinimum(mMinSliderX);
    ui->hSliderDCM->setMaximum(mMaxSliderX);


    ui->vtkRenderer->SetRenderWindow(imageViewerDCMSeriesX->GetRenderWindow());             //imageViewerDCMSeriesX->SetRenderWindow(ui->vtkRenderer->GetRenderWindow());
    imageViewerDCMSeriesX->SetupInteractor(ui->vtkRenderer->GetInteractor());
    imageViewerDCMSeriesX->Render();


    //Adicionando
    //falta setinputconnection
    //imageViewer_rotate->SetInputConnection(readerDCMSeries->GetOutputPort());
    ui->rotateRenderer->SetRenderWindow(imageViewer_rotate->GetRenderWindow());
    imageViewer_rotate->SetupInteractor(ui->rotateRenderer->GetInteractor());
    imageViewer_rotate->Render();


}

void MainWindow::on_btnOpenDCMFolder_clicked()
{
    openDCMFolder();
}


void MainWindow::on_btnOpenImage_clicked()
{
    //openFile();
    drawFile();

}

void MainWindow::on_hSliderDCM_sliderMoved(int position)
{
    cout<<"position "<<position<<endl;
    imageViewerDCMSeriesX->SetZSlice(position);
    imageViewerDCMSeriesX->Render();
    QString num_slice = QString::number(position);
    ui->num_slices_edit->setText(num_slice);

    QString num_max = QString::number(mMaxSliderX);
    cout<<"num_max: "<<mMaxSliderX<<endl;
    ui->num_total_slices->setText("/ ");
    ui->num_total_slices->setText("/ " +num_max);

}


void MainWindow::on_btnRotateFile_clicked()
{
    cout<<"clicked pos: "<<pos<<endl;
    //imageViewerDCMSeriesX->SetZSlice(pos++);

   imageViewer_rotate->SetInputConnection(readerSingleImage->GetOutputPort());
    double bounds[6];    
    readerSingleImage->GetOutput()->GetBounds(bounds);    

    cout<<"bounds"<<endl;
    cout<<bounds[0]<<" "<<bounds[1]<<" "<<bounds[2]<<" "<<bounds[3]<<" "<<bounds[4]<<" "<<bounds[5]<<endl;
   

    vtkSmartPointer<vtkTransform> transform = vtkSmartPointer<vtkTransform>::New();

    double center[3];
    center[0] = (bounds[1] + bounds[0]) / 2.0;
    center[1] = (bounds[3] + bounds[2]) / 2.0;
    center[2] = (bounds[5] + bounds[4]) / 2.0;

//    int angle=ui->num_slices_edit->
    int angle = 45;
    QString angle_txt = ui->num_grados_edit->toPlainText();
    if(angle_txt==" ") angle=0;
    else angle=angle_txt.toInt();

    cout<<"angulo obtenido "<<angle<<endl;

    transform->Translate(center[0], center[1], center[2]);
    transform->RotateWXYZ(angle, 0, 0, 1);
    transform->Translate(-center[0], -center[1], -center[2]);

    
    vtkSmartPointer<vtkImageReslice> reslice = vtkSmartPointer<vtkImageReslice>::New();
    reslice->SetInputConnection(readerSingleImage->GetOutputPort());
    reslice->SetResliceTransform(transform);
    reslice->SetInterpolationModeToCubic();
    reslice->SetOutputSpacing(
        readerSingleImage->GetOutput()->GetSpacing()[0], 
        readerSingleImage->GetOutput()->GetSpacing()[1], 
        readerSingleImage->GetOutput()->GetSpacing()[2]);

    reslice->SetOutputOrigin(
        readerSingleImage->GetOutput()->GetOrigin()[0],
        readerSingleImage->GetOutput()->GetOrigin()[1], 
        readerSingleImage->GetOutput()->GetOrigin()[2]);

    reslice->SetOutputExtent(readerSingleImage->GetOutput()->GetExtent());
    reslice->Update();

 

    // Visualize    
    imageViewer_rotate->SetInputConnection(reslice->GetOutputPort());
    //ui->rotateRenderer->SetRenderWindow(imageViewer_rotate->GetRenderWindow());
    //imageViewer_rotate->SetupInteractor(ui->rotateRenderer->GetInteractor());
    imageViewer_rotate->Render();

}




void MainWindow::on_btnMoveFile_clicked()
{
    cout<<"clicked pos: "<<pos<<endl;
    //imageViewerDCMSeriesX->SetZSlice(pos++);
    imageViewer_rotate->SetInputConnection(readerSingleImage->GetOutputPort());
    double bounds[6];    
    readerSingleImage->GetOutput()->GetBounds(bounds);    
    cout<<"bounds"<<endl;
    cout<<bounds[0]<<" "<<bounds[1]<<" "<<bounds[2]<<" "<<bounds[3]<<" "<<bounds[4]<<" "<<bounds[5]<<endl;
   

    vtkSmartPointer<vtkTransform> transform = vtkSmartPointer<vtkTransform>::New();
    double center[3] ;
    //center[0] = (bounds[1] + bounds[0]) / 2.0;
    //center[1] = (bounds[3] + bounds[2]) / 2.0;
    //center[2] = (bounds[5] + bounds[4]) / 2.0;
    QString move_x = ui->move_x->toPlainText();
    center[0]=move_x.toInt();

    QString move_y = ui->move_y->toPlainText();
    center[1]=move_y.toInt();

    QString move_z = ui->move_z->toPlainText();
    center[2]=move_z.toInt();

    
    transform->Translate(center[0], center[1], center[2]);
    
    vtkSmartPointer<vtkImageReslice> reslice = vtkSmartPointer<vtkImageReslice>::New();
    reslice->SetInputConnection(readerSingleImage->GetOutputPort());
    reslice->SetResliceTransform(transform);
    reslice->SetInterpolationModeToCubic();
    reslice->SetOutputSpacing(
        readerSingleImage->GetOutput()->GetSpacing()[0], 
        readerSingleImage->GetOutput()->GetSpacing()[1], 
        readerSingleImage->GetOutput()->GetSpacing()[2]);

    reslice->SetOutputOrigin(
        readerSingleImage->GetOutput()->GetOrigin()[0],
        readerSingleImage->GetOutput()->GetOrigin()[1], 
        readerSingleImage->GetOutput()->GetOrigin()[2]);

    reslice->SetOutputExtent(readerSingleImage->GetOutput()->GetExtent());
    reslice->Update();

 
    // Visualize    
    imageViewer_rotate->SetInputConnection(reslice->GetOutputPort());
    imageViewer_rotate->Render();

}




void MainWindow::on_btnRotateDCM_clicked()
{
    cout<<"clicked pos: "<<pos<<endl;
    //imageViewerDCMSeriesX->SetZSlice(pos++);


    //------------------------------------------------------------------------------
    //------------------------------------------------------------------------------
    //------------------------------------------------------------------------------
    imageViewer_rotate->SetInputConnection(readerDCMSeries->GetOutputPort());

    double bounds[6];    
    readerDCMSeries->GetOutput()->GetBounds(bounds);    

    cout<<"bounds"<<endl;
    cout<<bounds[0]<<" "<<bounds[1]<<" "<<bounds[2]<<" "<<bounds[3]<<" "<<bounds[4]<<" "<<bounds[5]<<endl;

    /*bounds[0] = 0;  bounds[1]=205.598;
    bounds[2] = 0;  bounds[3]=205.598;
    bounds[4] = 0;  bounds[5] = 0;*/
  

    vtkSmartPointer<vtkTransform> transform = vtkSmartPointer<vtkTransform>::New();

    double center[3];
    center[0] = (bounds[1] + bounds[0]) / 2.0;
    center[1] = (bounds[3] + bounds[2]) / 2.0;
    center[2] = (bounds[5] + bounds[4]) / 2.0;

    transform->Translate(center[0], center[1], center[2]);
    transform->RotateWXYZ(0, 0, 0, 1);
    //transform->RotateWZ(45);
    transform->Translate(-center[0], -center[1], -center[2]);

    
    vtkSmartPointer<vtkImageReslice> reslice = vtkSmartPointer<vtkImageReslice>::New();
    reslice->SetInputConnection(readerDCMSeries->GetOutputPort());
    reslice->SetResliceTransform(transform);
    reslice->SetInterpolationModeToCubic();
    reslice->SetOutputSpacing(
        readerDCMSeries->GetOutput()->GetSpacing()[0], 
        readerDCMSeries->GetOutput()->GetSpacing()[1], 
        readerDCMSeries->GetOutput()->GetSpacing()[2]);

    reslice->SetOutputOrigin(
        readerDCMSeries->GetOutput()->GetOrigin()[0],
        readerDCMSeries->GetOutput()->GetOrigin()[1], 
        readerDCMSeries->GetOutput()->GetOrigin()[2]);

   // reslice->SetOutputSpacing(0.402344, 0.402344, 1); reslice->SetOutputOrigin(0, 0, 0);


    reslice->SetOutputExtent(readerDCMSeries->GetOutput()->GetExtent());
    reslice->Update();

 

    // Visualize    
    imageViewer_rotate->SetInputConnection(reslice->GetOutputPort());
    //ui->rotateRenderer->SetRenderWindow(imageViewer_rotate->GetRenderWindow());
    //imageViewer_rotate->SetupInteractor(ui->rotateRenderer->GetInteractor());
    imageViewer_rotate->Render();

    double boundsss[6];
    reslice->GetOutput()->GetBounds(boundsss);
    cout<<"bounddssss "<<boundsss[0]<<" "<<boundsss[1]<<endl;

    //imageViewer_rotate->GetRenderer()->ResetCamera();
    //imageViewer_rotate->Render();
    //ui->rotateRenderer->Start();
      //ui->vtkRenderer2->Start();    

    
    

       /*imageViewerDCMSeriesX->SetInputConnection(reslice->GetOutputPort());

    vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
    imageViewerDCMSeriesX->SetupInteractor(renderWindowInteractor);
    imageViewerDCMSeriesX->Render();
    imageViewerDCMSeriesX->GetRenderer()->ResetCamera();
    imageViewerDCMSeriesX->Render();

    renderWindowInteractor->Start();
    */

    //imageViewerDCMSeriesX->Render();

}

void MainWindow::on_btnExportImage_clicked()
{
    //Command for writing
    cout<<"writing: "<<endl;
    vtkSmartPointer<vtkNIFTIImageWriter> writer = vtkSmartPointer<vtkNIFTIImageWriter>::New();

    vtkImageData * img=readerSingleImage->GetOutput();

    writer->SetInputConnection(readerSingleImage->GetOutputPort());
    writer->SetFileName("outp.png");
    writer->Write();


}