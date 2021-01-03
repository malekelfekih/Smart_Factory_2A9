#include "arduino.h"
#include "cf.h"
#include "client.h"
#include "connection.h"
#include "gestion_clients_cf.h"
#include "stat.h"
#include "ui_arduino.h"
#include <QSerialPort>
#include <QSerialPortInfo>

arduino::arduino(QWidget *parent) : QDialog(parent), ui(new Ui::arduino) {
  ui->setupUi(this);
}

arduino::~arduino() { delete ui; }
