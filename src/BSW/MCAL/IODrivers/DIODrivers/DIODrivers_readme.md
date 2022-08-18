Functional Overview

Dependencies to other Modules
    Port Driver Module
    Many ports and port pins are assigned by the PORT Driver Module to various functionalities as for example:
        * General purpose I/O 
        * ADC
        * SPI
        * PWM

    SWS_Dio_00061. The Dio module shall not provide APIs for overall configuration and initialization of the port structure 
                   is used in the Dio module. These actions are done by the PORT Driver Module.
    
    SWS_Dio_00063. The Dio module shall adapt its configuration and usage to the microcontroller and ECU.

    SWS_Dio_00102. The Dio module’s user shall only use the Dio functions after the Port Driver has been initialized. 
                   Otherwise the Dio module will exhibit undefined behavior.

    SWS_Dio_00194. Dio.c shall include Det.h if detection of development error (DET) is enabled.

