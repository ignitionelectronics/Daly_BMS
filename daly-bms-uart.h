

#ifndef DALY_BMS_UART_H
#define DALY_BMS_UART_H

#define XFER_BUFFER_LENGTH 13

class Daly_BMS_UART
{
public:
    enum COMMAND
    {
        VOUT_IOUT_SOC = 0x90,
        MIN_MAX_CELL_VOLTAGE = 0x91
    };

    Daly_BMS_UART(HardwareSerial &serialIntf);
    bool Init();
    bool getPackMeasurements(uint16_t &voltage, int16_t &current, uint16_t &SOC);
    bool getPackTemp(int8_t &temp);

private:
    HardwareSerial *serialIntf;

    void sendCommand(COMMAND cmdID);
    /**
     * @brief
     * @details
     * @return True on success, false on failure
     */
    bool receiveBytes(void);
    /**
     * @brief Validates the checksum in the RX Buffer
     * @return true if checksum matches, false otherwise
     */
    bool validateChecksum();

    uint8_t my_txBuffer[XFER_BUFFER_LENGTH];
    uint8_t my_rxBuffer[XFER_BUFFER_LENGTH];
};

#endif // DALY_BMS_UART_H