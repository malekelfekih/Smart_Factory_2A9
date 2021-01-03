#ifndef ARDUINO_H
#define ARDUINO_H

#include "client.h"
#include "gestion_clients_cf.h"
#include <QDialog>
#include <QSerialPort>

namespace Ui {
class arduino;
}

class arduino : public QDialog {
  Q_OBJECT

public:
  explicit arduino(QWidget *parent = nullptr);
  ~arduino();

private:
  Ui::arduino *ui;
  QSerialPort *arduinoo;
  static const quint16 arduino_uno_vendor_id = 9025;
  static const quint16 arduino_uno_product_id = 67;
  QByteArray serialData;
  QString serialBuffer;
  QString parsed_data;
  double temperature_value;

private slots:
  void readSerial();
  void updateTemperature(QString);
};

#endif // ARDUINO_H
