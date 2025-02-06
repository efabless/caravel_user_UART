// SPDX-FileCopyrightText: 2023 Efabless Corporation

// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at

//      http://www.apache.org/licenses/LICENSE-2.0

// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.


#include <firmware_apis.h>
#include <EF_UART.h>
#include <EF_UART.c>
#define UART_USER_BASE 0x30000000
#define UART_USER ((EF_UART_TYPE_PTR)UART_USER_BASE)

void main(){
    // Enable managment gpio as output to use as indicator for finishing configuration  
    ManagmentGpio_outputEnable();
    ManagmentGpio_write(0);
    enableHkSpi(0); // disable housekeeping spi
    GPIOs_configure(8, GPIO_MODE_USER_STD_OUTPUT);
    GPIOs_configure(7, GPIO_MODE_USER_STD_INPUT_PULLUP);
    
    GPIOs_loadConfigs(); // load the configuration 
    User_enableIF(); // this necessary when reading or writing between wishbone and user project if interface isn't enabled no ack would be recieve and the command will be stuck
    ManagmentGpio_write(1);
    EF_UART_enable(UART_USER);
    EF_UART_setTxFIFOThreshold(UART_USER, 3);
    EF_UART_enableTx(UART_USER);
    EF_UART_writeChar(UART_USER, 'H');
    EF_UART_writeChar(UART_USER, 'e');
    EF_UART_writeChar(UART_USER, 'l');
    EF_UART_writeChar(UART_USER, 'l');
    EF_UART_writeChar(UART_USER, 'o');
    EF_UART_writeChar(UART_USER, '\n');
}
    
    