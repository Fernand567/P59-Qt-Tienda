#include "factura.h"
#include "ui_factura.h"
#include <QDebug>

Factura::Factura(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Factura)
{
    ui->setupUi(this);

}

Factura::~Factura()
{
    delete ui;
}

void Factura::datosFactura(QString cedula, QString nombre, QString telefono, QString email, QString direccion,QString detalles)
{
    this->c_cedula=cedula;
    this->c_nombre=nombre;
    this->c_telefono=telefono;
    this->c_email=email;
    this->c_direccion=direccion;
    this->c_detalles=detalles;

}

void Factura::ValoresFactura(float subtotal, float iva, float total)
{
    this->c_subtotal=subtotal;
    this->c_iva=iva;
    this->c_total=total;
}

void Factura::cargarDatos()
{
    ui->outNombre->setText(c_nombre);
    ui->outDireccion->setText(c_direccion);
    ui->outCedula->setText(c_cedula);
    ui->outEmail->setText(c_email);
    ui->outTelefono->setText(c_telefono);
    ui->outDetallesFactura->setPlainText(c_detalles);
    ui->outSubtotalF->setText("$" + QString::number(c_subtotal,'f',2));
    ui->outIvaF->setText("$" + QString::number(c_iva,'f',2));
    ui->outTotalF->setText("$" + QString::number(c_total,'f',2));
    fecha= QDate::currentDate().toString(Qt::ISODate);
    ui->outFecha->setText(fecha);
    fechahora=QDateTime::currentDateTime().toString("ddMMyyyy_hhmmss");
}

void Factura::on_btnImprimir_clicked()
{

    QFile archivo("D:/Segundo semestre Salesiana/Programacion orientada a objetos/Nueva carpeta/Tienda/Facturas/"+fechahora+".txt");

    if(archivo.open(QFile::WriteOnly | QFile::Truncate)){
    QTextStream salida(&archivo);
    salida.operator<<("\n\t\t\tAbarrotes Luky\n");
    salida.operator<<("Chillogallo,Santa Rosa 3,oe12-41\n");
    salida.operator<<("Ruc:1792652553001\n");
    salida.operator<<("Ret Factura: 001-403-30034647");
    salida.operator<<("\n-------------------------------------------------------------------\n");
    salida.operator<<("Datos del cliente\n\n");
    salida.operator<<("Cliente: "+c_nombre+"\t\t"+ "RUC/CI: "+c_cedula+"\n");
    salida.operator<<("Direccion: "+c_direccion+"\t\t"+ "Telefono: "+ c_telefono+"\n");
    salida.operator<<("Email: "+c_email+"\t\t"+ "Fecha: "+ fecha+"\n");
    salida.operator<<("\n-------------------------------------------------------------------\n");
    salida.operator<<("Forma de pago: Efectivo");
    salida.operator<<("\n-------------------------------------------------------------------\n");
    salida.operator<<("Cantidad\tProducto\tP.Unitario\tSubtotal\n");
    salida.operator<<(c_detalles);
    salida.operator<<("\n-------------------------------------------------------------------\n");
    salida.operator<<("Subtototal:\t\t"+("$" + QString::number(c_subtotal,'f',2))+"\n");
    salida.operator<<("Iva(12%):  \t\t"+("$" + QString::number(c_iva,'f',2))+"\n");
    salida.operator<<("TOTAL:     \t\t"+("$" + QString::number(c_total,'f',2))+"\n\n");
    salida.operator<<("\tGracias por confiar en nosotros :)");

    QMessageBox::information(this,"Guardar datos",
                             "Los datos han sido guardados exitosamente");
    }else{
        QMessageBox::warning(this,
                             "Guardar datos",
                             "No se pudo guardar el archivo");
    }


    archivo.close();

}


void Factura::on_btnCerrar_clicked()
{
    close();
}

