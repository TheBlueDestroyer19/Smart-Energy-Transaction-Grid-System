#include <string.h>
#include "combined.h"

void hardcode(struct SmartGridTransaction record[]) {
    // Manually initializing all 25 transactions

    // Transaction 1
    record[0].transactionID = 1;
    record[0].buyerID = 101;
    record[0].sellerID = 201;
    record[0].amountOfEnergy = 100.5;
    record[0].priceKWh = 3.5;
    strcpy(record[0].date, "15:10:2024");
    strcpy(record[0].time, "14:30");

    // Transaction 2
    record[1].transactionID = 2;
    record[1].buyerID = 102;
    record[1].sellerID = 202;
    record[1].amountOfEnergy = 250.2;
    record[1].priceKWh = 4.0;
    strcpy(record[1].date, "15:10:2024");
    strcpy(record[1].time, "10:00");

    // Transaction 3
    record[2].transactionID = 3;
    record[2].buyerID = 101;
    record[2].sellerID = 203;
    record[2].amountOfEnergy = 180.0;
    record[2].priceKWh = 3.8;
    strcpy(record[2].date, "10:09:2024");
    strcpy(record[2].time, "11:45");

    // Transaction 4
    record[3].transactionID = 4;
    record[3].buyerID = 103;
    record[3].sellerID = 204;
    record[3].amountOfEnergy = 320.7;
    record[3].priceKWh = 3.2;
    strcpy(record[3].date, "12:09:2024");
    strcpy(record[3].time, "12:15");

    // Transaction 5
    record[4].transactionID = 5;
    record[4].buyerID = 104;
    record[4].sellerID = 201;
    record[4].amountOfEnergy = 220.0;
    record[4].priceKWh = 3.9;
    strcpy(record[4].date, "20:08:2024");
    strcpy(record[4].time, "09:30");

    // Transaction 6
    record[5].transactionID = 6;
    record[5].buyerID = 102;
    record[5].sellerID = 202;
    record[5].amountOfEnergy = 190.0;
    record[5].priceKWh = 4.5;
    strcpy(record[5].date, "16:10:2024");
    strcpy(record[5].time, "14:00");

    // Transaction 7
    record[6].transactionID = 7;
    record[6].buyerID = 105;
    record[6].sellerID = 203;
    record[6].amountOfEnergy = 500.0;
    record[6].priceKWh = 2.9;
    strcpy(record[6].date, "25:07:2024");
    strcpy(record[6].time, "13:30");

    // Transaction 8
    record[7].transactionID = 8;
    record[7].buyerID = 101;
    record[7].sellerID = 201;
    record[7].amountOfEnergy = 300.0;
    record[7].priceKWh = 3.7;
    strcpy(record[7].date, "01:09:2024");
    strcpy(record[7].time, "15:00");

    // Transaction 9
    record[8].transactionID = 9;
    record[8].buyerID = 106;
    record[8].sellerID = 204;
    record[8].amountOfEnergy = 275.6;
    record[8].priceKWh = 4.0;
    strcpy(record[8].date, "15:10:2024");
    strcpy(record[8].time, "16:45");

    // Transaction 10
    record[9].transactionID = 10;
    record[9].buyerID = 101;
    record[9].sellerID = 203;
    record[9].amountOfEnergy = 330.0;
    record[9].priceKWh = 3.6;
    strcpy(record[9].date, "29:07:2024");
    strcpy(record[9].time, "17:30");

    // Transaction 11
    record[10].transactionID = 11;
    record[10].buyerID = 107;
    record[10].sellerID = 205;
    record[10].amountOfEnergy = 110.5;
    record[10].priceKWh = 3.3;
    strcpy(record[10].date, "02:08:2024");
    strcpy(record[10].time, "11:00");

    // Transaction 12
    record[11].transactionID = 12;
    record[11].buyerID = 101;
    record[11].sellerID = 202;
    record[11].amountOfEnergy = 150.5;
    record[11].priceKWh = 3.4;
    strcpy(record[11].date, "20:09:2024");
    strcpy(record[11].time, "09:00");

    // Transaction 13
    record[12].transactionID = 13;
    record[12].buyerID = 108;
    record[12].sellerID = 201;
    record[12].amountOfEnergy = 130.2;
    record[12].priceKWh = 3.9;
    strcpy(record[12].date, "05:08:2024");
    strcpy(record[12].time, "18:00");

    // Transaction 14
    record[13].transactionID = 14;
    record[13].buyerID = 109;
    record[13].sellerID = 202;
    record[13].amountOfEnergy = 210.8;
    record[13].priceKWh = 3.8;
    strcpy(record[13].date, "25:09:2024");
    strcpy(record[13].time, "10:45");

    // Transaction 15
    record[14].transactionID = 15;
    record[14].buyerID = 105;
    record[14].sellerID = 204;
    record[14].amountOfEnergy = 280.0;
    record[14].priceKWh = 3.5;
    strcpy(record[14].date, "05:10:2024");
    strcpy(record[14].time, "19:30");

    // Transaction 16
    record[15].transactionID = 16;
    record[15].buyerID = 102;
    record[15].sellerID = 201;
    record[15].amountOfEnergy = 400.0;
    record[15].priceKWh = 4.2;
    strcpy(record[15].date, "30:07:2024");
    strcpy(record[15].time, "13:00");

    // Transaction 17
    record[16].transactionID = 17;
    record[16].buyerID = 110;
    record[16].sellerID = 203;
    record[16].amountOfEnergy = 370.9;
    record[16].priceKWh = 3.4;
    strcpy(record[16].date, "10:10:2024");
    strcpy(record[16].time, "15:15");

    // Transaction 18
    record[17].transactionID = 18;
    record[17].buyerID = 106;
    record[17].sellerID = 201;
    record[17].amountOfEnergy = 295.5;
    record[17].priceKWh = 4.1;
    strcpy(record[17].date, "13:10:2024");
    strcpy(record[17].time, "12:00");

    // Transaction 19
    record[18].transactionID = 19;
    record[18].buyerID = 109;
    record[18].sellerID = 202;
    record[18].amountOfEnergy = 305.3;
    record[18].priceKWh = 3.7;
    strcpy(record[18].date, "22:09:2024");
    strcpy(record[18].time, "14:45");

    // Transaction 20
    record[19].transactionID = 20;
    record[19].buyerID = 104;
    record[19].sellerID = 205;
    record[19].amountOfEnergy = 250.0;
    record[19].priceKWh = 3.9;
    strcpy(record[19].date, "18:09:2024");
    strcpy(record[19].time, "16:30");

    // Transaction 21
    record[20].transactionID = 21;
    record[20].buyerID = 108;
    record[20].sellerID = 203;
    record[20].amountOfEnergy = 415.0;
    record[20].priceKWh = 3.5;
    strcpy(record[20].date, "01:10:2024");
    strcpy(record[20].time, "09:00");

    // Transaction 22
    record[21].transactionID = 22;
    record[21].buyerID = 103;
    record[21].sellerID = 204;
    record[21].amountOfEnergy = 175.0;
    record[21].priceKWh = 3.6;
    strcpy(record[21].date, "10:09:2024");
    strcpy(record[21].time, "10:00");

    // Transaction 23
    record[22].transactionID = 23;
    record[22].buyerID = 110;
    record[22].sellerID = 205;
    record[22].amountOfEnergy = 510.0;
    record[22].priceKWh = 3.9;
    strcpy(record[22].date, "25:09:2024");
    strcpy(record[22].time, "12:30");

    // Transaction 24
    record[23].transactionID = 24;
    record[23].buyerID = 105;
    record[23].sellerID = 202;
    record[23].amountOfEnergy = 190.5;
    record[23].priceKWh = 4.0;
    strcpy(record[23].date, "05:10:2024");
    strcpy(record[23].time, "08:45");

    // Transaction 25
    record[24].transactionID = 25;
    record[24].buyerID = 106;
    record[24].sellerID = 203;
    record[24].amountOfEnergy = 270.0;
    record[24].priceKWh = 4.2;
    strcpy(record[24].date, "17:10:2024");
    strcpy(record[24].time, "17:00");
}
